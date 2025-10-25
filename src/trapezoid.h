#pragma once
#include "figure.h"
#include <array>

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(const std::array<Point, 4>& vertices);

    Point calculateGeometricCenter() const;
    double calculateArea() const;
    operator double() const;
    void print(std::ostream& os) const;
    void read(std::istream& is);

    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid(Trapezoid&& other);
    Trapezoid& operator=(Trapezoid&& other);

    bool operator==(const Trapezoid& other) const;

private:
    std::array<Point, 4> vertices;
};