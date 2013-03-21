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
// File        : scripts/Draw/Line/LineParallelThrough/Tests/LineParallelThroughTest00.js
// Timestamp   : 2011-02-28 10:19:53
// Description : 4 parallel lines through end points of other lines

include('scripts/Developer/TestingDashboard/TdbTest.js');

function LineParallelThroughTest00() {
    TdbTest.call(this, 'scripts/Draw/Line/LineParallelThrough/Tests/LineParallelThroughTest00.js');
}

LineParallelThroughTest00.prototype = new TdbTest();

LineParallelThroughTest00.prototype.test00 = function() {
    qDebug('running LineParallelThroughTest00.test00()...');
    this.setUp();
    this.clickOnWidget('MainWindow::MainToolsPanel::LineMenuButton');
    this.clickOnWidget('MainWindow::LineToolsPanel::Line2PButton');
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(5.6, 24.4);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(5.8, 24.3);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(38.5, 26.6);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(38.5, 26.6);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    var p = new RVector(29.9, 22.3);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    var p = new RVector(29.9, 22.3);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    var p = new RVector(3.4, 31.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    var p = new RVector(3.4, 31.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    this.clickOnWidget('MainWindow::MainToolsPanel::LineMenuButton');
    this.clickOnWidget('MainWindow::LineToolsPanel::Line2PButton');
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(12.1, 15);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(12.1, 15);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(7.5, 3.8);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(7.5, 3.8);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    var p = new RVector(33.6, 14.1);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    var p = new RVector(33.6, 14.1);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(28.1, 21.8);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(28.1, 21.8);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(36.1, 1.3);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(36.1, 1.3);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    var p = new RVector(36.9, 13.5);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    var p = new RVector(36.9, 13.5);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    var p = new RVector(10.6, 26);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    var p = new RVector(10.6, 26);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    this.clickOnWidget('MainWindow::MainToolsPanel::LineMenuButton');
    this.clickOnWidget('MainWindow::LineToolsPanel::LineParallelThroughButton');
    this.setToolOption('LineParallelThrough/Number', '1');
    this.updateToolOptions();
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(17, 25.2);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(17, 25.2);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(28.1, 21.8);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(28.1, 21.8);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(12, 14.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(12, 14.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(7.8, 4.1);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(7.8, 4.1);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(35.9, 1);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(35.9, 1);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    var p = new RVector(39.7, 12.6);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    var p = new RVector(39.7, 12.6);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    var p = new RVector(-0.3, 16.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    var p = new RVector(-0.3, 16.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    this.verifyDrawing('LineParallelThroughTest00_000.dxf');
    this.tearDown();
    qDebug('finished LineParallelThroughTest00.test00()');
};
