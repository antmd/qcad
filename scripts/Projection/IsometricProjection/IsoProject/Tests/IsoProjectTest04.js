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
// File        : scripts/Projection/IsometricProjection/IsoProject/Tests/IsoProjectTest04.js
// Timestamp   : 2011-08-05 14:05:32
// Description : isometric projection of an ellipse using segment length 1

include('scripts/Developer/TestingDashboard/TdbTest.js');

function IsoProjectTest04() {
    TdbTest.call(this, 'scripts/Projection/IsometricProjection/IsoProject/Tests/IsoProjectTest04.js');
}

IsoProjectTest04.prototype = new TdbTest();

IsoProjectTest04.prototype.test00 = function() {
    qDebug('running IsoProjectTest04.test00()...');
    this.setUp();
    this.importFile('scripts/Projection/IsometricProjection/IsoProject/Tests/data/cube_ellipse.dxf');
    var w = objectFromPath('MainWindow::CadToolsDock::CadToolBar::MainToolsPanel');
    this.sendMouseEvent(w, QEvent.MouseButtonPress, new QPoint(61, 425), Qt.LeftButton, 1, 0);
    var w = objectFromPath('MainWindow::CadToolsDock::CadToolBar::MainToolsPanel');
    this.sendMouseEvent(w, QEvent.MouseButtonRelease, new QPoint(61, 425), Qt.LeftButton, 0, 0);
    this.setZoom(6.914994309623345, new RVector(1.69613, 14.7619, 0) );
    var p = new RVector(15.079008, 11.991533);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.triggerCommand('pj');
    this.setZoom(6.914994309623345, new RVector(1.69613, 14.7619, 0) );
    var p = new RVector(9.728316, 19.80065);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setToolOption('IsoProject/ProjectionType', 'Top');
    this.setToolOption('IsoProject/SegmentLength',  [ 1, 0 ] );
    this.updateToolOptions();
    this.setZoom(6.914994309623345, new RVector(1.69613, 14.7619, 0) );
    var p = new RVector(57.161472, 28.477447);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setToolOption('IsoProject/ProjectionType', 'Right');
    this.setToolOption('IsoProject/SegmentLength',  [ 1, 0 ] );
    this.updateToolOptions();
    this.setZoom(6.914994309623345, new RVector(1.69613, 14.7619, 0) );
    var p = new RVector(57.306085, 20.089877);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setToolOption('IsoProject/ProjectionType', 'Left');
    this.setToolOption('IsoProject/SegmentLength',  [ 1, 0 ] );
    this.updateToolOptions();
    this.setZoom(6.914994309623345, new RVector(1.69613, 14.7619, 0) );
    var p = new RVector(42.700144, 19.945264);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    var p = new RVector(30.118789, 17.486838);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    var p = new RVector(28.672656, 17.631451);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    this.verifyDrawing('IsoProjectTest04_000.dxf');
    this.tearDown();
    qDebug('finished IsoProjectTest04.test00()');
};
