#pragma once
#include "figure.h"
#include <array>

class Rhombus : public Figure {
public:
    Rhombus() = default;
    Rhombus(const std::array<Point, 4>& vertices);

    Point calculateGeometricCenter() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Rhombus(const Rhombus& other);
    Rhombus& operator=(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(Rhombus&& other) noexcept;

    bool operator==(const Rhombus& other) const;

private:
    std::array<Point, 4> vertices_{};
};