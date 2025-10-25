#pragma once
#include "figure.h"
#include <array>

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(const std::array<Point, 5>& vertices);

    Point calculateGeometricCenter() const;
    double calculateArea() const;
    operator double() const;
    void print(std::ostream& os) const;
    void read(std::istream& is);

    Pentagon(const Pentagon& other);
    Pentagon& operator=(const Pentagon& other);
    Pentagon(Pentagon&& other);
    Pentagon& operator=(Pentagon&& other);

    bool operator==(const Pentagon& other) const;

private:
    std::array<Point, 5> vertices;
};