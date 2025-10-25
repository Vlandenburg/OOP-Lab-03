#include <iostream>
#include <string>
#include "figure_array.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"

void print_menu() {
    std::cout << "\n--- Menu ---\n";
    std::cout << "1. Add Trapezoid\n";
    std::cout << "2. Add Rhombus\n";
    std::cout << "3. Add Pentagon\n";
    std::cout << "4. Print all figures info\n";
    std::cout << "5. Get total area\n";
    std::cout << "6. Delete figure by index\n";
    std::cout << "0. Exit\n";
    std::cout << "Your choice: ";
}

int main() {
    FigureArray figures;
    int choice = -1;

    while (choice != 0) {
        print_menu();
        std::cin >> choice;

        if (choice == 1) {
            Figure* new_figure = new Trapezoid();
            std::cout << "Enter 4 vertices for Trapezoid in (x,y) format:\n";
            std::cin >> *new_figure;
            figures.addFigure(new_figure);
        } else if (choice == 2) {
            Figure* new_figure = new Rhombus();
            std::cout << "Enter 4 vertices for Rhombus in (x,y) format:\n";
            std::cin >> *new_figure;
            figures.addFigure(new_figure);
        } else if (choice == 3) {
            Figure* new_figure = new Pentagon();
            std::cout << "Enter 5 vertices for Pentagon in (x,y) format:\n";
            std::cin >> *new_figure;
            figures.addFigure(new_figure);
        } else if (choice == 4) {
            if (figures.getSize() == 0) {
                std::cout << "Array is empty.\n";
            }
            for (size_t i = 0; i < figures.getSize(); ++i) {
                std::cout << "\n--- Figure " << i << " ---\n";
                std::cout << "Vertices: " << *figures.get(i) << '\n';
                Point center = figures.get(i)->calculateGeometricCenter();
                std::cout << "Center: " << center << '\n';
                std::cout << "Area: " << (double)(*figures.get(i)) << '\n';
            }
        } else if (choice == 5) {
            std::cout << "Total area: " << figures.calculateTotalArea() << '\n';
        } else if (choice == 6) {
            if (figures.getSize() == 0) {
                std::cout << "Array is empty.\n";
                continue;
            }
            size_t index;
            std::cout << "Enter index to delete: ";
            std::cin >> index;
            if (index >= figures.getSize()) {
                std::cout << "Error: invalid index.\n";
            } else {
                figures.removeFigure(index);
                std::cout << "Figure deleted.\n";
            }
        } else if (choice != 0) {
            std::cout << "Wrong command, try again.\n";
        }
    }

    std::cout << "Exiting.\n";
    return 0;
}