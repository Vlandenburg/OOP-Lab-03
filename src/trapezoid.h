#pragma once
#include "figure.h"
#include <array>

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(const std::array<Point, 4>& vertices);

    Point calculateGeometricCenter() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    bool operator==(const Trapezoid& other) const;

private:
    std::array<Point, 4> vertices_;
};