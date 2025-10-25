#pragma once
#include "figure.h"
#include <cstddef>

class FigureArray {
public:
    FigureArray() {
        count = 0;
        capacity = 8;
        arr = new Figure*[capacity];
    }

    ~FigureArray() {
        for (size_t i = 0; i < count; ++i) {
            delete arr[i];
        }
        delete[] arr;
    }

    void add(Figure* fig) {
        if (count == capacity) {
            size_t new_capacity = capacity * 2;
            Figure** new_arr = new Figure*[new_capacity];
            for (size_t i = 0; i < count; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            capacity = new_capacity;
        }
        arr[count] = fig;
        count++;
    }

    void remove(size_t index) {
        if (index >= count) {
            return;
        }
        delete arr[index];
        for (size_t i = index; i < count - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    size_t size() const {
        return count;
    }

    Figure* get(size_t index) const {
        if (index >= count) {
            return nullptr;
        }
        return arr[index];
    }

private:
    Figure** arr;
    size_t count;
    size_t capacity;

    FigureArray(const FigureArray&) = delete;
    FigureArray& operator=(const FigureArray&) = delete;
};