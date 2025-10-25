#include "rhombus.h"
#include <cmath>
#include <numeric>

Rhombus::Rhombus(const std::array<Point, 4>& vertices) : vertices_(vertices) {}

Point Rhombus::calculateGeometricCenter() const {
    Point center = {0.0, 0.0};
    for (int i = 0; i < 4; ++i) {
        center.x += vertices_[i].x;
        center.y += vertices_[i].y;
    }
    center.x /= 4;
    center.y /= 4;
    return center;
}

Rhombus::operator double() const {
    double area = 0.0;
    for (int i = 0; i < 4; ++i) {
        Point p1 = vertices_[i];
        Point p2 = vertices_[(i + 1) % 4];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

void Rhombus::print(std::ostream& os) const {
    for (int i = 0; i < 4; ++i) {
        os << vertices_[i] << " ";
    }
}

void Rhombus::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertices_[i];
    }
}

Rhombus::Rhombus(const Rhombus& other) : vertices_(other.vertices_) {}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        vertices_ = other.vertices_;
    }
    return *this;
}

Rhombus::Rhombus(Rhombus&& other) noexcept : vertices_(std::move(other.vertices_)) {}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        vertices_ = std::move(other.vertices_);
    }
    return *this;
}

bool Rhombus::operator==(const Rhombus& other) const {
    for(int i = 0; i < 4; ++i) {
        if (!(vertices_[i] == other.vertices_[i])) {
            return false;
        }
    }
    return true;
}