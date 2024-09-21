
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double user_BMI;
    double weight;
    double height;
    int muscle_level;
    int fat_level;

    cout << "What is your height in inches? " << endl;
    cin >> height;

    cout << "What is your weight? " << endl;
    cin >> weight;

    user_BMI = 703 * ( (weight) / pow(height, 2) );

    cout << "What would you rate your muscle mass level on a scale from 1 to 10";
    cin >> muscle_level;

    cout << "What would you rate your body fat level on a scale from 1 to 10";
    cin >> fat_level;


}
