#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

template <class T>
class Matrix {
public:
    Matrix(int N);  // will run this if the input is a int
    Matrix(std::vector<std::vector<T>> nums);  // will run this if input is a vector of vectors of ints
    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(int i, int j, T n);
    T get_value(int i, int j) const;
    int get_size() const;
    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;
    void swap_rows(int r1, int r2);
    void swap_cols(int c1, int c2);
    void print_matrix() const;
private:
  std::vector<std::vector<T>> the_data;  // defines a private member variable, aka the vector of vectors of ints
  int size;  // defines a private member variable, size
};

#endif // __MATRIX_HPP__