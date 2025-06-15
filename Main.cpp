#include "iostream"
#include "Matrix.hpp"

int main() {
    // Example usage of Matrix
    Matrix<float> mat(3, 3);

    mat.set_matrix_value(1,2,1);
    mat.set_matrix_value(0,0,3);  

    mat.display_matrix();

}