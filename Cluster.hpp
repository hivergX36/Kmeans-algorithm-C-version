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

   


    Cluster(int numberClusterIndex, int numberFeature){
        indexCluster = numberClusterIndex;
        numberBelongingPoint = 0;
        belongingPoints = new std::vector<float>[numberFeature];
  

    }














};
