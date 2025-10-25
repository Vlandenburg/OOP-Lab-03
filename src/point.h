#pragma once
#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

inline std::istream& operator>>(std::istream& is, Point& p) {
    char open_bracket, comma, close_bracket;
    is >> open_bracket >> p.x >> comma >> p.y >> close_bracket;
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

inline bool operator==(const Point& p1, const Point& p2) {
    const double Epsilon = 0.00000001;
    if (std::fabs(p1.x - p2.x) < Epsilon && std::fabs(p1.y - p2.y) < Epsilon) {
        return true;
    }
    return false;
}