#pragma once
#include "figure.h"
#include <array>

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(const std::array<Point, 4>& vertices);

    Point calculateGeometricCenter() const;
    double calculateArea() const;
    operator double() const;
    void print(std::ostream& os) const;
    void read(std::istream& is);

    Rhombus(const Rhombus& other);
    Rhombus& operator=(const Rhombus& other);
    Rhombus(Rhombus&& other);
    Rhombus& operator=(Rhombus&& other);

    bool operator==(const Rhombus& other) const;

private:
    std::array<Point, 4> vertices;
};