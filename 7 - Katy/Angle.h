//
// Created by magda on 26.02.2018.
//

#ifndef INC_7_KATY_ANGLE_H
#define INC_7_KATY_ANGLE_H


class Angle {

public:
    Angle(const Angle &copy);
    static Angle fromRadians(double rad);
    static Angle fromDegrees(double deg);
    static Angle distance(const Angle& first, const Angle& second);
    double toRad() const;
    double toDeg() const;
    Angle& add(const Angle& first);
    operator double() const;

private:
    Angle();
    Angle(double rad);
    double m_rad;

};


#endif //INC_7_KATY_ANGLE_H
