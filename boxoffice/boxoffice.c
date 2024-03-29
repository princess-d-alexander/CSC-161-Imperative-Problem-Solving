/**
 * Princess Alexander
 * 02/06/24
 * Homework 2: Ticket Pricing
 * 
 * Resources: Evening Tutor: Peter
 * Class website: https://curtsinger.cs.grinnell.edu/teaching/2024S/CSC161/hw/02-ticket-pricing/
 * 
 * Ticket Pricing System 
 *
 * Description:
 * This program is designed to calculate ticket prices for a local community theater based on seat location,
 * age of the ticket holder, and time of the show. It provides an interactive interface for users to input
 * the number of tickets they intend to purchase and the relevant information required to calculate the price
 * of each ticket. The program then prints the user-provided information along with the calculated ticket
 * prices and the total price for the order.
 *
 * Ticket Pricing Rules:
 * - Seat location: Main floor middle section, main floor sides, or balcony
 * - Price schedule:
 *     Location                   Matinee Price      Evening Price
 *     -----------------------------------------------------------
 *     Main floor - middle section     $25.00              $30.00
 *     Main floor - sides              $20.00              $25.00
 *     Balcony                         $15.00              $20.00
 * - Age Discounts:
 *     - Children 5 and under: Free
 *     - Children between 6 and 10 (inclusive) and senior citizens (age 55 and older): $5.00 discount
 *
 * Features:
 * - Interactive interface for user input
 * - Calculation of ticket prices based on seat location, age, and show time
 * - Validation of user inputs to ensure correctness
 *
 * Requirements:
 * - The program must prompt the user for the number of tickets they intend to purchase.
 * - It must collect information about the seat location, age of the ticket holder, and show time for each ticket.
 * - Invalid inputs should be rejected with appropriate error messages.
 * - The program should print the user-provided information, calculated ticket prices, and total price for the order.
 */

#include <stdio.h>

// Declared functions
void locationType(int location);
float calculateTicketPrice(int location, int age, int time);
void chosenTime(int time);

//////////////////////////////// Part 1 Collecting Input from User ////////////////////////////////////////////////

int main() {
    int numberOfTickets, location, age, time;
    float totalCost = 0;
    float ticketPrice;

    // Ask user for the number of tickets the user intends to purchase
    printf("How many tickets do you intend to purchase?\n");
    scanf("%d", &numberOfTickets);
    
    // Increment the number of times the loop is implemented based on the number of tickets
    for (int i = 0; i < numberOfTickets; i++) {
        printf("Ticket %d:\n", i + 1);
        // Ask the user where they would like to sit
        do {
            printf("Where would you like to sit?:\n1. Main floor - middle section\n2. Main floor - sides\n3. Balcony\n");
            scanf("%d", &location);
            if (location < 1 || location > 3) {
                printf("Invalid imput for location. Please select a whole number between 1 and 3.\n");
            }
        }while (location < 1 || location > 3);

        // Prompt the user to choose the Age for the ticket holder, inform them if they have entered an invalid input.
        do {
            printf("Enter the age of the ticket holder: ");
            scanf("%d", &age);
            if (age < 0 || age >= 150) {
                printf("Invalid input for age value. Please enter a valid age between 0 and 150.\n");
            }
        } while (age < 0 || age >= 150);

        // Prompt the user to choose the Time of The Show, inform them if they have entered an invalid input.
        do {
            printf("Select show time:\n1. Matinee\n2. Evening\n");
            scanf("%d", &time);
            if (time < 1 || time > 2) {
                printf("Invalid input for time. Please select either Matinee or Evening.\n");
            }
        }while (time < 1 || time > 2);

        ticketPrice = calculateTicketPrice(location, age, time);
        
        // If user buys more than two tickets add the ticket prices together
        totalCost += ticketPrice;

        // Print the ticket details for the user as well as the cost
        printf("Ticket Details:\n");
        printf("Location: ");
        locationType(location);
        printf("Age: %d\n", age);
        printf("Time: ");
        chosenTime(time);
        printf("Price: $%.2f\n", ticketPrice);
    }

    printf("\nTotal cost for %d tickets: $%.2f\n", numberOfTickets, totalCost);

    return 0;
}

//////////////////////////////////////////////// PART 2 Calculations and Printing Correct Names////////////////////////////////////////////////

// Define function for calculating the ticket price
float calculateTicketPrice(int location, int age, int time) {
float startingPrice = 0;

    // Determine the price of tickets before discounts based on location and time
    switch (location) {
        case 1: // If user chooses Matinee it will start at $25, if they choose Evening it will start at $30 the same logic applies for other locations...
                // For Main floor - middle section
            startingPrice = (time == 1) ? 25.0 : 30.0;
            break;
        case 2: // For Main floor - sides
            startingPrice = (time == 1) ? 20.0 : 25.0;
            break;
        case 3: // For Balcony
            startingPrice = (time == 1) ? 15.0 : 20.0;
            break;
    }

    // Account for discounts that need to applied to the ticket price in each special case
    if (age <= 5) {
        startingPrice = 0; // Free for children 5 and under
    } else if (age >= 55 || (age >= 6 && age <= 10)){
        startingPrice -= 5; // Discount for children between 6 & 10 and for seniors who are 55+
    }
    return startingPrice;
}

// Print the correct name for chosen time
void chosenTime(int time) {
    if (time == 1) {
        printf("Matinee\n");
    } 
    else {
        printf("Evening\n");
    }
}

// Print the correct name for the theater locations
void locationType(int location) {
    switch (location) {
        case 1:
            printf("Main floor - middle section\n");
            break;
        case 2:
            printf("Main floor - sides\n");
            break;
        case 3:
            printf("Balcony\n");
            break;
    }
}

// Note: When typing in exact name of location or a decimal in the place of an integer, the code runs infinitely, not sure how to fix this.