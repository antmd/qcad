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
#ifdef Q_OS_WIN32
// for _isnan:
#include <cfloat>
#endif

#include <complex>

#include <QRegExp>
#include <QScriptEngine>

#include "RDebug.h"
#include "RMath.h"
#include "RSettings.h"


QString RMath::lastError = "";

int RMath::absmod(int a, int b) {
    if (b == 0) {
        return a;
    }
    int m = a % b;
    if ((b < 0 && m > 0) || (b > 0 && m < 0)) {
        return b + m;
    }
    return m;
}

double RMath::trunc(double v) {
#ifdef Q_OS_MAC
    return ::trunc(v);
#elif defined Q_OS_WIN32
    if (v==0 || RMath::isNaN(v) || RMath::isInf(v)) {
        return v;
    }
    if (v >= 0.0) {
        return floor(v);
    }
    else {
        return ceil(v);
    }
#else
    return ::trunc(v);
#endif
}

/**
 * Safe pow function.
 *
 * \param x the base
 * \param y the exponent
 *
 * \return The value of x raised to the power of y.
 */
double RMath::pow(double x, double y) {
    errno = 0;
    double ret = ::pow(x, y);
    if (errno == EDOM) {
        qCritical("RMath::pow: EDOM in pow");
        ret = 0.0;
    } else if (errno == ERANGE) {
        qCritical("RMath::pow: ERANGE in pow");
        ret = 0.0;
    }
    return ret;
}


bool RMath::isNormal(double v) {
    if (RMath::isNaN(v) || RMath::isInf(v)) {
        return false;
    }
    return true;
}

bool RMath::isNaN(double v) {
#ifdef Q_OS_MAC
    return std::fpclassify(v)==FP_NAN;
#elif defined Q_OS_WIN32
    return _isnan(v);
#else
    return std::isnan(v);
#endif
}

bool RMath::isInf(double v) {
#ifdef Q_OS_MAC
    return std::fpclassify(v)==FP_INFINITE;
#elif defined Q_OS_WIN32
    return !_finite(v);
#else
    return std::fpclassify(v)==FP_INFINITE;
#endif
}

double RMath::eval(const QString& expression, bool* ok) {
    lastError = "";

    if (expression.isEmpty()) {
        if (ok!=NULL) {
            *ok = false;
        }
        lastError = "Expression is empty";
        //qDebug() << "RMath::evel: error: " << lastError;
        return RNANDOUBLE;
    }

    if (ok!=NULL) {
        *ok = true;
    }

    QString expr = expression;

    // 'correct' commas to points:
    if (RSettings::getNumberLocale().decimalPoint()==',') {
        expr.replace(',', '.');
    }

    if (expr.contains(',') || expr.contains(';')) {
        if (ok!=NULL) {
            *ok = false;
        }
        lastError = "Multiple expressions";
        return RNANDOUBLE;
    }

    int idx = -1;

    // convert surveyor type angles (e.g. N10d30'12.5"E) to degrees:
    if (expr.contains(QRegExp("[NESW]", Qt::CaseInsensitive))) {
        // \b(?:(?:([NS])(?:([+-]?)(?:(?:(\d*\.?\d*)[d°])?(?:(\d*\.?\d*)')?(?:(\d*\.?\d*)")?|(\d*))([EW]))?)|([EW]))\b
        QRegExp re(
            "\\b"                               // a word
            "(?:"
              "(?:"
                "([NS])"                        // expression starts with nord or south
                "(?:"
                  "([+-]?)"                     // sign
                  "(?:"
                    "(?:(\\d*\\.?\\d*)[d°])?"   // degrees with d
                    "(?:(\\d*\\.?\\d*)')?"      // minutes with '
                    "(?:(\\d*\\.?\\d*)\")?"     // seconds with "
                    "|"                         // or...
                    "(\\d*)"                    // degrees without d
                  ")"
                  "([EW])"                      // east or west
                ")?"
              ")"
              "|"                               // or...
              "([EW])"                          // only east (0d) or west (180d)
            ")"
            "\\b",
            Qt::CaseInsensitive, QRegExp::RegExp2);
        do {
            idx = re.indexIn(expr);
            if (idx==-1) {
                break;
            }
            double angle = 0.0;
            QString sign;

            // "E" or "W":
            if (!re.cap(8).isEmpty()) {
                if (re.cap(8).toUpper()=="E") {
                    angle = 0.0;
                }
                else if (re.cap(8).toUpper()=="W") {
                    angle = 180.0;
                }
                else {
                    if (ok!=NULL) {
                        *ok = false;
                    }
                    lastError = "Invalid cardinal direction found (valid values are: N,E,S,W)";
                    return RNANDOUBLE;
                }
            }
            // "[NS]...[EW]":
            else {
                bool north = re.cap(1).toUpper()=="N";
                bool south = re.cap(1).toUpper()=="S";
                sign = re.cap(2);
                double degrees = 0.0;
                double minutes = 0.0;
                double seconds = 0.0;
                if (!re.cap(6).isEmpty()) {
                    degrees = re.cap(6).toDouble(ok);
                }
                else {
                    degrees = re.cap(3).toDouble(ok);
                    minutes = re.cap(4).toDouble(ok);
                    seconds = re.cap(5).toDouble(ok);
                }
                bool east = re.cap(7).toUpper()=="E";
                bool west = re.cap(7).toUpper()=="W";

                double base = (north ? 90.0 : 270.0);
                int dir = ((north && west) || (south && east) ? 1 : -1);
                angle = base + dir * (degrees + minutes/60.0 + seconds/3600.0);
            }

            expr.replace(
                re.cap(),
                QString("%1%2").arg(sign).arg(angle, 0, 'g', 16)
            );
        } while(idx!=-1);
    }

    //qDebug() << "RMath::eval: expression 001 is: " << expr;

    // convert radiant angles (e.g. "1.2r") to degrees:
    {
        QRegExp re("((?:\\.\\d+)|(?:\\d+\\.\\d*)|(?:\\d+))r\\b", Qt::CaseInsensitive, QRegExp::RegExp2);
        do {
            idx = re.indexIn(expr);
            if (idx==-1) {
                break;
            }
            QString match = re.cap(1);
            //qDebug() << "RMath::eval: match 001a is: " << match;
            expr.replace(
                re,
                QString("%1").arg(rad2deg(match.toDouble(ok)), 0, 'g', 16)
            );
            //qDebug() << "RMath::eval: expression 001a is: " << expr;
        } while(idx!=-1);
    }

    //qDebug() << "RMath::eval: expression 002 is: " << expr;

    // convert grad angles (e.g. "100g") to degrees:
    {
        QRegExp re("((?:\\.\\d+)|(?:\\d+\\.\\d*)|(?:\\d+))g\\b", Qt::CaseInsensitive, QRegExp::RegExp2);
        do {
            idx = re.indexIn(expr);
            if (idx==-1) {
                break;
            }
            QString match = re.cap(1);
            expr.replace(
                re,
                QString("%1").arg(gra2deg(match.toDouble(ok)), 0, 'g', 16)
            );
        } while(idx!=-1);
    }

    //qDebug() << "RMath::eval: expression 003 is: " << expr;

    // convert explicitely indicated degree angles (e.g. "90d") to degrees:
    {
        QRegExp re("((?:\\.\\d+)|(?:\\d+\\.\\d*)|(?:\\d+))d\\b", Qt::CaseInsensitive, QRegExp::RegExp2);
        do {
            idx = re.indexIn(expr);
            if (idx==-1) {
                break;
            }
            QString match = re.cap(1);
            expr.replace(
                re,
                QString("%1").arg(match.toDouble(ok), 0, 'g', 16)
            );
        } while(idx!=-1);
    }

    // convert fraction notation to formula:
    // e.g. 7 3/32 to 7+3/32
    {
        QRegExp re("(\\d+)[ ]+(\\d+/\\d+)", Qt::CaseInsensitive, QRegExp::RegExp2);
        do {
            idx = re.indexIn(expr);
            if (idx==-1) {
                break;
            }
            QString numberString = re.cap(1);
            QString fractionString = re.cap(2);
            expr.replace(
                re,
                QString("%1+%2").arg(numberString).arg(fractionString)
            );
        } while(idx!=-1);
    }

    //qDebug() << "RMath::eval: expression is: " << expr;

    QScriptEngine e;

    // add common functions of Math to global scope for use in math input fields:
    QStringList mathProp;
    mathProp  << "PI" << "LN2" << "LN10" << "LOG2E" << "LOG10E" << "SQRT1_2" << "SQRT2"
          << "abs"
          //<< "cos" << "sin" << "tan"
          //<< "acos" << "asin" << "atan" << "atan2"
          << "ceil" << "floor"
          << "exp" << "log"
          << "max" << "min"
          << "pow" << "sqrt"
          << "random"
          << "round";
    for (int i=0; i<mathProp.length(); i++) {
        e.evaluate(mathProp[i] + " = Math." + mathProp[i]);
    }

    e.evaluate("rad2deg = function(a) { return a / (2.0 * Math.PI) * 360.0; }");
    e.evaluate("deg2rad = function(a) { return (a / 360.0) * (2.0 * Math.PI); }");

    e.evaluate("sin = function(v) { return Math.sin(deg2rad(v)); }");
    e.evaluate("cos = function(v) { return Math.cos(deg2rad(v)); }");
    e.evaluate("tan = function(v) { return Math.tan(deg2rad(v)); }");

    e.evaluate("asin = function(v) { return rad2deg(Math.asin(v)); }");
    e.evaluate("acos = function(v) { return rad2deg(Math.acos(v)); }");
    e.evaluate("atan = function(v) { return rad2deg(Math.atan(v)); }");
    //e.evaluate("atan2 = function(y,x) { return rad2deg(Math.atan2(y,x)); }");

    QScriptValue res = e.evaluate(expr);

    if (res.isError()) {
        if (ok!=NULL) {
            *ok = false;
        }
        lastError = res.toString();
        //qDebug() << "RMath::evel: error: " << lastError;
        return RNANDOUBLE;
    }

    if (!res.isNumber()) {
        if (ok != NULL) {
            *ok = false;
        }
        lastError = expr + " is not a number";
        //qDebug() << "RMath::evel: error: " << lastError;
        return RNANDOUBLE;
    }

    //qDebug() << "res.toNumber(): " << res.toNumber();
    //qDebug() << "fpclassify: " << std::fpclassify(res.toNumber());

    if (!isNormal(res.toNumber())) {
        if (ok != NULL) {
            *ok = false;
        }
        lastError = expr + " is not a normal number";
        //qDebug() << "RMath::evel: error: " << lastError;
        return RNANDOUBLE;
    }

    return res.toNumber();
}

QString RMath::getError() {
    return lastError;
}

bool RMath::hasError() {
    return !lastError.isEmpty();
}

/**
 * Converts the given string to an angle. Accepted
 * formats are:
 * #.## for an angle in degrees,
 * #.##r for an angle in rad,
 * #.##g for an angle in gon,
 * ##d##.#'##.##" for an angle in degrees, minutes, seconds,
 * N##d##'##"E, S##D##'##"E for suveyors units.
 */
/*double RMath::stringToAngle(const QString& str) {
    if (str.isEmpty()) {
        return 0.0;
    }

    if (str.endsWith('r', Qt::CaseInsensitive)) {

    }

}*/

/**
 * Converts the given angle in rad to the given angle format.
 * \todo Support different formats.
 */
QString RMath::angleToString(double a) {
    return QString("%1").arg(rad2deg(a));
}


/**
 * Converts radians to degrees.
 *
 * \param a angle in radians
 */
double RMath::rad2deg(double a) {
    return (a / (2.0 * M_PI) * 360.0);
}

/**
 * Converts grads to degrees.
 *
 * \param a angle in grad (gon)
 */
double RMath::gra2deg(double a) {
    return a / 400.0 * 360.0;
}

/**
 * Converts degrees to radians.
 *
 * \param a angle in degrees
 */
double RMath::deg2rad(double a) {
    return ((a / 360.0) * (2.0 * M_PI));
}

/**
 * Converts radians to gradians.
 *
 * \param a angle in radians
 */
double RMath::rad2gra(double a) {
    return (a / (2.0 * M_PI) * 400.0);
}

/**
 * Finds greatest common divider using Euclid's algorithm.
 * \sa http://en.wikipedia.org/wiki/Greatest_common_divisor
 *
 * \param a the first number
 *
 * \param b the second number
 *
 * \return The greatest common divisor of \c a and \c b.
 */
int RMath::getGcd(int a, int b) {
    int rem;

    while (b != 0) {
        rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}

/**
 * Tests if angle a is between a1 and a2. a, a1 and a2 must be in the
 * range between 0 and 2*PI.
 * All angles in rad.
 *
 * \param a the test angle
 * \param a1 the lower limiting angle
 * \param a2 the upper limiting angle
 * \param reversed True for clockwise testing. False for ccw testing.
 * \return true if the angle a is between a1 and a2.
 */
bool RMath::isAngleBetween(double a, double a1, double a2, bool reversed) {

    a = RMath::getNormalizedAngle(a);
    a1 = RMath::getNormalizedAngle(a1);
    a2 = RMath::getNormalizedAngle(a2);

    bool ret = false;

    if (reversed) {
        double tmp = a1;
        a1 = a2;
        a2 = tmp;
    }

    if (a1 >= a2 - RS::AngleTolerance) {
        if (a >= a1 - RS::AngleTolerance || a <= a2 + RS::AngleTolerance) {
            ret = true;
        }
    } else {
        if (a >= a1 - RS::AngleTolerance && a <= a2 + RS::AngleTolerance) {
            ret = true;
        }
    }
    return ret;
}

/**
 * Gets the normalized angle from \c a.
 * Used to make sure that an angle is in the range between 0 and 2 pi.
 *
 * \param a the unnormalized angle, e.g. 8
 *
 * \return The angle \c a normalized to the range of \f$ 0 \ldots 2\pi \f$,
 * e.g. normalized angle from 8 is 1.716.
 */
double RMath::getNormalizedAngle(double a) {
    if (a >= 0.0) {
        int n = (int) floor(a / (2*M_PI));
        a -= 2*M_PI * n;
    } else {
        int n = (int) ceil(a / (-2*M_PI));
        a += 2*M_PI * n;
    }

    return a;
}

/**
 * \return Angle a as angle relative to baseAngle.
 *         Result is in range -PI < result < PI.
 */
double RMath::getRelativeAngle(double a, double baseAngle) {
    double ret = a - baseAngle;
    if (ret>M_PI) {
        ret-=2*M_PI;
    }
    return ret;
}

/**
 *
 * \param a1 first angle in rad
 *
 * \param a2 s second angle in rad
 *
 * \return The angle that needs to be added to a1 to reach a2.
 *         Always positive and less than 2*pi.
 */
double RMath::getAngleDifference(double a1, double a2) {
    double ret;

    if (a1 >= a2) {
        a2 += 2*M_PI;
    }
    ret = a2 - a1;

    if (ret >= 2*M_PI) {
        ret = 0.0;
    }

    return ret;
}

/**
 * \param a1 first angle in rad
 *
 * \param a2 s second angle in rad
 *
 * \return The angle that needs to be added to a1 to reach a2.
 *         Always between -pi and pi.
 */
double RMath::getAngleDifference180(double a1, double a2) {
    double ret;

    ret = a2 - a1;
    if (ret > M_PI) {
        ret = -(2*M_PI - ret);
    }
    if (ret < -M_PI) {
        ret = 2*M_PI + ret;
    }

    return ret;
}

/**
 * Adds 180° to the given angle if a text constructed with that angle
 * otherwise wouldn't be readable.
 * Used for dimension texts and for mirroring texts.
 *
 * \param angle the original angle
 *
 * \param readable true: make angle readable, false: unreadable
 *
 * \param corrected Pointer to boolean that will point to true if the given angle was
 *   corrected, false otherwise, or null.
 *
 * \return The given angle or the given \c angle + pi, depending which one
 * is readable from the bottom or right.
 */
double RMath::makeAngleReadable(double angle, bool readable, bool* corrected) {

    double ret;

    bool cor = isAngleReadable(angle) ^ readable;

    // quadrant 1 & 4
    if (!cor) {
        ret = angle;
    }
    // quadrant 2 & 3
    else {
        ret = angle + M_PI;
    }

    if (corrected != NULL) {
        *corrected = cor;
    }

    return ret;
}

/**
 * \param angle the angle in rad
 *
 * \param tolerance The tolerance by which the angle still maybe
 * in the unreadable range.
 *
 * \return true: If the given angle is in a range that is readable
 * for texts created with that angle.
 */
bool RMath::isAngleReadable(double angle, double tolerance) {
    double angleCorrected = getNormalizedAngle(angle);
    if (angleCorrected > M_PI / 2.0 * 3.0 + tolerance || angleCorrected < M_PI
            / 2.0 + tolerance) {
        return true;
    } else {
        return false;
    }
}

/**
 * Tests if two angels point approximately in the same direction.
 *
 * \param dir1 first direction
 *
 * \param dir2 second direction
 *
 * \param tolerance Tolerance in rad.
 *
 * \retval true The two angles point in the same direction.
 *
 * \retval false The difference between the two angles is at
 * least \c tolerance radians.
 */
bool RMath::isSameDirection(double dir1, double dir2, double tolerance) {
    double diff = fabs(dir1 - dir2);
    if (diff < tolerance || diff > 2*M_PI - tolerance) {
        return true;
    } else {
        return false;
    }
}

QString RMath::toFractionString(double v, int maxDenominator) {
    int number, numerator, denominator;
    toFraction(v, maxDenominator, number, numerator, denominator);

    if (number==0) {
        return QString("%1/%2").arg(numerator).arg(denominator);
    }
    else {
        if (numerator==0) {
            return QString("%1").arg(number);
        }
        else {
            return QString("%1 %2/%3").arg(number).arg(numerator).arg(denominator);
        }
    }
}

void RMath::toFraction(double v, int maxDenominator, int& number, int& numerator, int& denominator) {
    int in = (int)v;
    number = in;

    if (in==v) {
        number = in;
        numerator = 0;
        denominator = 1;
        return;
    }

    simplify(abs(mround((v-in)*maxDenominator)), maxDenominator, numerator, denominator);
}

void RMath::simplify(int numerator, int denominator, int& numeratorRes, int& denominatorRes) {
    int g = getGcd(numerator, denominator);
    numeratorRes = numerator/g;
    denominatorRes = denominator/g;
}


bool RMath::fuzzyCompare(double v1, double v2, double tolerance) {
    return fabs(v1-v2) < tolerance;
}

double RMath::parseScale(const QString& scaleString) {
    int i;
    double d;

    double scale = 1.0;

    if (scaleString.contains(':')) {
        // e.g. 1:5
        i = scaleString.indexOf(':');
        bool ok1 = false;
        bool ok2 = false;
        double n = scaleString.left(i).toDouble(&ok1);
        d = scaleString.mid(i+1).toDouble(&ok2);
        if (ok1 && ok2 && !RMath::isNaN(n) && !RMath::isNaN(d) && d>1.0e-6 && n>1.0e-6) {
            scale = n/d;
        }
    } else if (scaleString.endsWith(" = 1'-0\"")) {
        // e.g. 1/16" = 1'-0"
        i = scaleString.indexOf('"');
        d = RMath::eval(scaleString.mid(0, i));
        if (!RMath::isNaN(d) && d > 1.0e-6) {
            scale = d / 12.0;
        }
    } else if (scaleString.startsWith("1\" =")) {
        // e.g. 1" = 2"
        i = scaleString.indexOf('=');
        bool ok = false;
        d = scaleString.mid(i+2, scaleString.length()-i-3).toDouble(&ok);
        if (!RMath::isNaN(d) && d>1.0e-6 && ok) {
            scale = 1.0/d;
        }
    } else {
        double f = RMath::eval(scaleString);
        scale = f;
    }

    // don't allow scale to be 0 or less or NaN:
    if (scale<1.0e-12 || RMath::isNaN(scale)) {
        scale = 1.0;
    }

    return scale;
}

void RMath::getQuadRoots(double p[], double r[][5]) {
    /*
    Array r[3][5] p[5]
    Roots of poly p[0]*x^2 + p[1]*x + p[2]=0
    x=r[1][k] + i r[2][k] k=1,2
    */
    double b,c,d;
    b=-p[1]/(2.0*p[0]);
    c=p[2]/p[0];
    d=b*b-c;
    if(d>=0.0) {
        if(b>0.0)
            b=(r[1][2]=(sqrt(d)+b));
        else
            b=(r[1][2]=(-sqrt(d)+b));
        r[1][1]=c/b;
        r[2][1]=(r[2][2]=0.0);
    }
    else {
        d=(r[2][1]=sqrt(-d));
        r[2][2]=-d;
        r[1][1]=(r[1][2]=b);
    }
}

void RMath::getCubicRoots(double p[], double r[][5]) {
    /*
    Array r[3][5] p[5]
    Roots of poly p[0]*x^3 + p[1]*x^2 + p[2]*x + p[3] = 0
    x=r[1][k] + i r[2][k] k=1,...,3
    Assumes 0<arctan(x)<pi/2 for x>0
    */
    double s,t,b,c,d;
    int k;
    if(p[0]!=1.0)
    {
        for(k=1;k<4;k++)
            p[k]=p[k]/p[0];
        p[0]=1.0;
    }
    s=p[1]/3.0;
    t=s*p[1];
    b=0.5*(s*(t/1.5-p[2])+p[3]);
    t=(t-p[2])/3.0;
    c=t*t*t;
    d=b*b-c;
    if(d>=0.0) {
        d=pow((sqrt(d)+fabs(b)),1.0/3.0);
        if(d!=0.0) {
            if(b>0.0)
                b=-d;
            else
                b=d;
            c=t/b;
        }
        d=r[2][2]=sqrt(0.75)*(b-c);
        b=b+c;
        c=r[1][2]=-0.5*b-s;
        if((b>0.0 && s<=0.0) || (b<0.0 && s>0.0)) {
            r[1][1]=c;
            r[2][1]=-d;
            r[1][3]=b-s;
            r[2][3]=0.0;
        }
        else {
            r[1][1]=b-s;
            r[2][1]=0.0;
            r[1][3]=c;
            r[2][3]=-d;
        }

    } /* end 2 equal or complex roots */
    else {
        if(b==0.0)
            d=atan(1.0)/1.5;
        else
            d=atan(sqrt(-d)/fabs(b))/3.0;
        if(b<0.0)
            b=2.0*sqrt(t);
        else
            b=-2.0*sqrt(t);
        c=cos(d)*b;
        t=-sqrt(0.75)*sin(d)*b-0.5*c;
        d=-t-c-s;
        c=c-s;
        t=t-s;
        if(fabs(c)>fabs(t)) {
            r[1][3]=c;
        }
        else {
            r[1][3]=t;
            t=c;
        }
        if(fabs(d)>fabs(t)) {
            r[1][2]=d;
        }
        else {
            r[1][2]=t;
            t=d;
        }
        r[1][1]=t;
        for(k=1;k<4;k++)
            r[2][k]=0.0;
    }
    return;
}

void RMath::getBiQuadRoots(double p[],double r[][5]) {
    /*
    Array r[3][5] p[5]
    Roots of poly p[0]*x^4 + p[1]*x^3 + p[2]*x^2 + p[3]*x + p[4] = 0
    x=r[1][k] + i r[2][k] k=1,...,4
    */
    double a,b,c,d,e;
    int k,j;
    if(p[0] != 1.0)
    {
        for(k=1;k<5;k++)
            p[k]=p[k]/p[0];
        p[0]=1.0;
    }
    e=0.25*p[1];
    b=2.0*e;
    c=b*b;
    d=0.75*c;
    b=p[3]+b*(c-p[2]);
    a=p[2]-d;
    c=p[4]+e*(e*a-p[3]);
    a=a-d;
    p[1]=0.5*a;
    p[2]=(p[1]*p[1]-c)*0.25;
    p[3]=b*b/(-64.0);
    if(p[3]<0.0)
    {
        getCubicRoots(p,r);
        for(k=1;k<4;k++)
        {
            if(r[2][k]==0.0 && r[1][k]>0.0)
            {
                d=r[1][k]*4.0;
                a=a+d;
                if(a>=0.0 && b>=0.0)
                    p[1]=sqrt(d);
                else if(a<=0.0 && b<=0.0)
                    p[1]=sqrt(d);
                else
                    p[1]=-sqrt(d);
                b=0.5*(a+b/p[1]);
                goto QUAD;
            }

        }

    }
    if(p[2]<0.0)
    {
        b=sqrt(c);
        d=b+b-a;
        p[1]=0.0;
        if(d>0.0)
            p[1]=sqrt(d);
    }
    else
    {
        if(p[1]>0.0)
            b=sqrt(p[2])*2.0+p[1];
        else
            b=-sqrt(p[2])*2.0+p[1];
        if(b!=0.0)
        {
            p[1]=0.0;
        }
        else
        {
            for(k=1;k<5;k++)
            {
                r[1][k]=-e;
                r[2][k]=0.0;
            }
            goto END;
        }
    }
QUAD:
    p[2]=c/b;
    getQuadRoots(p,r);
    for(k=1;k<3;k++)
        for(j=1;j<3;j++)
            r[j][k+2]=r[j][k];
    p[1]=-p[1];
    p[2]=b;
    getQuadRoots(p,r);
    for(k=1;k<5;k++)
        r[1][k]=r[1][k]-e;
END:
    return;
}