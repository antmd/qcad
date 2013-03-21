/**
 * Copyright (c) 2011-2013 by Andrew Mustun. All rights reserved.
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

 
include("../Layer.js");
include("../LayerDialog.js");

/**
 * This action handles all user interaction to edit the current layer.
 */
function EditLayer(guiAction) {
    Layer.call(this, guiAction);
}

EditLayer.prototype = new Layer();

EditLayer.prototype.beginEvent = function() {
    Layer.prototype.beginEvent.call(this);

    var layer = this.getDocument().queryCurrentLayer();
    
    var dlg = new LayerDialog(this.getDocument(), layer);
    var newLayer = dlg.show();
    if (!newLayer) {
        this.terminate();
        return;
    }
    
    var operation = new RAddObjectOperation(newLayer);
    var di = this.getDocumentInterface();
    di.applyOperation(operation);
    di.clearPreview();
    di.repaintViews();
    
    this.terminate();
};
