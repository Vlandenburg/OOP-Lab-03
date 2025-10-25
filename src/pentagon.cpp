#include "pentagon.h"

Pentagon::Pentagon() {}
Pentagon::Pentagon(const std::array<Point, 5>& vertices) {
    this->vertices = vertices;
}

Point Pentagon::calculateGeometricCenter() const {
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < 5; ++i) {
        sum_x += vertices[i].x;
        sum_y += vertices[i].y;
    }
    return {sum_x / 5, sum_y / 5};
}

double Pentagon::calculateArea() const {
    double area = 0.0;
    for (int i = 0; i < 5; ++i) {
        Point p1 = vertices[i];
        Point p2 = vertices[(i + 1) % 5];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
}

Pentagon::operator double() const {
    return calculateArea();
}

void Pentagon::print(std::ostream& os) const {
    for (int i = 0; i < 5; ++i) {
        os << vertices[i] << " ";
    }
}

void Pentagon::read(std::istream& is) {
    for (int i = 0; i < 5; ++i) {
        is >> vertices[i];
    }
}

Pentagon::Pentagon(const Pentagon& other) {
    vertices = other.vertices;
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this == &other) {
        return *this;
    }
    vertices = other.vertices;
    return *this;
}

Pentagon::Pentagon(Pentagon&& other) {
    vertices = std::move(other.vertices);
}

Pentagon& Pentagon::operator=(Pentagon&& other) {
    if (this == &other) {
        return *this;
    }
    vertices = std::move(other.vertices);
    return *this;
}

bool Pentagon::operator==(const Pentagon& other) const {
    for(int i = 0; i < 5; ++i) {
        if (!(vertices[i] == other.vertices[i])) {
            return false;
        }
    }
    return true;
}