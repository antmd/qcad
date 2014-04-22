/**
 * Copyright (c) 2011-2014 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

include("../PointMark.js");
include("scripts/sprintf.js");

/**
 * \class PointMarkDraw
 * \brief Point marker with label (block with block attribute).
 * \ingroup ecma_misc_pointmark
 */
function PointMarkDraw(guiAction) {
    EAction.call(this, guiAction);

    this.label = "";
    this.pos = new RVector(0,0);
    this.benchmarkPos = new RVector(0,0);
    this.benchmarkCounter = -1;
    this.pointCounter = -1;
    this.benchmarkHandle = RObject.INVALID_ID;
    this.autoAppendCounter = true;
    this.textHeight = 10;

    if (!isNull(guiAction)) {
        this.setUiOptions("PointMarkDraw.ui");
    }
}

PointMarkDraw.State = {
    SettingBenchmarkPosition : 0,
    SettingPointPosition : 1
};
PointMarkDraw.dataPath = "libraries/default/Tools/PointMark";

PointMarkDraw.prototype = new EAction();
PointMarkDraw.includeBasePath = includeBasePath;

PointMarkDraw.prototype.beginEvent = function() {
    // load bench mark:
    this.diBM = new RDocumentInterface(new RDocument(new RMemoryStorage(), new RSpatialIndexNavel()));
    this.diBM.importFile(PointMarkDraw.dataPath + "/benchmark.dxf");

    // load point symbol:
    this.diPoint = new RDocumentInterface(new RDocument(new RMemoryStorage(), new RSpatialIndexNavel()));
    this.diPoint.importFile(PointMarkDraw.dataPath + "/point.dxf");

    var doc = this.getDocument();
    if (isNull(doc)) {
        this.terminate();
        return;
    }

    var benchmarkIds = PointMark.queryAllMarkIds(doc, 'b');
    if (benchmarkIds.length===0) {
        // no benchmarks yet, start with adding a benchmark:
        this.setState(PointMarkDraw.State.SettingBenchmarkPosition);
        return;
    }
    else {
        var blockRef = doc.queryObjectDirect(benchmarkIds[benchmarkIds.length-1]);
        if (isNull(blockRef) || !isBlockReferenceEntity(blockRef)) {
            this.setState(PointMarkDraw.State.SettingBenchmarkPosition);
            return;
        }

        // got already a benchmark, start with adding points:
        this.benchmarkHandle = blockRef.getHandle();
        qDebug("PointMarkDraw.prototype.beginEvent: this.benchmarkHandle: ", this.benchmarkHandle);
        this.setState(PointMarkDraw.State.SettingPointPosition);
    }

    EAction.prototype.beginEvent.call(this);

//    var optionsToolBar = EAction.getOptionsToolBar();
//    if (isNull(optionsToolBar)) {
//        return;
//    }
//    optionsToolBar.findChild("Benchmark").setProperty("Loaded", true);
};

PointMarkDraw.prototype.initUiOptions = function(resume) {
    var appWin = RMainWindowQt.getMainWindow();
    var dock = appWin.findChild("PointMarkDock");
    if (isNull(dock)) {
        return;
    }
    dock.visible = true;

    var optionsToolBar = EAction.getOptionsToolBar();
    if (isNull(optionsToolBar)) {
        return;
    }
    var benchmarkCombo = optionsToolBar.findChild("Benchmark");
    if (isNull(benchmarkCombo)) {
        return;
    }
    benchmarkCombo.blockSignals(true);
    benchmarkCombo.clear();
    //benchmarkCombo.setProperty("Loaded", true);

    var doc = this.getDocument();
    var markIds = PointMark.queryAllMarkIds(doc);
    var i, id, blockRef, handle, label;

    // init benchmark counter and combo box:
    this.benchmarkCounter = 1;
    this.pointCounter = 1;
    for (i=0; i<markIds.length; i++) {
        id = markIds[i];
        blockRef = doc.queryEntityDirect(id);
        if (isNull(blockRef)) {
            continue;
        }

        // get benchmark handle as int:
        handle = PointMark.getBenchmarkHandle(blockRef);
        if (handle===RObject.INVALID_HANDLE) {
            continue;
        }

        // get label:
        label = PointMark.getMarkLabel(doc, blockRef.getId());
        var matches = label.match(/\d+$/);
        if (matches.length!==1) {
            continue;
        }

        // parse label number:
        var num = parseInt(matches[0], 10);

        // benchmark mode and block ref is a benchmark
        // (refers to itself as benchmark):
        //if (this.state===PointMarkDraw.State.SettingBenchmarkPosition) {
            if (handle===blockRef.getHandle()) {
                this.benchmarkCounter = Math.max(this.benchmarkCounter, num+1);

                if (benchmarkCombo.findData(handle)===-1) {
                    benchmarkCombo.addItem(label, handle);
                }
                continue;
            }
        //}

        // point mode and block ref is a point that refers to the selected
        // bench mark:
        //else {
            if (handle!==this.benchmarkHandle) {
                continue;
            }
            //if (handle!==blockRef.getHandle()) {
                this.pointCounter = Math.max(this.pointCounter, num+1);
            //}
        //}
    }

    benchmarkCombo.currentIndex = benchmarkCombo.findData(this.benchmarkHandle);
    qDebug("PointMarkDraw.prototype.initUiOptions: this.benchmarkHandle: ", this.benchmarkHandle);
    benchmarkCombo.blockSignals(false);
};

PointMarkDraw.prototype.setState = function(state) {
    EAction.prototype.setState.call(this, state);

    this.setCrosshairCursor();
    this.getDocumentInterface().setClickMode(RAction.PickCoordinate);

    var appWin = RMainWindowQt.getMainWindow();
    switch (this.state) {
    case PointMarkDraw.State.SettingBenchmarkPosition:
        this.pointCounter = 1;
        var trBM = qsTr("Benchmark (Origin)");
        this.setCommandPrompt(trBM);
        this.setLeftMouseTip(trBM);
        this.setRightMouseTip(EAction.trCancel);
        break;
    case PointMarkDraw.State.SettingPointPosition:
        var trPos = qsTr("Position");
        this.setCommandPrompt(trPos);
        this.setLeftMouseTip(trPos);
        this.setRightMouseTip(EAction.trBack);
        break;
    }

    EAction.showSnapTools();
};

PointMarkDraw.prototype.escapeEvent = function() {
    switch (this.state) {
    case PointMarkDraw.State.SettingBenchmarkPosition:
        EAction.prototype.escapeEvent.call(this);
        break;

    case PointMarkDraw.State.SettingPointPosition:
        EAction.prototype.escapeEvent.call(this);
        //this.setState(PointMarkDraw.State.SettingBenchmarkPosition);
        break;
    }
};

PointMarkDraw.prototype.pickCoordinate = function(event, preview) {
    var di = this.getDocumentInterface();
    var doc = this.getDocument();
    this.pos = event.getModelPosition();
    var op, i, transaction, objIds, objId, obj;

    switch (this.state) {
    case PointMarkDraw.State.SettingBenchmarkPosition:
        this.benchmarkPos = this.pos;

        // insert bench mark symbol with label:
        if (preview) {
            this.updatePreview();
        }
        else {
            op = this.getOperation(false);
            transaction = di.applyOperation(op);
            di.setRelativeZero(this.pos);

            objIds = transaction.getAffectedObjects();
            for (i=0; i<objIds.length; i++) {
                objId = objIds[i];
                obj = doc.queryObjectDirect(objId);
                if (isBlockReferenceEntity(obj)) {
                    this.benchmarkHandle = obj.getHandle();
                    // benchmark refers to itself as benchmark:
                    obj.setCustomProperty("QCAD", "benchmark", "0x" + this.benchmarkHandle.toString(16));
                }
            }

            // update combo box with possible benchmarks to use as origin:
            this.initUiOptions();
            this.setState(PointMarkDraw.State.SettingPointPosition);
        }
        break;

    case PointMarkDraw.State.SettingPointPosition:
        // insert point mark:
        if (preview) {
            this.updatePreview();
        }
        else {
            op = this.getOperation(false);
            transaction = di.applyOperation(op);
            objIds = transaction.getAffectedObjects();
            for (i=0; i<objIds.length; i++) {
                objId = objIds[i];
                obj = doc.queryObjectDirect(objId);
                if (isBlockReferenceEntity(obj)) {
                    // point mark refers to benchmark:
                    obj.setCustomProperty("QCAD", "benchmark", "0x" + this.benchmarkHandle.toString(16));
                }
            }
        }
        break;
    }
};

/**
 * Finds the block attribute in the given document interface and adjusts its text.
 */
PointMarkDraw.prototype.updateLabel = function(di, benchmark, preview) {
    var doc = di.getDocument();
    var ids = doc.queryAllEntities();
    for (var i=0; i<ids.length; i++) {
        var id = ids[i];
        var entity = doc.queryEntityDirect(id);
        if (isAttributeEntity(entity)) {
            var data = entity.getData();
            data.setText(this.getLabel(benchmark, preview));
            entity.setData(data);
            break;
        }
    }
};

/**
 * \return Complete label for next marker.
 * \param benchmark True for benchmarks (origins).
 * \param preview False for final call (increments counter).
 */
PointMarkDraw.prototype.getLabel = function(benchmark, preview) {
    var optionsToolBar = EAction.getOptionsToolBar();
    if (isNull(optionsToolBar)) {
        return "";
    }

    var te = optionsToolBar.findChild(benchmark ? "BenchmarkLabel" : "PointLabel");
    if (isNull(te)) {
        return "";
    }

    var ret = te.text;

    if (this.autoAppendCounter) {
        var num = "";
        if (benchmark) {
            num = sprintf("%03d", this.benchmarkCounter);
            if (!preview) {
                this.benchmarkCounter++;
            }
        }
        else {
            num = sprintf("%03d", this.pointCounter);
            if (!preview) {
                this.pointCounter++;
            }
        }
        ret += num;
    }

    return ret;
};

PointMarkDraw.prototype.getOperation = function(preview) {
    var op;

    switch (this.state) {
    case PointMarkDraw.State.SettingBenchmarkPosition:
        this.updateLabel(this.diBM, true, preview);
        op = new RPasteOperation(this.diBM.getDocument());
        break;
    case PointMarkDraw.State.SettingPointPosition:
        this.updateLabel(this.diPoint, false, preview);
        op = new RPasteOperation(this.diPoint.getDocument());
        break;
    default:
        return undefined;
    }

    op.setOffset(this.pos);
    op.setOverwriteBlocks(false);

    return op;
};

PointMarkDraw.prototype.slotPointLabelChanged = function(value) {
    this.updatePreview(true);
};

PointMarkDraw.prototype.slotBenchmarkLabelChanged = function(value) {
    this.updatePreview(true);
};

PointMarkDraw.prototype.slotAutoAppendCounterChanged = function(value) {
    this.autoAppendCounter = value;
    this.updatePreview(true);
};

PointMarkDraw.prototype.slotTextHeightChanged = function(value) {
    this.textHeight = value;
    this.updatePreview(true);
};

PointMarkDraw.prototype.slotBenchmarkChanged = function(value) {
    //this.textHeight = value;
    qDebug("PointMarkDraw.prototype.slotBenchmarkChanged: ", value);

    if (value===-1) {
        return;
    }

    var optionsToolBar = EAction.getOptionsToolBar();
    if (isNull(optionsToolBar)) {
        return;
    }
    var benchmarkCombo = optionsToolBar.findChild("Benchmark");
    if (isNull(benchmarkCombo)) {
        return;
    }

    this.benchmarkHandle = benchmarkCombo.itemData(value);
    this.initUiOptions(false);
    this.updatePreview(true);

    // new benchmark:
    //if (value===0) {

    //}
};

PointMarkDraw.prototype.slotAddBenchmark = function() {
    this.setState(PointMarkDraw.State.SettingBenchmarkPosition);
};