#include <stdio.h>
#include "cs50.h"

// Function prototype
float calculate_creche_fee(float father_salary, float mother_salary, int days_per_week, int hours_per_day, int num_children);

int main(void)
{
    // Get input from user
    float father_salary = get_float("Enter father's salary: ");
    float mother_salary = get_float("Enter mother's salary: ");
    
    // Validate salaries
    if (father_salary < 0 || mother_salary < 0)
    {
        printf("Salaries cannot be negative.\n");
        return 1;
    }

    int days_per_week = get_int("Enter number of days per week (1-7): ");
    if (days_per_week < 1 || days_per_week > 7)
    {
        printf("Invalid number of days. Must be between 1 and 7.\n");
        return 1;
    }

    int hours_per_day = get_int("Enter number of hours per day (1-24): ");
    if (hours_per_day < 1 || hours_per_day > 24)
    {
        printf("Invalid number of hours. Must be between 1 and 24.\n");
        return 1;
    }

    int num_children = get_int("Enter number of children (1 or more): ");
    if (num_children < 1)
    {
        printf("Number of children must be at least 1.\n");
        return 1;
    }

    // Calculate the creche fee
    float fee = calculate_creche_fee(father_salary, mother_salary, days_per_week, hours_per_day, num_children);

    // Print the result
    printf("The monthly creche fee is: %.2f EUR\n", fee);

    return 0;
}

// Function to calculate the creche fee
float calculate_creche_fee(float father_salary, float mother_salary, int days_per_week, int hours_per_day, int num_children)
{
    // Coefficient caf based on number of children
    float coef_caf;
    if (num_children == 1)
    {
        coef_caf = 0.0619; // 6.19%
    }
    else if (num_children == 2)
    {
        coef_caf = 0.0516; // 5.16%
    }
    else if (num_children == 3)
    {
        coef_caf = 0.0413; // 4.13%
    }
    else if (num_children >= 4 && num_children <= 7)
    {
        coef_caf = 0.0310; // 3.10%
    }
    else if (num_children >= 8)
    {
        coef_caf = 0.0206; // 2.06%
    }
    else
    {
        printf("Invalid number of children.\n");
        return 0;
    }

    // Calculate the total salary
    float total_salary = father_salary + mother_salary;

    // Calculate the base fee
    float base_fee = total_salary * coef_caf;

    // Number of weeks in a month
    int weeks_per_month = 4;

    // Calculate the total fee (fee per day multiplied by total days in a month)
    float total_fee = base_fee * days_per_week * hours_per_day * weeks_per_month;

    return total_fee;
}
