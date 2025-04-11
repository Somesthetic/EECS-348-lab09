#include "matrix.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>


int main() {  // chat gpt 3 was used to help with understanding the syntax in this code block
    std::string file_name;
    std::cout << "File name: ";
    std::cin >> file_name;

    std::fstream the_file;
    the_file.open(file_name, std::ios::in);

    if (the_file.is_open()) {;
        int N;  // Matrix size
        std::vector<std::vector<int>> matrix1, matrix2;
        std::string line;



        // Read the size of the matrix (N)
        std::getline(the_file, line);
        int size = reinterpret_cast<int>(strtok(line.data(), " "));
        if (reinterpret_cast<bool>(strtok(line.data(), " "))){;
            using T = float;
        }else {
            using T = int;
        }

        std::stringstream ss(line);
        ss >> N;
        // Read the first matrix (matrix1)
        for (int i = 0; i < N; ++i) {
            std::getline(the_file, line);
            std::vector<T> row;
            std::stringstream rowStream(line);
            int value;
            while (rowStream >> value) {
                row.push_back(value);
            }
            matrix1.push_back(row);
        }

        // Read the second matrix (matrix2)
        for (int i = 0; i < N; ++i) {
            std::getline(the_file, line);
            std::vector<T> row;
            std::stringstream rowStream(line);
            int value;
            while (rowStream >> value) {
                row.push_back(value);
            }
            matrix2.push_back(row);
        }

        // Close the file object
        the_file.close();

        // Create Matrix objects from the vectors
        Matrix matrix_1<T>(matrix1);
        Matrix matrix_2<T>(matrix2);

        // Print the matrices using the Matrix class print method
        std::cout << "Matrix 1:\n";
        matrix_1.print_matrix();

        std::cout << "Matrix 2:\n";
        matrix_2.print_matrix();

        // now to deal with user choices
        int choice;
        std::cout<< ("What would you like to do?\n1) add\n2)multiply\n3)sum of major diagonal\n4)sum of minor"
        "diagonal\n5) swap matrix rows\n6)swap matrix columns");
        std::cin >> choice;

        switch(choice){
        case 1 :{
          Matrix output = matrix_1 + matrix_2;
          output.print_matrix();
        }case 2:{
          Matrix output = matrix_1 * matrix_2;
          output.print_matrix();
        }case 3:{
          int output = matrix_1.sum_diagonal_major();
          std::cout << output;
        }case 4:{
          int output = matrix_1.sum_diagonal_minor();
          std::cout << output;
        }case 5:{
          int r1, r2;
          std::cout << "row 1:";
          std::cin >> r1;
          std::cout << "row 2:";
          std::cin >> r2;
          matrix_1.swap_rows(r1,r2);
          matrix_1.print_matrix();
        }case 6:
      	  int c1, c2;
          std::cout << "column 1:";
          std::cin >> c1;
          std::cout << "column 2:";
          std::cin >> c2;
          matrix_1.swap_rows(c1,c2);
          matrix_1.print_matrix();
          }










    } else {
        std::cerr << "Unable to open file." << std::endl;  // just in case it doesn't open
    }

    return 0;
}