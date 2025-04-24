#include <iostream>

template<class m>
class Matrix{

    private: 

    int row;
    int col; 
    m* matrix; 

    public: 



    Matrix(int Rows, int Cols){
        rows = Rows;
        col = Cols;
        matrix = new m[rows * cols];
    };


    Matrix(int size){
        rows = size;
        col = size;
        matrix = new m[rows * cols];
    };

    ~Matrix(){
        delete matrix[];
    };


}