//
// Created by magda on 26.02.2018.
//

#include "Angle.h"
#include <cmath>

double goodAngle(double angle)
{
    while(angle < 0.0 || angle > 2*M_PI)
    {

        if (angle > 0.0)
            angle += (-2) * M_PI;
        else
            angle += 2 * M_PI;
    }

    return angle;
}

Angle::Angle(const Angle &copy)
{
    m_rad = copy.m_rad;
}

Angle::Angle()
{
    m_rad=0;
}
Angle::Angle(double rad)
{
    rad=goodAngle(rad);
    m_rad=rad;
}

 Angle Angle::fromRadians(double rad)
 {
     rad=goodAngle(rad);

     Angle new_angle(rad);

     return  new_angle;
 }
 Angle Angle::fromDegrees(double deg)
 {
     deg=deg*M_PI/180;
     deg=goodAngle(deg);
     Angle new_angle(deg);

    return new_angle;
 }
 Angle Angle::distance(const Angle& first, const Angle& second)
 {
    double diff_angle;

     if(first.m_rad > second.m_rad)
         diff_angle=first.m_rad-second.m_rad;
     else
         diff_angle=second.m_rad-first.m_rad;

     diff_angle=goodAngle(diff_angle);

     if(diff_angle > M_PI)
         diff_angle = 2*M_PI-diff_angle;

     Angle new_angle(diff_angle);

     return new_angle;
 }
double Angle::toRad() const
{
    return m_rad;
}
double Angle::toDeg() const
{
    return m_rad*180/M_PI;
}
Angle& Angle::add(const Angle& first)
{
    m_rad+=first.m_rad;
    m_rad=goodAngle(m_rad);

    return *this;

}
Angle::operator double() const
{
    return m_rad;
}
