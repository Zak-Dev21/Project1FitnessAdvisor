
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

    cout << "Your BMI is: " << user_BMI << endl;

    //Provide recemondations based on BMI, muscle level, and fat level
    if (user_BMI <= 18.4) {
        if (muscle_level < 4 && fat_level < 4) {
            cout << "You are underweight with low muscle mass and low body fat. Consider increasing your calorie intake and focusing on strength training to build muscle." << endl;
        }
        else if (muscle_level >= 4 && fat_level < 4) {
            cout << "You are underweight but have moderate muscle mass. Consider a balanced diet with enough protein to maintain muscle while increasing overall calories." << endl;
        }
        else if (muscle_level < 4 && fat_level >= 4) {
            cout << "You are underweight with higher fat levels. Focus on increasing lean muscle mass through resistance training and balanced eating." << endl;
        }
    else if (user_BMI >= 18.5 && user_BMI <= 24.9) {
        if (muscle_level >= 7 && fat_level <= 3) {
            cout << "You have a healthy weight with high muscle mass and low fat. Continue maintaining your current fitness routine and balanced diet." << endl;
        } else if (muscle_level >= 4 && fat_level > 4 && fat_level <= 7) {
            cout << "You have a healthy weight, but consider balancing muscle and fat levels. Keep an active routine and a balanced diet." << endl;
        } else if (muscle_level < 4 && fat_level >= 7) {
            cout << "You are at a healthy weight, but could benefit from increasing muscle mass and reducing fat. Focus on resistance training and reducing calorie intake slightly." << endl;
        }
    }
    else if (user_BMI >= 25.0 && user_BMI <= 29.9) {
        if (muscle_level >= 6 && fat_level <= 3) {
            cout << "You are overweight but have high muscle mass and low fat. Ensure your diet supports your activity levels, and avoid excess calorie intake." << endl;
        } else if (muscle_level < 6 && fat_level > 3) {
            cout << "You are overweight and may need to focus on reducing fat. Incorporate regular cardio exercises and monitor your calorie intake." << endl;
        }
    }
    else if (user_BMI >= 30.0) {
        if (muscle_level < 5 && fat_level > 6) {
            cout << "You are in the obese category. Focus on reducing body fat with cardio and calorie control, while incorporating muscle-strengthening exercises." << endl;
        } else if (muscle_level >= 5 && fat_level > 6) {
            cout << "You have good muscle mass, but your fat levels are high. Prioritize fat loss with a healthy diet and cardio, while maintaining muscle mass." << endl;
        }
    }
    }


}
