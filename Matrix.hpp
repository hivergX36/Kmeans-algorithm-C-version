#include <iostream>

template<class m>
class Matrix{

    private:

    int row;
    int col;
    m** matrix;

    public:



    Matrix(int Rows, int Cols){
        row = Rows;
        col = Cols;
        matrix = new m*[row];
        for(int i = 0;i < row; i++){
            matrix[i] = new m[col];
        }; 
    
    };


    Matrix(int size){
        row = size;
        col = size;
        matrix = new m*[row];
        for(int i = 0; i < row; i++){
            matrix[i] = new m[col];
        }
    };

    ~Matrix(){
        delete matrix;
    };


    void display_matrix(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    };

    void set_matrix_value(int i, int j, int value){
        matrix[i][j] = value;
    }

    void set_matrix_value(int i, int j, float value){
        matrix[i][j] = value;
    }

    void get_matrix_row(int i){
        float vector[col]
        for(int j = 0; j < col; j++){
            vector[j] = matrix[i][j];
        }
        return vector;
    };

};
