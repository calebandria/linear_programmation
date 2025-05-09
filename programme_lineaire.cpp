#include <iostream>
#include <vector>

using namespace std;
void display(vector<vector<float>> matrix);
void gettingThePivot(vector<vector<float>> matrix);
int main(){
    int m = 8;
    int n = 4;

    vector<vector<float>> standard_form = {
        {6,3,-1,0,0,0,-1,0},
        {2,2,-1,1,0,0,0,10},
        {3,-2,2,0,1,0,0,10},
        {4,-3,1,0,0,1,0,10}
    };
    // choosing the pivot

    //display(standard_form);
    gettingThePivot(standard_form);
    return 0;
}

void display(vector<vector<float>> matrix) {
    for(const auto& inner_vector: matrix){
        for(float value : inner_vector){
            cout << value << " ";
        }
        cout << endl;
    }
}

void gettingThePivot(vector<vector<float>> matrix){   
    
    vector<vector<float>>::iterator it1;
    vector<float>::iterator it2;
    vector<vector<float>>::iterator z = matrix.begin();
    int crosserRow = 0;
    int crosserCol = 0;
    int pivotRow = 0;
    int pivotCol = 0;
    int pivotFilter = 0;
    float b = 0.0;
    float possiblePivot = 0.0;
    float chosenPivot = 0.0;
    float division = 0.0;

    for(it1 = matrix.begin()+1; it1 != matrix.end(); it1++){
        crosserCol = 0;
        for(it2 = (*it1).begin(); it2 != (*it1).end(); it2++){
            b = *((*it1).end()-1);
            division = (*it2)/b;
            if((*z)[crosserCol] > 0){
                if (division > 0){
                    if(pivotFilter == 0) 
                        chosenPivot = division;
                    possiblePivot = division;
                    pivotFilter++;

                }
                if (possiblePivot <= chosenPivot){
                    chosenPivot = possiblePivot;
                    cout << "Element at" << "[" << crosserRow << "]" << "[" << crosserCol << "]" << endl;
                }
            }
            crosserCol ++;
        }
        crosserRow++;
    }

}