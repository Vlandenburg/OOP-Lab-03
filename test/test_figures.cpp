#include <gtest/gtest.h>
#include <sstream>
#include "../src/trapezoid.h"
#include "../src/rhombus.h"
#include "../src/pentagon.h"

// --- Тесты для класса Trapezoid ---

TEST(TrapezoidTest, AreaAndCenter) {
    // Прямоугольник - частный случай трапеции, его легко посчитать
    std::array<Point, 4> vertices = {{{0, 0}, {6, 0}, {6, 4}, {0, 4}}};
    Trapezoid t(vertices);

    // Проверяем площадь
    EXPECT_DOUBLE_EQ(static_cast<double>(t), 24.0);

    // Проверяем геометрический центр
    Point center = t.calculateGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 3.0);
    EXPECT_DOUBLE_EQ(center.y, 2.0);
}

TEST(TrapezoidTest, CopyAndComparison) {
    std::array<Point, 4> vertices1 = {{{0, 0}, {6, 0}, {6, 4}, {0, 4}}};
    Trapezoid t1(vertices1);
    Trapezoid t2(t1); // Тест конструктора копирования

    ASSERT_TRUE(t1 == t2);

    std::array<Point, 4> vertices2 = {{{1, 1}, {2, 1}, {2, 2}, {1, 2}}};
    Trapezoid t3(vertices2);
    
    ASSERT_FALSE(t1 == t3);

    t3 = t1; // Тест оператора присваивания
    ASSERT_TRUE(t1 == t3);
}

// --- Тесты для класса Rhombus ---

TEST(RhombusTest, AreaAndCenter) {
    // Ромб с вершинами на осях координат
    std::array<Point, 4> vertices = {{{-2, 0}, {0, 5}, {2, 0}, {0, -5}}};
    Rhombus r(vertices);

    // Диагонали равны 4 и 10. Площадь = (4 * 10) / 2 = 20
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 20.0);

    // Центр должен быть в начале координат
    Point center = r.calculateGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 0.0);
}

// --- Тесты для класса Pentagon ---

TEST(PentagonTest, AreaAndCenter) {
    // Фигура "домик"
    std::array<Point, 5> vertices = {{{0, 0}, {4, 0}, {4, 2}, {2, 4}, {0, 2}}};
    Pentagon p(vertices);

    // Площадь = прямоугольник (4*2) + треугольник (4*2/2) = 8 + 4 = 12
    EXPECT_DOUBLE_EQ(static_cast<double>(p), 12.0);

    // Центр
    Point center = p.calculateGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 2.0); // (0+4+4+2+0)/5
    EXPECT_DOUBLE_EQ(center.y, 1.6); // (0+0+2+4+2)/5
}

TEST(PentagonTest, OperatorIO) {
    std::array<Point, 5> vertices = {{{0,0}, {1,0}, {1,1}, {0.5, 1.5}, {0,1}}};
    Pentagon p1(vertices);
    
    std::stringstream ss;
    ss << p1; // Записываем в поток только координаты
    
    Pentagon p2;
    ss >> p2; // Считываем из потока

    // Теперь p1 и p2 должны быть идентичны
    ASSERT_TRUE(p1 == p2);
}