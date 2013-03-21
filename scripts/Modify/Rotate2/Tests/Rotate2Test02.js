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
// Auto generated by Testing Dashboard
// File        : scripts/Modify/Rotate2/Tests/Rotate2Test02.js
// Timestamp   : 2011-08-08 14:34:24
// Description : Rotate 2 using arcs

include('scripts/Developer/TestingDashboard/TdbTest.js');

function Rotate2Test02() {
    TdbTest.call(this, 'scripts/Modify/Rotate2/Tests/Rotate2Test02.js');
}

Rotate2Test02.prototype = new TdbTest();

Rotate2Test02.prototype.test00 = function() {
    qDebug('running Rotate2Test02.test00()...');
    this.setUp();
    this.importFile('scripts/Modify/Rotate2/Tests/data/arc.dxf');
    var w = objectFromPath('MainWindow::CadToolsDock::CadToolBar::MainToolsPanel');
    this.sendMouseEvent(w, QEvent.MouseButtonPress, new QPoint(49, 429), Qt.LeftButton, 1, 0);
    var w = objectFromPath('MainWindow::CadToolsDock::CadToolBar::MainToolsPanel');
    this.sendMouseEvent(w, QEvent.MouseButtonRelease, new QPoint(49, 429), Qt.LeftButton, 0, 0);
    var p = new RVector(269.560238, 74.192103);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.MidButton, 4, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.MidButton, 0, 0);
    var p = new RVector(254.059232, 130.2342);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.MidButton, 4, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.MidButton, 0, 0);
    this.setZoom(0.8386552701086307, new RVector(35.6903, 196.479, 0) );
    var p = new RVector(23.928919, 62.268252);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.triggerCommand('rotate2');
    this.setToolOption('TranslateRotate/PrimaryAngle',  [ 15, 0 ] );
    this.setToolOption('TranslateRotate/SecondaryAngle',  [ -15, 0 ] );
    this.setToolOption('TranslateRotate/NumberOfCopies',  [ 10, 0 ] );
    this.updateToolOptions();
    this.setZoom(0.8386552701086307, new RVector(35.6903, 196.479, 0) );
    var p = new RVector(-3.495937, 2.649);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    var p = new RVector(116.934952, -4.50531);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.MidButton, 4, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.MidButton, 0, 0);
    var p = new RVector(-85.770505, -9.27485);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.MidButton, 4, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.MidButton, 0, 0);
    this.setZoom(1.0063863241303568, new RVector(188.514, 180.978, 0) );
    var p = new RVector(-168.641265, -37.892091);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    this.dlgStart();
    this.dlgAppendCode('var map = new Map()');
    this.dlgAppendCode("map.put('DialogOpenedByTdb/groupBox', 'MultipleCopies')");
    this.dlgAppendCode("map.put('DialogOpenedByTdb/NumberOfCopies',  [ 10, 0 ] )");
    this.dlgAppendCode("map.put('DialogOpenedByTdb/PrimaryAngle',  [ 15, 0 ] )");
    this.dlgAppendCode("map.put('DialogOpenedByTdb/SecondaryAngle',  [ -15, 0 ] )");
    this.dlgAppendCode("map.put('DialogOpenedByTdb/UseCurrentAttributes', false)");
    this.dlgAppendCode("WidgetFactory.restoreState(dialog, 'DialogOpenedByTdb', undefined, false, undefined, map)");
    this.dlgEnd();
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.verifyDrawing('Rotate2Test02_000.dxf');
    this.tearDown();
    qDebug('finished Rotate2Test02.test00()');
};
