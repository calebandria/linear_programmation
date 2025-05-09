#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m = 8;
    int n = 4;

    std::vector<std::vector<float>> standard_form = {
        {6,3,-1,0,0,0,-1,0},
        {2,2,-1,1,0,0,0,10},
        {3,-2,2,0,1,0,0,10},
        {4,-3,1,0,0,1,0,10}
    };

    return 0;
}

void display(std::vector<std::vector<float>> matrix) {
    for(const auto& inner_vector: matrix){
        for(float value : inner_vector){
            cout << value << " ";
        }
        cout << endl;
    }
}