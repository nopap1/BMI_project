#include <stdio.h>

// ANSI escape codes for text color
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"

int main() {
    // Declare variables to store weight, height, and recommended weight range
    float weight_kg, height_ft_in, height_m, height_in, bmi;
    float lower_weight_range, upper_weight_range;

    // Prompt the user to enter weight in kilograms
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight_kg);

    // Prompt the user to enter height in feet and inches as "feet inches"
    printf("Enter your height in feet and inches (e.g., 5 9 for 5 feet 9 inches): ");
    scanf("%f %f", &height_ft_in, &height_in);

    // Convert height to meters (1 foot = 0.3048 meters, 1 inch = 0.0254 meters)
    height_m = (height_ft_in * 0.3048) + (height_in * 0.0254);

    // Calculate BMI using the formula: BMI = weight (kg) / (height (m) * height (m))
    bmi = weight_kg / (height_m * height_m);

    // Display the calculated BMI with colored text
    printf("Your BMI is: ");
    if (bmi < 18.5) {
        printf(RED "%.2f" RESET, bmi);
    } else if (bmi >= 18.5 && bmi < 25) {
        printf(GREEN "%.2f" RESET, bmi);
    } else if (bmi >= 25 && bmi < 30) {
        printf(YELLOW "%.2f" RESET, bmi);
    } else {
        printf(RED "%.2f" RESET, bmi);
    }
    printf("\n");

    // Interpret and display the BMI category with colored text
    printf("BMI Category: ");
    if (bmi < 18.5) {
        printf(RED "Underweight" RESET "\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf(GREEN "Normal" RESET "\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf(YELLOW "Overweight" RESET "\n");
    } else {
        printf(RED "Obese" RESET "\n");
    }

    // Calculate recommended weight range based on height (BMI range: 18.5 - 24.9)
    lower_weight_range = 18.5 * height_m * height_m;
    upper_weight_range = 24.9 * height_m * height_m;

    // Display the recommended weight range
    printf("Recommended weight range for your height is between %.2f kg and %.2f kg.\n", lower_weight_range, upper_weight_range);

    return 0;
}
