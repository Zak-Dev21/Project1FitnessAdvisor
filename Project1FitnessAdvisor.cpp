
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

const int BMI_CONSTANT = 703;

// Function to calculate BMI
double calculateBMI(double weight, double height) {
    return BMI_CONSTANT * (weight / pow(height, 2));
}

/*void provideRecommendation(double user_BMI_goal, int muscle_level_goal, int fat_level_goal) {
    if (user_BMI == goalBMI) {
        cout << "You reached your BMI goal!"
    }
}
*/

// Function to provide recommendation based on BMI, muscle, and fat levels
void provideRecommendation(double user_BMI, int muscle_level, int fat_level) {
    string recommendations[4][4] = { //initializing 2d array to store strings of recommendatiions and make them accessable easily
        {"You are underweight with low muscle mass and low body fat. Consider increasing your calorie intake and focusing on strength training to build muscle.",
         "You are underweight but have moderate muscle mass. Consider a balanced diet with enough protein to maintain muscle while increasing overall calories.",
         "You are underweight with higher fat levels. Focus on increasing lean muscle mass through resistance training and balanced eating."},

        {"You have a healthy weight with high muscle mass and low fat. Continue maintaining your current fitness routine and balanced diet.",
         "You have a healthy weight, but consider balancing muscle and fat levels. Keep an active routine and a balanced diet.",
         "You are at a healthy weight, but could benefit from increasing muscle mass and reducing fat. Focus on resistance training and reducing calorie intake slightly."},
        {"You are overweight but have high muscle mass and low fat. Ensure your diet supports your activity levels, and avoid excess calorie intake.",
         "You are overweight and may need to focus on reducing fat. Incorporate regular cardio exercises and monitor your calorie intake."},

        {"You are in the obese category. Focus on reducing body fat with cardio and calorie control, while incorporating muscle-strengthening exercises.",
         "You have good muscle mass, but your fat levels are high. Prioritize fat loss with a healthy diet and cardio, while maintaining muscle mass."}
    };

    if (user_BMI <= 18.4) {
        if (muscle_level < 4 && fat_level < 4) {
            cout << recommendations[0][0] << endl;
        }
        else if (muscle_level >= 4 && fat_level < 4) {
            cout << recommendations[0][1] << endl;
        }
        else if (muscle_level < 4 && fat_level >= 4) {
            cout << recommendations[0][2] << endl;
        }
    }
    else if (user_BMI >= 18.5 && user_BMI <= 24.9) {
        if (muscle_level >= 7 && fat_level <= 3) {
            cout << recommendations[1][0] << endl;
        }
        else if (muscle_level >= 4 && fat_level > 4 && fat_level <= 7) {
            cout << recommendations[1][1] << endl;
        }
        else if (muscle_level < 4 && fat_level >= 7) {
            cout << recommendations[1][2] << endl;
        }
    }
    else if (user_BMI >= 25.0 && user_BMI <= 29.9) {
        if (muscle_level >= 6 && fat_level <= 3) {
            cout << recommendations[2][0] << endl;
        }
        else if (muscle_level < 6 && fat_level > 3) {
            cout << recommendations[2][1] << endl;
        }
    }
    else if (user_BMI >= 30.0) {
        if (muscle_level < 5 && fat_level > 6) {
            cout << recommendations[3][0] << endl;
        }
        else if (muscle_level >= 5 && fat_level > 6) {
            cout << recommendations[3][1] << endl;
        }
    }
}

//Function to generate random number between 5 and 15
int generateRandomExerciseDays() {
    return rand() % 11 + 15; // generates random number between 5 and 15

}

// Function to check if a string is a valid number
bool isValidNumber(const string& input) {
    for (char c : input) {
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

int main() {
    double weight, height, user_BMI;
    string fav_activity;
    int muscle_level, fat_level;
    char user_choice;
    string user_input;

    const int max_entries = 10; // Define the maximum number of entries
    double bmi_history[max_entries] = { 0 }; // Initialize the BMI history array
    int muscle_levels[max_entries] = { 0 }; // Initialize muscle levels array
    int fat_levels[max_entries] = { 0 }; // Initialize fat levels array


    srand(static_cast<unsigned int>(time(0)));

    cout << "Chose between 'p':progress check or 'd': direct check. Enter single character either 'p' or 'd'" << endl;
    cin >> user_choice;

    if (user_choice == 'd') {

        

        while (true) {
            cout << "Would you like to begin direct check? Answer 'yes' or 'done' " << endl;
            cin >> user_input;

            if (user_input == "done") {
                break;
            }

            // Input height with validation
            while (true) {
                cout << "What is your height in inches? " << endl;
                cin >> user_input;

                if (isValidNumber(user_input)) {
                    height = stod(user_input); // Convert string to double
                    if (height > 0) {
                        break; // Valid input, exit loop
                    }
                    else {
                        cout << "Invalid input. Please enter a positive value for height." << endl;
                    }
                }
                else {
                    cout << "Invalid input. Please enter a numeric value for height." << endl;
                }
            }

            // Input weight with validation
            while (true) {
                cout << "What is your weight in pounds? " << endl;
                cin >> user_input;

                if (isValidNumber(user_input)) {
                    weight = stod(user_input); // Convert string to double
                    if (weight > 0) {
                        break; // Valid input, exit loop
                    }
                    else {
                        cout << "Invalid input. Please enter a positive value for weight." << endl;
                    }
                }
                else {
                    cout << "Invalid input. Please enter a numeric value for weight." << endl;
                }
            }
            // Calculate BMI using function
            user_BMI = calculateBMI(weight, height);

            cout << "Your BMI is: " << user_BMI << endl;

            cout << "What would you rate your muscle mass level on a scale from 1 to 10: " << endl;
            cin >> muscle_level;

            cout << "What would you rate your body fat level on a scale from 1 to 10: " << endl;
            cin >> fat_level;

            provideRecommendation(user_BMI, muscle_level, fat_level);

            cout << "What is you favorite form of exercise/activity: " << endl;
            cin >> fav_activity;


            


            //Generate random number for exercise days to motivate user
            int exercise_days = generateRandomExerciseDays();
            cout << "To kickoff your fitness journey, try doing " << fav_activity << " for "
                << exercise_days << " days this month!" << endl;


        
        }

        
        
        cout << "YOU HAVE FINISHED USING PROGRAM! THANKS";
        

    }

    if (user_choice == 'p') {
        int count = 0;
        // Input height with validation
        while (true) {
            cout << "What is your height in inches? " << endl;
            cin >> user_input;

            if (isValidNumber(user_input)) {
                height = stod(user_input); // Convert string to double
                if (height > 0) {
                    break; // Valid input, exit loop
                }
                else {
                    cout << "Invalid input. Please enter a positive value for height." << endl;
                }
            }
            else {
                cout << "Invalid input. Please enter a numeric value for height." << endl;
            }
        }
        
        while (true) {
            cout << "Would you like to initiate progess check? Answer 'yes' or 'done' " << endl << "Keep in mind you only have a maximum of 10 entries to enter." << endl;
            cin >> user_input;
            

            if (user_input == "done") {
                break;
            }

            //cout << "Keep in mind when entering you info you do have a maximum of 10 entries";

        
            

            cout << "What is your weight in pounds? " << endl;
            cin >> weight;

            // Calculate BMI using function
            user_BMI = calculateBMI(weight, height);

            //cout << "Your BMI is: " << user_BMI << endl;

            cout << "What would you rate your muscle mass level on a scale from 1 to 10: " << endl;
            cin >> muscle_level;

            cout << "What would you rate your body fat level on a scale from 1 to 10: " << endl;
            cin >> fat_level;

            bmi_history[count] = user_BMI;
            muscle_levels[count] = muscle_level;
            fat_levels[count] = fat_level;

            count++;
        }

        // Display stored progress
        cout << "Here is your progress:" << endl;
        for (int i = 0; i < count; ++i) {
            cout << "Result " << (i + 1) << ": BMI = " << bmi_history[i]
                << ", Muscle Level = " << muscle_levels[i]
                << ", Fat Level = " << fat_levels[i] << endl;
        }
    }

    return 0;
}

