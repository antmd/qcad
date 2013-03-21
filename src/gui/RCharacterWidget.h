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

#ifndef RCHARACTERWIDGET_H
#define RCHARACTERWIDGET_H

#include <QMetaType>
#include <QFont>
#include <QPoint>
#include <QSize>
#include <QString>
#include <QWidget>
#include <QtDesigner/QDesignerExportWidget>

class QMouseEvent;
class QPaintEvent;

/**
 * \scriptable
 */
class /*QDESIGNER_WIDGET_EXPORT*/ RCharacterWidget: public QWidget {

    Q_OBJECT

public:
    RCharacterWidget(QWidget *parent = 0);
    QSize sizeHint() const;

    QFont getDisplayFont();

public slots:
    void updateFont(const QFont &font);
    void updateSize(const QString &fontSize);
    void updateStyle(const QString &fontStyle);
    void updateFontMerging(bool enable);

signals:
    void characterSelected(const QString &character);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QFont displayFont;
    int columns;
    int lastKey;
    int squareSize;
};

Q_DECLARE_METATYPE(RCharacterWidget*)

#endif