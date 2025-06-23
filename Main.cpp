#include "iostream"
#include "vector"
int main() {
    // Example usage of Matrix
    int b[5];
    std::vector<int>* belongingPoints;
    belongingPoints = new std::vector<int>;
    belongingPoints->push_back(1);
    belongingPoints->push_back(2);
    belongingPoints->push_back(3);




    for(auto &value: *belongingPoints){
        std::cout << value << " "; // Print the values in the array
    };
   
    // Generate a random number between 0 and RAND_MAX
    // Cast to double for better precision in the output

  


    std::cout << b << std::endl;



    return 0;


}