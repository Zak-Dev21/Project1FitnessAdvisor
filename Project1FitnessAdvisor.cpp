
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double user_BMI;
    double weight;
    double height;

    cout << "What is your height? " << endl;
    cin >> height;

    cout << "What is your weight? " << endl;
    cin >> weight;

    user_BMI = 703 * ( (weight) / pow(height, 2) );

    
}
