#pragma once
#include "point.h"
#include <iostream>

class Figure {
public:
    virtual ~Figure() = default;

    virtual Point calculateGeometricCenter() const = 0;
    virtual operator double() const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}