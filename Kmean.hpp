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

    std::vector<Cluster> *Centroids;
    std::vector<float> * data_inertia;
    float *pedictor[][]; 

  

}