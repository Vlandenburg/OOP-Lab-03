#include "trapezoid.h"

Trapezoid::Trapezoid() {}
Trapezoid::Trapezoid(const std::array<Point, 4>& vertices) {
    this->vertices = vertices;
}

Point Trapezoid::calculateGeometricCenter() const {
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < 4; ++i) {
        sum_x += vertices[i].x;
        sum_y += vertices[i].y;
    }
    return {sum_x / 4, sum_y / 4};
}

double Trapezoid::calculateArea() const {
    double area = 0.0;
    for (int i = 0; i < 4; ++i) {
        Point p1 = vertices[i];
        Point p2 = vertices[(i + 1) % 4];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

Trapezoid::operator double() const {
    return calculateArea();
}

void Trapezoid::print(std::ostream& os) const {
    for (int i = 0; i < 4; ++i) {
        os << vertices[i] << " ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertices[i];
    }
}

Trapezoid::Trapezoid(const Trapezoid& other) {
    vertices = other.vertices;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this == &other) {
        return *this;
    }
    vertices = other.vertices;
    return *this;
}

Trapezoid::Trapezoid(Trapezoid&& other) {
    vertices = std::move(other.vertices);
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) {
    if (this == &other) {
        return *this;
    }
    vertices = std::move(other.vertices);
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    for(int i = 0; i < 4; ++i) {
        if (!(vertices[i] == other.vertices[i])) {
            return false;
        }
    }
    return true;
}