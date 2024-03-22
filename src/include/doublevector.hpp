#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class DoubleVector {
private:
  T* matrix_;
  int width_;
  int height_;
  bool isEmpty;

public:
  DoubleVector();
  DoubleVector(int w, int h);
  ~DoubleVector();

  int width();
  int height();

  bool coordinateInRange(int x, int y);
  void set(int x, int y, T value);
  T* get(int x, int y);
  string print();
};

template <typename T>
int DoubleVector<T>::width() {
  return width_;
}

template <typename T>
int DoubleVector<T>::height() {
  return height_;
}

template <typename T>
DoubleVector<T>::DoubleVector() {
  width_ = 0;
  height_ = 0;
  isEmpty = true;

  matrix_ = new T[width_ * height_];
}

template <typename T>
DoubleVector<T>::DoubleVector(int w, int h) {
  width_ = w;
  height_ = h;
  isEmpty = true;

  matrix_ = new T[width_ * height_];
}

template <typename T>
DoubleVector<T>::~DoubleVector() {
  // delete[] matrix_;
}

template <typename T>
bool DoubleVector<T>::coordinateInRange(int x, int y) {
  return (x >= 0 && x < width_) && (y >= 0 && y < height_);
}

template <typename T>
void DoubleVector<T>::set(int x, int y, T value) {
  if (!coordinateInRange(x, y)) {
    throw std::out_of_range("Cannot get a value from an empty list");
  }

  matrix_[width_ * x + y] = value;
}

template <typename T>
T* DoubleVector<T>::get(int x, int y) {
  if (!coordinateInRange(x, y)) {
    throw std::out_of_range("Cannot get a value from an empty list");
  }
  return &matrix_[width_ * x + y];
}

#endif
