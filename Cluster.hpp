#include<vector> 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>  
#include <algorithm>


struct Cluster{

    int indexCluster;
    int numberBelongingPoint;
    std::vector<float> * belongingPoints;
    float intra_inertia; 
    std::vector<float> * centroid_coordinate;

   


    Cluster(int numberClusterIndex, int numberFeature, int sizeofcentroid){
        indexCluster = numberClusterIndex;
        numberBelongingPoint = 0;
        belongingPoints = new std::vector<float>[numberFeature];
        centroid_coordinate =  new std::vector<float>[1];
  

    }














};
