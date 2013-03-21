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

#ifndef RLINEENTITY_H
#define RLINEENTITY_H

#include "REntity.h"
#include "RLineData.h"

class RDocument;
class RExporter;

/**
 * Line entity.
 *
 * \scriptable
 * \sharedPointerSupport
 * \ingroup entity
 */
class RLineEntity: public REntity {

public:
    static RPropertyTypeId PropertyCustom;
    static RPropertyTypeId PropertyHandle;
    static RPropertyTypeId PropertyType;
    static RPropertyTypeId PropertyBlock;
    static RPropertyTypeId PropertyLayer;
    static RPropertyTypeId PropertyLinetype;
    static RPropertyTypeId PropertyLineweight;
    static RPropertyTypeId PropertyColor;
    static RPropertyTypeId PropertyDrawOrder;

    static RPropertyTypeId PropertyStartPointX;
    static RPropertyTypeId PropertyStartPointY;
    static RPropertyTypeId PropertyStartPointZ;
    static RPropertyTypeId PropertyEndPointX;
    static RPropertyTypeId PropertyEndPointY;
    static RPropertyTypeId PropertyEndPointZ;

    static RPropertyTypeId PropertyAngle;
    static RPropertyTypeId PropertyLength;

public:
    RLineEntity(RDocument* document, const RLineData& data,
        RObject::Id objectId = RObject::INVALID_ID);
    virtual ~RLineEntity();

    static void init();

    virtual RLineEntity* clone() const {
        return new RLineEntity(*this);
    }

    virtual RS::EntityType getType() const {
        return RS::EntityLine;
    }

    bool setProperty(RPropertyTypeId propertyTypeId, const QVariant& value);
    QPair<QVariant, RPropertyAttributes> getProperty(
            RPropertyTypeId propertyTypeId,
            bool humanReadable = false, bool noAttributes = false);

    virtual void exportEntity(RExporter& e, bool preview=false) const;

    virtual RLineData& getData() {
        return data;
    }

    virtual const RLineData& getData() const {
        return data;
    }

    void setShape(const RLine& l);

    void setStartPoint(const RVector& p) {
        data.setStartPoint(p);
    }

    RVector getStartPoint() const {
        return data.getStartPoint();
    }

    void setEndPoint(const RVector& p) {
        data.setEndPoint(p);
    }

    RVector getEndPoint() const {
        return data.getEndPoint();
    }

    double getAngle() const {
        return data.getAngle();
    }

    double getDirection1() const {
        return data.getDirection1();
    }

    double getDirection2() const {
        return data.getDirection2();
    }

    bool reverse() {
        return data.reverse();
    }

    RS::Side getSideOfPoint(const RVector& point) const {
        return data.getSideOfPoint(point);
    }

    RS::Ending getTrimEnd(const RVector& coord,
                            const RVector& trimPoint) {
        return data.getTrimEnd(coord, trimPoint);
    }

    void trimStartPoint(const RVector& p) {
        return data.trimStartPoint(p);
    }
    void trimEndPoint(const RVector& p) {
        return data.trimEndPoint(p);
    }

    double getLength() const {
        return data.getLength();
    }

protected:
    virtual void print(QDebug dbg) const;

protected:
    RLineData data;
};

Q_DECLARE_METATYPE(RLineEntity*)
Q_DECLARE_METATYPE(QSharedPointer<RLineEntity>)
Q_DECLARE_METATYPE(QSharedPointer<RLineEntity>*)

#endif