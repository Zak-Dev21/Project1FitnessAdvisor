
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

const int BMI_CONSTANT = 703;

double weight, height, user_BMI;
string fav_activity;
int muscle_level, fat_level;
string user_choice;
string user_input;
int age;
int activity_level;
string health_condition;

const int max_entries = 10; // Define the maximum number of entries
double bmi_history[max_entries] = { 0 }; // Initialize the BMI history array
int muscle_levels[max_entries] = { 0 }; // Initialize muscle levels array
int fat_levels[max_entries] = { 0 }; // Initialize fat levels array

const string muscleGroups[] = { "Chest", "Back", "Legs", "Arms", "Core" };
const string exercises[][3] = {
    {"Decline Push Ups", "Push Up", "Resistance Band Chest Fly"}, // Chest
    {"Pull Up", "Bodyweight Row", "Chin Up"},          // Back
    {"Squat", "Lunge", "Biking/Running"},         // Legs
    {"Bicep Curl", "Tricep Dip", "Push Up"}, // Arms
    {"Plank", "Crunch", "Leg Raises"}     // Core
};

// Function to calculate BMI
double calculateBMI(double weight, double height) {
    return BMI_CONSTANT * (weight / pow(height, 2));
}



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

    if (user_BMI <= 18.4) { //checking if user falls in underwight category for BMI
        // checking further with muscle and fat levels to see where user falls and provide accurate recommendation
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
    else if (user_BMI >= 18.5 && user_BMI <= 24.9) { // checking if user falls into mid-range category for BMI
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

void provideRecommendation(int age, int activity_level, string &health_condition) {
    // Condition for people over 50 who are sedentary (low activity level) and no health condition
    if (age > 50 && activity_level <= 2 && health_condition == "none") {
        cout << "Consider performing low-impact exercises such as walking or swimming. Make sure to maintain a healthy diet." << endl;
    }
    // Other age-based recommendations
    else if (age <= 18) {
        cout << "Since you're a young adult, maintaining an active lifestyle with balanced nutrition is crucial for healthy development." << endl;
    }
    else if (age >= 65) {
        cout << "For seniors, it's important to focus on low-impact exercises like walking or swimming and to ensure your diet supports bone health." << endl;
    }
    else {
        cout << "Maintaining a balanced lifestyle with regular physical activity is recommended for adults." << endl;
    }

    // Activity level recommendations (other cases)
    if (activity_level <= 2 && !(age > 50 && health_condition == "none")) {
        cout << "It looks like you have a low activity level. Consider adding more physical activities like walking or cycling to your routine." << endl;
    }
    else if (activity_level >= 8) {
        cout << "With your high activity level, ensure you're getting enough rest and nutrients to support your fitness." << endl;
    }
    else {
        cout << "You're maintaining a moderate activity level. Keep up the good work! Make sure to progress to further levels in order to push yourself and reach goals!" << endl;
    }

    // Health condition recommendations (other cases)
    if (health_condition == "heart") {
        cout << "For heart health, it's important to focus on cardio exercises and maintain a heart-healthy diet rich in fiber and low in saturated fats." << endl;
    }
    else if (health_condition == "diabetes") {
        cout << "With diabetes, managing your blood sugar levels through a balanced diet and regular physical activity is key." << endl;
    }
    else if (health_condition == "joint") {
        cout << "For joint health, consider low-impact exercises like swimming or cycling, and consult with your doctor for personalized recommendations." << endl;
    }
    else if (health_condition == "none" && !(age > 50 && activity_level <= 2)) {
        cout << "If you have no specific health conditions, continue maintaining a balanced diet and regular exercise." << endl;
    }
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

// function used to validate height input and make sure it is a positive number
void height_validation() {
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
}

// function used to validate height input and make sure it is a positive number
void weight_validation() {
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
}



//Function to generate random number between 15 and 25
int generateRandomExerciseDays() {
    return rand() % 11 + 15; // generates random number between 15 and 25

}




int main() {


    int numMuscleGroups = sizeof(muscleGroups) / sizeof(muscleGroups[0]); // calculating the number of elements in the muscleGroups array.
    


    srand(static_cast<unsigned int>(time(0))); // seed the random number generator so new number shows every execution

    cout << "Chose between 'p':progress check (track progress over time) or 'd': direct fitness check or 'm': muscle exercise recemmondations. Enter single character either 'p' or 'd' or 'm' " << endl;
    cin >> user_choice; // prompting user to chose which feature to use for program

    while ((user_choice != "m") && (user_choice != "d") && (user_choice != "p")) {
        cout << "Invalid input. Please enter 'm', 'd', or 'p'." << endl;
        cin >> user_choice;
    } // making sure user enter given characters and nothing else, handling edge case for possibilities here

    while (true) {

        if (user_choice == "d") {

                cout << "Would you like to begin direct check? Answer 'yes' or 'no' " << endl;
                cin >> user_input;

                if (user_input == "no") {
                    break;
                }

                // Input height with validation
                height_validation();

                // Input weight with validation
                weight_validation();

                // continue asking user for more inputs to get more tailored recommendation

                cout << "Enter your age: ";
                cin >> age;

                cout << "Rate you activity level from 1 to 10: ";
                cin >> activity_level;

                cout << "Do you have a health condition involving the following? (diabetic, heart, joint)."
                    "If yes enter it, otherwise enter 'other' if you have other health conditions, or enter 'none' if you have none." << endl;
                cin >> health_condition;


                // Calculate BMI using function
                user_BMI = calculateBMI(weight, height);

                cout << "Your BMI is: " << user_BMI << endl;

                if (user_BMI > 40) {
                    cout << "Your BMI exceeds the limit of 40. Please consult a healthcare professional for advice." << endl;
                    continue; // Skip further inputs if BMI is too high
                }

                while (true) {
                    cout << "What would you rate your muscle mass level on a scale from 1 to 10: " << endl;
                    cin >> muscle_level;

                    if (muscle_level >= 1 && muscle_level <= 10) {
                        break; // valid input, exit the loop
                    }
                    else {
                        cout << "Invalid input. Please enter a number between 1 and 10." << endl;
                    }
                }

                // Input and validation for fat level
                while (true) {
                    cout << "What would you rate your body fat level on a scale from 1 to 10: " << endl;
                    cin >> fat_level;

                    if (fat_level >= 1 && fat_level <= 10) {
                        break; // valid input, exit the loop
                    }
                    else {
                        cout << "Invalid input. Please enter a number between 1 and 10." << endl;
                    }
                }

                provideRecommendation(user_BMI, muscle_level, fat_level);

                provideRecommendation(age, activity_level, health_condition);

                cout << "What is you favorite form of exercise/activity: " << endl;
                cin >> fav_activity;





                //Generate random number for exercise days to motivate user
                int exercise_days = generateRandomExerciseDays();
                cout << "To kickoff your fitness journey, try doing " << fav_activity << " for "
                    << exercise_days << " days this month!" << endl;



            cout << "YOU HAVE FINISHED USING PROGRAM! THANKS" <<endl;
            break;


        }

        if (user_choice == "p") {
            int count = 0;

            while (true) {
                cout << "Would you like to initiate progess check? Answer 'yes' or 'no' " << endl << "Keep in mind you only have a maximum of 10 entries to enter." << endl;
                cin >> user_input; // prompting user to either run checker feature or exit

                if (user_input == "no") {
                    cout << "You have finished the progress check feature for this program. Thanks!" << endl;
                    break;
                }
                
                // validate input for height
                height_validation();




                // Input weight with validation
                weight_validation();

                // Calculate BMI using function
                user_BMI = calculateBMI(weight, height);

                if (user_BMI > 40) {
                    cout << "Your BMI exceeds the limit of 40. Please consult a healthcare professional for advice." << endl;
                    continue; // Skip further inputs if BMI is too high
                }

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
        
        

        if (user_choice == "m") {
            
            //cout << "Would you like to initiate muscle reccomendation checker? " << endl;
            //cin >> input;
            // User input for weak muscle groups
            

            // Array to store user's weaknesses (maximum 5 weak muscle groups)
            int userWeaknesses[5] = { -1, -1, -1, -1, -1 }; // Initialize to -1 to indicate unused slots



                cout << "Would you like to start muscle recommendation feature of this program? Enter 'no' without quotes to exit or 'yes' without quotes to proceed. " << endl;
                cin >> user_input;

            
                if ((user_input != "yes") && (user_input != "no")) {
                    cout << "You entered an invalid input. Please enter yes or no without upper case or quotes. " << endl;
                    continue;
                }


                if (user_input == "no") {
                    cout << "You have come to the end of this program. Thanks!" << endl;
                    break;
                }
            


                string input;


                cout << "Which muscle groups do you consider weak? Enter numbers (0-4) corresponding to:" << endl;
                for (int i = 0; i < numMuscleGroups; ++i) {
                    cout << i << ": " << muscleGroups[i] << endl;
                }


                cout << "Enter your choices (comma-separated, e.g., 0,2). Or enter 'no' without quotes to exit program or 'yes' to continue. " << endl;
                cin >> input;




                if (true) {



                    // Collect user input for selesting numbers that represent muscle weaknesses






                    // Validate input
                    bool validInput = true;
                    int index = 0;

                    // Check each character in the input string
                    for (size_t i = 0; i < input.length(); ++i) {
                        if (isdigit(input[i])) {
                            int num = input[i] - '0'; // Convert char to int
                            if (num >= 0 && num <= 4) {
                                if (index < 5) {
                                    userWeaknesses[index++] = num; // Store the valid number
                                }
                            }
                            else {
                                validInput = false; // Number out of range
                            }
                        }
                        else if (input[i] != ',' && input[i] != ' ') {
                            validInput = false; // Invalid character found
                        }
                    }

                    // Ensure valid input
                    if (!validInput || index == 0) {
                        cout << "Invalid input. Please enter numbers (0-4) separated by commas." << endl;
                        continue; // Prompt for input again
                    }

                    // Display exercises for weak muscle groups
                    cout << "Here are some exercises for your weak muscle groups:" << endl;

                    for (int i = 0; i < index; ++i) { // Loop only through valid inputs
                        int weakness = userWeaknesses[i];
                        if (weakness >= 0 && weakness < numMuscleGroups) { // check user's number falls in the number limit for muscle groups array
                            cout << muscleGroups[weakness] << " exercises:" << endl;
                            for (int j = 0; j < 3; ++j) { // Assuming each muscle group has 3 exercises
                                cout << "- " << exercises[weakness][j] << endl;
                            }
                        }

                    }

                 


                }



          


        }
    }

    return 0;
}

