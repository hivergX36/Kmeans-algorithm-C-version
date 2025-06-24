#include<vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include "Cluster.hpp"
#include "Matrix.hpp"


class Kmean{

    public class:

    int nbMatrixrows;
    int nbMatrixcols;
    int numberFeature;
    int featureSize;
    int numberOfCluster;
    float min;
    float max; 
    Cluster* Centroids;
    std::vector<float> * sum_cluster_intra_inertia;
    Matrix<float>* predictor;
    bool stop; 

    Kmean(int nbCluster, std::string filename){
        nbMatrixrows = 0;
        nbMatrixcols = 0;
        numberFeature = 0;
        max = 0;
        min = 2147483627; 
        numberOfCluster = nbCluster;
        predictor = nullptr;
        sum_cluster_intra_inertia = new std::vector<float>;
        Centroids = nullptr;
        stop = false; 

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
            featureSize = nbMatrixrows;
            numberFeature = featureSize; 


            predictor = new Matrix<float>(nbMatrixrows, nbMatrixcols);
            for (int i = 0; i < nbMatrixrows; ++i) {
                for (int j = 0; j < nbMatrixcols; ++j) {
                
                    float value;
                    file >> value;
                    predictor->set_matrix_value(i, j, value);
                    if value < min) {
                        min = value;
                    }
                    if (value > max) {
                        max = value;
                    }
                }
            }
;

            file.close();



        }
    

        std::cout << "Les caractéristiques du problèmes sont: " << std::endl;
        std::cout << "Nombre de lignes: " << nbMatrixrows << std::endl;
        std::cout << "Nombre de colonnes: " << nbMatrixcols << std::endl;
        std::cout << "Le nombre de features est: " << numberFeature << std::endl;
        std::cout << "Le nombre de cluster est: " << nbMatrixcols << std::endl;
        std::cout << "La matrice de données est: " << std::endl;
        predictor ->display_matrix();


    }


    void normalize_data(){
        /* Normalize the data in the matrix to a range of [0, 1] */
        for (int i = 0; i < nbMatrixrows; ++i) {
            for (int j = 0; j < nbMatrixcols; ++j) {
                float value = predictor->get_matrix_value(i, j);
                float normalized_value = (value - min) / (max - min);
                predictor->set_matrix_value(i, j, normalized_value);
            }
        }
    }
    void denormalize_data(){
        /* Denormalize data to return in the normal range */
        for (int i = 0; i < nbMatrixrows; ++i) {
            for (int j = 0; j < nbMatrixcols; ++j) {
                float value = predictor->get_matrix_value(i, j);
                float denormalized_value = value * (max - min) + min;
                predictor->set_matrix_value(i, j, denormalized_value);
            }
        }
    }

    void generate_random_centroids(){
        Centroids = new Cluster[numberOfCluster];
        for (int i = 0; i < numberOfCluster; ++i) {
            Centroids[i] = Cluster(featureSize);
            for (int j = 0; j < featureSize; ++j) {
                Centroids[i].centroid_coordinate[j] = (double)std::rand() / (double)RAND_MAX;;
            }
        }
    }

    void calculate_and_assign(){
        int min_index = 0;
        float min_distance = 0.0;
        for (int i = 0; i < nbMatrixrows; ++i) {
            for (int j = 0; j < numberOfCluster; ++j) {
                float distance = 0.0;
                for (int k = 0; k < featureSize; ++k) {
                    distance += pow(predictor->get_matrix_value(i, k) - Centroids[j].centroid_coordinate[k], 2);
                }
                distance = sqrt(distance);
                if (j == 0 || distance < min_distance) {
                    min_distance = distance;
                    min_index = j;
                }
            }
            Centroids[min_index].belongingPoints->push_back(predictor->get_row(i));
    }


    void calculate_centroid_intra_inertia(){
        for (int i = 0; i < numberOfCluster; i++) {
            Centroids[i].intra_inertia = 0.0;
            for (const auto &point : *Centroids[i].belongingPoints) {
                float distance = 0.0;
                for (int j = 0; j < featureSize; j++) {
                    distance += pow(point[j] - Centroids[i].centroid_coordinate[j], 2);
                }
                distance = sqrt(distance);
                Centroids[i].intra_inertia += distance;
            }
        }
    }

    void update_centroids(){
        for (int i = 0; i < numberOfCluster; i++) {
            if (Centroids[i].belongingPoints->size() < 1) continue; // Skip empty clusters
            for (int j = 0; j < featureSize; j++) {
                float coord_j = 0.0;
                for (const auto &point : *Centroids[i].belongingPoints) {
                    coord_j += point[j];
                }
                Centroids[i].centroid_coordinate[j] = coord_j / Centroids[i].belongingPoints->size();
            }
        }
    }

    void update_clusters(){
        for (int i = 0; i < numberOfCluster; i++) {
            Centroids[i].belongingPoints->clear();
            Centroids[i].numberBelongingPoint = 0;
        }
    }

    void update_inertia(){
        float sum = 0.0;
        for (int i = 0; i < numberOfCluster; i++) {
            sum += Centroids[i].intra_inertia;
        }
        sum_cluster_intra_inertia->push_back(sum);
    }


    void stopping_criteria(float epsilon, int number_iterations, int max_iterations){
        if(number_iterations >= max_iterations){
            std::cout << "Maximum number of iterations reached." << std::endl;
            return true;
        }
        if(sum_cluster_intra_inertia->size() < 2){
            std::cout << "Not enough data to calculate stopping criteria." << std::endl;
            return false;
        }

        if(fabs((*sum_cluster_intra_inertia)[sum_cluster_intra_inertia->size() - 1] - (*sum_cluster_intra_inertia)[sum_cluster_intra_inertia->size() - 2]) < epsilon){
            std::cout << "Stopping criteria met." << std::endl;
            return true;
        }

        return false;





        
    }


    void run_kmeans(float epsilon, int max_iterations){
        int number_iterations = 0;
        generate_random_centroids();
        while(!stop){
            update_clusters();
            calculate_and_assign();
            calculate_centroid_intra_inertia();
            update_centroids();
            update_inertia();
            stop = stopping_criteria(epsilon, number_iterations, max_iterations);
            number_iterations++;
        }
        denormalize_data();
    }




}


};