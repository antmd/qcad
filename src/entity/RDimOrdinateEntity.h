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

#ifndef RDIMORDINATEENTITY_H
#define RDIMORDINATEENTITY_H

#include "RDimensionEntity.h"
#include "RDimOrdinateData.h"

class RDocument;
class RExporter;

/**
 * Ordinate dimension entity class.
 *
 * \scriptable
 * \sharedPointerSupport
 * \ingroup entity
 */
class RDimOrdinateEntity: public RDimensionEntity {

    Q_DECLARE_TR_FUNCTIONS(RDimOrdinateEntity)

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

    static RPropertyTypeId PropertyMiddleOfTextX;
    static RPropertyTypeId PropertyMiddleOfTextY;
    static RPropertyTypeId PropertyMiddleOfTextZ;
    static RPropertyTypeId PropertyText;
    static RPropertyTypeId PropertyUpperTolerance;
    static RPropertyTypeId PropertyLowerTolerance;

    static RPropertyTypeId PropertyOriginX;
    static RPropertyTypeId PropertyOriginY;
    static RPropertyTypeId PropertyOriginZ;

    static RPropertyTypeId PropertyOrdinate;

    static RPropertyTypeId PropertyLeaderEndPointX;
    static RPropertyTypeId PropertyLeaderEndPointY;
    static RPropertyTypeId PropertyLeaderEndPointZ;

    static RPropertyTypeId PropertyDefiningPointX;
    static RPropertyTypeId PropertyDefiningPointY;
    static RPropertyTypeId PropertyDefiningPointZ;

public:
    RDimOrdinateEntity(RDocument* document, const RDimOrdinateData& data,
                      RObject::Id objectId = RObject::INVALID_ID);
    virtual ~RDimOrdinateEntity();

    static void init();

    virtual RDimOrdinateEntity* clone() const {
        return new RDimOrdinateEntity(*this);
    }

    virtual RS::EntityType getType() const {
        return RS::EntityDimOrdinate;
    }

    bool setProperty(RPropertyTypeId propertyTypeId, const QVariant& value);
    QPair<QVariant, RPropertyAttributes> getProperty(
            RPropertyTypeId propertyTypeId,
            bool humanReadable = false, bool noAttributes = false);

    virtual RDimOrdinateData& getData() {
        return data;
    }

    void setData(RDimOrdinateData& d) {
        data = d;
    }

    virtual const RDimOrdinateData& getData() const {
        return data;
    }

    void setLeaderEndPoint(const RVector& p) {
        data.setLeaderEndPoint(p);
    }

    RVector getLeaderEndPoint() const {
        return data.getLeaderEndPoint();
    }

    void setDefiningPoint(const RVector& p) {
        data.setDefiningPoint(p);
    }

    RVector getDefiningPoint() const {
        return data.getDefiningPoint();
    }

protected:
    virtual void print(QDebug dbg) const;

protected:
    RDimOrdinateData data;
};

Q_DECLARE_METATYPE(RDimOrdinateEntity*)
Q_DECLARE_METATYPE(QSharedPointer<RDimOrdinateEntity>)
Q_DECLARE_METATYPE(QSharedPointer<RDimOrdinateEntity>*)

#endif