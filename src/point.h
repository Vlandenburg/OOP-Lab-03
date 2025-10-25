#pragma once
#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

inline std::istream& operator>>(std::istream& in, Point& p) {
    char dummy;
    in >> dummy >> p.x >> dummy >> p.y >> dummy;
    return in;
}

inline std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

inline bool operator==(const Point& p1, const Point& p2) {
    const double epsilon = 1e-9;
    return std::fabs(p1.x - p2.x) < epsilon && std::fabs(p1.y - p2.y) < epsilon;
}