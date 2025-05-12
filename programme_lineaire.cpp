#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
void display(vector<vector<int>> matrix);
vector<int> gettingThePivot(vector<vector<int>> matrix);
vector<vector<int>> newMatrix(vector<int> pivot, vector<vector<int>> matrix);
int max(int x, int y);
long long lcm(int x, int y);

int main()
{
    int m = 8;
    int n = 4;

    vector<vector<int>> standard_form = {
        {6, 3, -1, 0, 0, 0, -1, 0},
        {2, 2, -1, 1, 0, 0, 0, 10},
        {3, -2, 2, 0, 1, 0, 0, 10},
        {4, -3, 1, 0, 0, 1, 0, 10}};
    // choosing the pivot
    cout << "Original" << endl;
    display(standard_form);
    vector<int> pivot = gettingThePivot(standard_form);

    vector<vector<int>> secondMatrix = newMatrix(pivot, standard_form);

    cout << "First" << endl;
    display(secondMatrix);
    
    
    vector<int> pivot2 = gettingThePivot(secondMatrix);
    vector<vector<int>> thirdMatrix = newMatrix(pivot2, secondMatrix);

    cout << "Second" << endl;
    display(thirdMatrix);
    
    vector<int> pivot3 = gettingThePivot(thirdMatrix);
    vector<vector<int>> fourthMatrix = newMatrix(pivot3, thirdMatrix);

    cout << "Third" << endl;
    display(fourthMatrix);

    //cout << lcm(4,3) << endl;
    

    
    return 0;
}

void display(vector<vector<int>> matrix)
{
    for (const auto &inner_vector : matrix)
    {
        for (int value : inner_vector)
        {
            cout << value << setw(20);
        }
        cout << endl;
    }
}

vector<int> gettingThePivot(vector<vector<int>> matrix)
{

    vector<int> pivotCoordinates;
    vector<vector<int>>::iterator it1;
    vector<int>::iterator it2;
    vector<vector<int>>::iterator z = matrix.begin();

    int crosserRow = 1; // we begin from the 2nd row
    int crosserCol = 0;
    int pivotRow = 0;
    int pivotCol = 0;
    int pivotFilter = 0;
    int b = 0;
    int possiblePivot = 0;
    int chosenPivot = 0;
    float division = 0;

    for (it1 = matrix.begin() + 1; it1 != matrix.end(); it1++)
    {
        crosserCol = 0;
        for (it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
        {
            b = *((*it1).end() - 1);
            division = static_cast<float>(b)/(*it2) ;
            if ((*z)[crosserCol] > 0)
            {
                //cout << "xij/b = "<< b << "/"<< *it2 <<" = " << division <<  endl;
                if (division > 0)
                {
                    if (pivotFilter == 0)
                    {
                        chosenPivot = division;
                        pivotRow = crosserRow;
                        pivotCol = crosserCol;
                    }
                    possiblePivot = division;
                    pivotFilter++;

                    if (possiblePivot <= chosenPivot)
                    {
                        chosenPivot = possiblePivot;
                        pivotRow = crosserRow;
                        pivotCol = crosserCol;
                    }
                }
            }
            crosserCol++;
        }
        crosserRow++;
    }
    pivotCoordinates.push_back(pivotRow);
    pivotCoordinates.push_back(pivotCol);

    return pivotCoordinates;
}

int max(int x, int y)
{
    int max = 0;

    if (x > y)
    {
        max = x;
    }
    else
    {
        max = y;
    }

    return max;
}

float min(float x, float y){
    float min = 0.0;

    if (x < y){
        min = x;
    }
    else {
        min = y;
    }
    return min;
}

int gcd(int a, int b) {
    // Ensure a and b are non-negative for the algorithm
    a = std::abs(a);
    b = std::abs(b);

    // Base case: gcd(a, 0) = a
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the Least Common Multiple (LCM) using the GCD
// Handles non-negative inputs.
long long lcm(int x, int y) {
    // LCM of 0 and any number is 0
    if (x == 0 || y == 0) {
        return 0;
    }

    // The result of std::abs is at least 0.
    long long abs_x = std::abs(static_cast<long long>(x));
    long long abs_y = std::abs(static_cast<long long>(y));

    long long common_divisor = gcd(abs_x, abs_y); // Use our custom gcd which handles int

    // Ensure we don't divide by zero if somehow gcd returned 0 for non-zero inputs
    if (common_divisor == 0) {

         return 0;
    }


    return (abs_x / common_divisor) * abs_y; 
}

vector<vector<int>> newMatrix(vector<int> pivot, vector<vector<int>> matrix)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < matrix.size(); i++)
    {
        if (i != pivot[0])
        {
            for (j = 0; j < matrix[i].size(); j++)
            {
                if (j != pivot[1])
                {   
                    matrix[i][j] = (lcm(matrix[i][pivot[1]], matrix[pivot[0]][pivot[1]]) / matrix[i][pivot[1]]) * matrix[i][j] -
                                   (lcm(matrix[i][pivot[1]], matrix[pivot[0]][pivot[1]]) / matrix[pivot[0]][pivot[1]]) * matrix[pivot[0]][j];
                }
            }
        }
    }

    for(i=0; i < matrix.size(); i++){
        if(i != pivot[0])
            matrix[i][pivot[1]] = 0;
    }
    return matrix;
}