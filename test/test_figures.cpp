#include <gtest/gtest.h>
#include <sstream>
#include "../src/trapezoid.h"
#include "../src/rhombus.h"
#include "../src/pentagon.h"


TEST(TrapezoidTest, AreaAndCenter) {
    std::array<Point, 4> vertices = {{{0, 0}, {6, 0}, {6, 4}, {0, 4}}};
    Trapezoid t(vertices);
    
    EXPECT_DOUBLE_EQ(t.calculateArea(), 24.0);

    Point center = t.calculateGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 3.0);
    EXPECT_DOUBLE_EQ(center.y, 2.0);
}

TEST(RhombusTest, AreaAndCenter) {
    std::array<Point, 4> vertices = {{{-2, 0}, {0, 5}, {2, 0}, {0, -5}}};
    Rhombus r(vertices);

    EXPECT_DOUBLE_EQ(r.calculateArea(), 20.0);

    Point center = r.calculateGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

TEST(PentagonTest, OperatorIO) {
    std::array<Point, 5> vertices = {{{0,0}, {1,0}, {1,1}, {0.5, 1.5}, {0,1}}};
    Pentagon p1(vertices);
    
    std::stringstream ss;
    ss << p1;
    
    Pentagon p2;
    ss >> p2;

    ASSERT_TRUE(p1 == p2);
}