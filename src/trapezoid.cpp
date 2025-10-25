#include "trapezoid.h"
#include <cmath>
#include <numeric>

Trapezoid::Trapezoid(const std::array<Point, 4>& vertices) : vertices_(vertices) {}

Point Trapezoid::calculateGeometricCenter() const {
    Point center = {0.0, 0.0};
    for (int i = 0; i < 4; ++i) {
        center.x += vertices_[i].x;
        center.y += vertices_[i].y;
    }
    center.x /= 4;
    center.y /= 4;
    return center;
}

Trapezoid::operator double() const {
    double area = 0.0;
    for (int i = 0; i < 4; ++i) {
        Point p1 = vertices_[i];
        Point p2 = vertices_[(i + 1) % 4];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

void Trapezoid::print(std::ostream& os) const {
    for (int i = 0; i < 4; ++i) {
        os << vertices_[i] << " ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertices_[i];
    }
}

Trapezoid::Trapezoid(const Trapezoid& other) : vertices_(other.vertices_) {}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        vertices_ = other.vertices_;
    }
    return *this;
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept : vertices_(std::move(other.vertices_)) {}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        vertices_ = std::move(other.vertices_);
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    for(int i = 0; i < 4; ++i) {
        if (!(vertices_[i] == other.vertices_[i])) {
            return false;
        }
    }
    return true;
}