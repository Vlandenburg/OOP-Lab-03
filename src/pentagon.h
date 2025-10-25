#pragma once
#include "figure.h"
#include <array>

class Pentagon : public Figure {
public:
    Pentagon() = default;
    Pentagon(const std::array<Point, 5>& vertices);

    Point calculateGeometricCenter() const override;
    operator double() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Pentagon(const Pentagon& other);
    Pentagon& operator=(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;
    Pentagon& operator=(Pentagon&& other) noexcept;

    bool operator==(const Pentagon& other) const;

private:
    std::array<Point, 5> vertices_{};
};