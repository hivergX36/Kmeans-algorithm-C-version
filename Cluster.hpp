#include<vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <algorithm>

// Réfléchir sur le cluster 
struct Cluster{

int sizeofcentroid;
    int numberBelongingPoint;
    float intra_inertia;
    float * centroid_coordinate;
    std::vector<std::vector<float>>* belongingPoints;


   


    Cluster(int sizeofcentroid){
        numberBelongingPoint = 0;
        centroid_coordinate =  new float[sizeofcentroid];
        belongingPoints = new std::vector<std::vector<float>>;


    


  

    }














};
