#include "pentagon.h"
#include <cmath>
#include <numeric>

Pentagon::Pentagon(const std::array<Point, 5>& vertices) : vertices_(vertices) {}

Point Pentagon::calculateGeometricCenter() const {
    Point center = {0.0, 0.0};
    for (int i = 0; i < 5; ++i) {
        center.x += vertices_[i].x;
        center.y += vertices_[i].y;
    }
    center.x /= 5;
    center.y /= 5;
    return center;
}

Pentagon::operator double() const {
    double area = 0.0;
    for (int i = 0; i < 5; ++i) {
        Point p1 = vertices_[i];
        Point p2 = vertices_[(i + 1) % 5];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

void Pentagon::print(std::ostream& os) const {
    for (int i = 0; i < 5; ++i) {
        os << vertices_[i] << " ";
    }
}

void Pentagon::read(std::istream& is) {
    for (int i = 0; i < 5; ++i) {
        is >> vertices_[i];
    }
}

Pentagon::Pentagon(const Pentagon& other) : vertices_(other.vertices_) {}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        vertices_ = other.vertices_;
    }
    return *this;
}

Pentagon::Pentagon(Pentagon&& other) noexcept : vertices_(std::move(other.vertices_)) {}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        vertices_ = std::move(other.vertices_);
    }
    return *this;
}

bool Pentagon::operator==(const Pentagon& other) const {
    for(int i = 0; i < 5; ++i) {
        if (!(vertices_[i] == other.vertices_[i])) {
            return false;
        }
    }
    return true;
}