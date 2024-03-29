/**
 * Credit Card Interest Calculator
 *
 * Description:
 * This program simulates calculating credit card interest while making only the minimum payment each month. 
 * It calculates the daily periodic rate (DPR) based on the annual percentage rate (APR) and uses it to determine 
 * the interest charges accrued in a billing cycle. The program displays the amount paid each month, along with 
 * the interest accrued and the remaining balance. Once the balance is paid off, it reports the total months 
 * it took to pay off the balance and the total amount paid.
 *
 * Example:
 * Suppose the APR is 18%, the monthly minimum payment is $35, and the initial balance is $500. The program 
 * might display the following information:
 * 
 * Month  Payment  Interest  Remaining Balance
 * 1      $7.40    $35.00    $472.40
 * 2      $7.22    $35.00    $444.62
 * ...
 * 16     $0.63    $35.00    $6.75
 * 17     $0.10    $6.86     $0.00
 * 
 * After 17 months, you paid $566.86 on an initial balance of $500.00.
 *
 * Requirements:
 * - Prompt the user for the annual percentage rate (APR), initial balance, and monthly minimum payment.
 * - Display the payment, interest, and remaining balance for each month until the balance is paid off.
 * - Calculate interest based on the number of days in the month.
 * - Ensure that the payment does not exceed the minimum payment or the remaining balance.
 * - Assume no new charges accrue, focusing solely on paying off the card.
 * - Organize the code to easily find and change values for initial_balance, APR, monthly_minimum, and starting_month.
 * - Utilize at least one additional function besides the main function.
 * 
 * Princess Alexander
 * 02/11/24
 * Homework 3: Credit Card Interest
 * 
 * Resources: To clear old inputs I learned what clearing the input buffer was here: https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
 * Class website: https://curtsinger.cs.grinnell.edu/teaching/2024S/CSC161/hw/03-interest/
 * */

#include <stdio.h>
#include <math.h>

#define MAX_CYCLES 100

// Function to calculate interest based on balance, APR, and days
double calculateInterest(double balance, double apr, int days) {
    return balance * apr * days;
}

// Function to calculate the number of days in a given month
int daysInMonth(int month) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[month];
}

// Function to print the table header
void printTableHeader() {
    printf("%-8s%-8s%-12s%-12s%-12s%-18s\n", "Cycle", "Month", "Balance", "Interest", "Payment", "New Balance");
}

// Function to print a table row
void printTableRow(int cycle, int month, double balance, double interest, double payment, double new_balance) {
    printf("%-8d%-8d%-12.2f%-12.2f%-12.2f%-18.2f\n", cycle, month, balance, interest, payment, new_balance);
}

int main() {
    // Variables for user input
    double initial_balance = 0, monthly_minimum = 0, interest = 0, payment = 0, new_balance = 0;
    int current_month = 0;
    int cycle = 0;
    double apr = 0;

    float counter = 0;

    // Get user input with validation
    do {
        printf("Enter initial balance: ");
        if (scanf("%lf", &initial_balance) != 1 || initial_balance < 0) {
            printf("Invalid input. Please choose a positive number.\n");
            while (getchar() != '\n');
        }
    } while (initial_balance < 0);

    do {
        printf("Enter monthly minimum payment: ");
        if (scanf("%lf", &monthly_minimum) != 1 || monthly_minimum < 0) {
            printf("Invalid input. Please choose a positive number.\n");
            while (getchar() != '\n');
        }
    } while (monthly_minimum < 0);

    do {
        printf("Enter APR (e.g. 0.18 for 18%%): ");
        if (scanf("%lf", &apr) != 1 || apr < 0) {
            printf("Invalid input. Please choose a positive number.\n");
            while (getchar() != '\n');
        }
    } while (apr < 0);
    
    // Convert APR to daily rate
    double dpr = apr / 365;

    do {
        printf("Enter starting month (1-12): ");
        if (scanf("%d", &current_month) != 1 || current_month < 1 || current_month > 12) {
            printf("Invalid input. Please choose a whole positive integer between 1 and 12. (choosing a non integer will round your number down to nearest integer)\n");
            while (getchar() != '\n');
        }
    } while (current_month < 1 || current_month > 12);

    // Constants for calculation
    double total_paid = 0;

    // Store the original initial balance
    double original_initial_balance = initial_balance;

    // Print table header
    printTableHeader();

    // Loop until the balance is paid off or maximum iterations
    for (cycle = 0; cycle < MAX_CYCLES && initial_balance > 0; cycle++) {
        // Get the number of days in the current month
        int days_in_current_month = daysInMonth(current_month);

        // Calculate interest based on the number of days in the month
        interest = calculateInterest(initial_balance, dpr, days_in_current_month);

        // Calculate the new balance after the minimum payment
        new_balance = initial_balance + interest - monthly_minimum;

        // Adjust the payment amount if it exceeds the balance
        if (monthly_minimum > initial_balance + interest) {
            payment = initial_balance + interest;
        } else {
            payment = monthly_minimum;
        }

        // Set new_balance to 0 if it goes below 0
        if (new_balance < 0) {
            new_balance = 0;
        }

        // Print the table row
        printTableRow(cycle, current_month, initial_balance, interest, payment, new_balance);

        // Update variables for the next iteration
        initial_balance = new_balance;
        current_month = (current_month % 12) + 1;
        total_paid += payment;
    }

    // Print the summary using the original initial balance
    printf("\nAfter %d cycles, you paid $%.2f on an initial balance of $%.2f.\n", cycle, total_paid, original_initial_balance);

    return 0;
}
