#pragma once
#include "figure.h"
#include <cstddef>
#include <stdexcept>

class FigureArray {
public:
    FigureArray() {
        size_ = 0;
        capacity_ = 10;
        data_ = new Figure*[capacity_];
    }

    ~FigureArray() {
        for (size_t i = 0; i < size_; ++i) {
            delete data_[i];
        }
        delete[] data_;
    }

    void addFigure(Figure* fig) {
        if (size_ == capacity_) {
            capacity_ *= 2;
            Figure** new_data = new Figure*[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
        }
        data_[size_++] = fig;
    }

    void removeFigure(size_t index) {
        if (index >= size_) {
            return;
        }
        delete data_[index];
        for (size_t i = index; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    size_t getSize() const {
        return size_;
    }

    Figure* get(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    double calculateTotalArea() const {
        double total = 0.0;
        for (size_t i = 0; i < size_; ++i) {
            total += (double)(*data_[i]);
        }
        return total;
    }

private:
    Figure** data_;
    size_t size_;
    size_t capacity_;

    FigureArray(const FigureArray&) = delete;
    FigureArray& operator=(const FigureArray&) = delete;
};