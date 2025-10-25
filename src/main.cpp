#include <iostream>
#include "figure_array.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"

void print_menu() {
    std::cout << "\n--- Menu ---\n";
    std::cout << "1. Add Trapezoid\n";
    std::cout << "2. Add Rhombus\n";
    std::cout << "3. Add Pentagon\n";
    std::cout << "4. Show all figures\n";
    std::cout << "5. Calculate total area\n";
    std::cout << "6. Delete a figure\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    FigureArray figures;
    int command = -1;
    bool is_running = true;

    while (is_running) {
        print_menu();
        std::cin >> command;

        if (command == 1) {
            Figure* new_fig = new Trapezoid();
            std::cout << "Enter 4 vertices for the Trapezoid in (x,y) format:\n";
            std::cin >> *new_fig;
            figures.add(new_fig);
        } else if (command == 2) {
            Figure* new_fig = new Rhombus();
            std::cout << "Enter 4 vertices for the Rhombus in (x,y) format:\n";
            std::cin >> *new_fig;
            figures.add(new_fig);
        } else if (command == 3) {
            Figure* new_fig = new Pentagon();
            std::cout << "Enter 5 vertices for the Pentagon in (x,y) format:\n";
            std::cin >> *new_fig;
            figures.add(new_fig);
        } else if (command == 4) {
            std::cout << "\n--- List of Figures ---\n";
            if (figures.size() == 0) {
                std::cout << "The list is empty.\n";
            }
            for (size_t i = 0; i < figures.size(); ++i) {
                Figure* fig = figures.get(i);
                std::cout << "Figure #" << i << std::endl;
                std::cout << "  Vertices: " << *fig << std::endl;
                std::cout << "  Center: " << fig->calculateGeometricCenter() << std::endl;
                std::cout << "  Area: " << (double)(*fig) << std::endl;
            }
        } else if (command == 5) {
            double total_area = 0;
            for (size_t i = 0; i < figures.size(); ++i) {
                total_area += (double)(*figures.get(i));
            }
            std::cout << "Total area of all figures: " << total_area << std::endl;
        } else if (command == 6) {
            size_t index;
            std::cout << "Enter figure index to delete: ";
            std::cin >> index;
            if (index < figures.size()) {
                figures.remove(index);
                std::cout << "Figure was deleted.\n";
            } else {
                std::cout << "Invalid index.\n";
            }
        } else if (command == 0) {
            is_running = false;
        } else {
            std::cout << "Unknown command.\n";
        }
    }

    std::cout << "Exiting program.\n";
    return 0;
}