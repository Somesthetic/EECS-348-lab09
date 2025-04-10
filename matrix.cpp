#include "matrix.hpp"
#include <iostream>
#include <vector>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:
template <class T>
Matrix<T>::Matrix(int N) {
  for (int row = 0; row <= size-1; row++){
    std::vector<int> new_row;
    for (int column = 0; column <= size-1; column++){
      new_row.push_back(0);  // adds zero to the end of the column
    }
    the_data.push_back(new_row);
  }
}

template <class T>
Matrix<T>::Matrix(std::vector<std::vector<T>> nums){;
  size = nums.size();
  for (int row = 0; row <= size-1; row++){
    std::vector<T> new_row;
    for (int column = 0; column <= size-1; column++){
      new_row.push_back(nums[row][column]);  // adds individual value to end of column
    }
    the_data.push_back(new_row);
  }
}
template <class T>
void Matrix<T>::print_matrix() const {
    for (int row = 0; row< size-1; row++){
      for (int column = 0; column < size-1; column++){
        std::cout<< the_data[row][column]<< " ";  // prints each value in the column, followed by a space
      }
      std::cout<< "\n";  // makes a new line after everything in the column is printed
    }
}

template <class T>
int Matrix<T>::get_size() const{
  return size;  // Used to still have access to size without making it public
}

template <class T>
T Matrix<T>::get_value(int i, int j) const{;
  return the_data[i][j];
}

template <class T>
void Matrix<T>::set_value(int i, int j, T n){;
  the_data[i][j] = n;  // returns val at that coord
  return;
}

template <class T>
Matrix<T> Matrix<T>::operator + (const Matrix &rhs) const{;
  Matrix<T> output(size);  // Makes sure the output is always a float
  for (int i = 0; i <= size-1; i++){;
    for (int j = 0; j <= size-1; j++){;
      output.set_value(i,j, get_value(i,j) + rhs.get_value(i,j));
    }
  }
  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const{;
  Matrix<T> output(size);
  for (int i = 0; i < size; i++) {           // Iterate over rows of mat1
    for (int j = 0; j < size; j++) {       // Iterate over columns of mat2
      for (int k = 0; k < size; k++) {   // Iterate over row elements of mat1 and column elements of mat2
         output.set_value(i,j,(get_value(i,j) * rhs.get_value(j,i))+output.get_value(i,j));
      }
    }
  }
  return output;
}

template <class T>
T Matrix<T>::sum_diagonal_major() const{;
  int sum = 0;
  for (int i = 0; i < size; i++){;
    sum += get_value(i,i);
  }
  return sum;
}

template <class T>
T Matrix<T>::sum_diagonal_minor() const{;
  int sum = 0;
  for (int i = 0; i < size; i++){;
    sum += get_value(i,size-1-i);
  }
  return sum;
}

template <class T>
void Matrix<T>::swap_rows(int r1, int r2){;
  std::vector temp_row = the_data[r1];
  for (int j = 0; j < size; j++){;
    set_value(r1, j, the_data[r2][j]);  // setting the r1 variables
  } for (int j = 0; j < size; j++){;
    set_value(r2, j, temp_row[j]);
  }
}

template <class T>
void Matrix<T>::swap_cols(int c1, int c2){;
  std::vector<T> temp_column;
  for (int i = 0; i < size; i++){;
    temp_column[i] = get_value(i, c1);  // get the value about to be deleted
    set_value(i, c1, get_value(i, c2));  // replaces the c1 value
    set_value(i, c2, temp_column[i]);  // replaces the c2 value with the c1 one
  }
}