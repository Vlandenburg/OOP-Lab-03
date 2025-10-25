#include "rhombus.h"

Rhombus::Rhombus() {}
Rhombus::Rhombus(const std::array<Point, 4>& vertices) {
    this->vertices = vertices;
}

Point Rhombus::calculateGeometricCenter() const {
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < 4; ++i) {
        sum_x += vertices[i].x;
        sum_y += vertices[i].y;
    }
    return {sum_x / 4, sum_y / 4};
}

double Rhombus::calculateArea() const {
    double area = 0.0;
    for (int i = 0; i < 4; ++i) {
        Point p1 = vertices[i];
        Point p2 = vertices[(i + 1) % 4];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

Rhombus::operator double() const {
    return calculateArea();
}

void Rhombus::print(std::ostream& os) const {
    for (int i = 0; i < 4; ++i) {
        os << vertices[i] << " ";
    }
}

void Rhombus::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertices[i];
    }
}

Rhombus::Rhombus(const Rhombus& other) {
    vertices = other.vertices;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this == &other) {
        return *this;
    }
    vertices = other.vertices;
    return *this;
}

Rhombus::Rhombus(Rhombus&& other) {
    vertices = std::move(other.vertices);
}

Rhombus& Rhombus::operator=(Rhombus&& other) {
    if (this == &other) {
        return *this;
    }
    vertices = std::move(other.vertices);
    return *this;
}

bool Rhombus::operator==(const Rhombus& other) const {
    for(int i = 0; i < 4; ++i) {
        if (!(vertices[i] == other.vertices[i])) {
            return false;
        }
    }
    return true;
}