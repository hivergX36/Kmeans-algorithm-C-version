#include<vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include "Cluster.hpp"
#include "Matrix.hpp"


struct Kmean{

    int nbMatrixrows;
    int nbMatrixcols;
    int numberFeature;

    Cluster *Centroids;
    std::vector<float> * data_inertia;
    Matrix<float>* pedictor;

    Kmean(int numberOfCluster, int numberFeature,std::string filename){
        nbMatrixrows = 0;
        nbMatrixcols = 0;
        pedictor = nullptr;
        data_inertia = nullptr;
        Centroids = nullptr;

    }

    void set_number_of_feature(int numberFeature){
        this->numberFeature = numberFeature;
    }



    void parse_data(std::string filename){
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        else{
            file >> nbMatrixrows;
            file >> nbMatrixcols;
            std::cout << "Les caractéristiques du problèmes sont: " << std::endl;
            std::cout << "Nombre de lignes: " << nbMatrixrows << std::endl;
            std::cout << "Nombre de colonnes: " << nbMatrixcols << std::endl;

            pedictor = new Matrix<float>(nbMatrixrows, nbMatrixcols);
            for (int i = 0; i < nbMatrixrows; ++i) {
                for (int j = 0; j < nbMatrixcols; ++j) {
                    float value;
                    file >> value;
                    pedictor->set_matrix_value(i, j, value);
                }
            }



        }


    }

};