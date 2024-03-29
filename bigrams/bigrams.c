/**
 * Princess Alexander
 * 02/19/24
 * Homework 4: Bigrams
 * 
 * Resources: For ASCII values: https://www.ascii-code.com/
 * Class website: https://curtsinger.cs.grinnell.edu/teaching/2024S/CSC161/hw/04-bigrams/
 * 
 * Counting Bigrams
 *
 * Description:
 * This program reads input from the user until they press enter and then displays the count of each bigram
 * (sequence of two adjacent characters) observed in the input. It also identifies the most common bigram.
 * Bigrams include any adjacent characters, including spaces, but exclude the newline character.
 *
 * Requirements:
 * - The program places no upper limit on the length of user input.
 * - Input is case sensitive; distinct counts are maintained for different cases.
 * - The newline character is not part of the processed input.
 * - The most common bigram is printed at the end of the output. If tied, any can be printed.
 * - Only bigrams with a non-zero count are printed.
 * - If the input contains no bigrams (i.e., it's shorter than two characters), a message is printed instead of the most common bigram.
 *
 * Hints:
 * - Process user input one character at a time using getchar().
 * - Use a 2D array to store bigram counts.
 */

#include <stdio.h>

#define CHAR_RANGE 256 //Based on ASCII range

// Function to update the bigram count
void updateBigramCount(int counts[CHAR_RANGE][CHAR_RANGE], char first, char second, int isFirstChar) {
    // Check if it's the first character, skip updating bigram in this case. 
    // You want to start counting only if it is NOT the first character which would make sure it doesnt print the first character as a bigram
    if (!isFirstChar) {
        // Update bigram count
        counts[first][second]++;
    }
}

// Function to find the most common bigram
void findMostCommonBigram(int counts[CHAR_RANGE][CHAR_RANGE], char mostCommon[2]) {
    int maxCount = 0; // used to keep track of the maximum count of any bigram encountered so far
    int maxIndex1 = 0, maxIndex2 = 0; // These variables store the indices of the most common bigram

    // Iterate through the array to find the most common bigram
    for (int i = 0; i < CHAR_RANGE; i++) {
        for (int j = 0; j < CHAR_RANGE; j++) {
            if (counts[i][j] > maxCount) {
                maxCount = counts[i][j];
                maxIndex1 = i; 
                maxIndex2 = j;
            }
        }
    }

    // Converting the indices back to characters
    mostCommon[0] = maxIndex1;
    mostCommon[1] = maxIndex2;
}

int main() {
    // Initialize the array to store the count of each bigram
    int bigramCounts[CHAR_RANGE][CHAR_RANGE] = {0};

    // Read input from the user ONLY until a newline character is encountered
    char ch;
    char prevChar = '\0'; // \0 is the null character in ASCII, lets you know prevChar stores a character but doesnt assign a character yet

    printf("Enter text (press Enter to finish):\n");

    int isFirstChar = 1; // Boolean to indicate the first character

    while ((ch = getchar()) != '\n') {
        // Update bigram count
        updateBigramCount(bigramCounts, prevChar, ch, isFirstChar);

        isFirstChar = 0; // Reset the boolean after processing the first character
        prevChar = ch;
    }

    // Find the count of each bigram, then print the result
    int totalBigrams = 0; // Track the total number of bigrams
    for (int i = 0; i < CHAR_RANGE; i++) {
        for (int j = 0; j < CHAR_RANGE; j++) {
            if (bigramCounts[i][j] > 0) {
                totalBigrams++;
                printf("\"%c%c\": %d\n", i, j, bigramCounts[i][j]);
            }
        }
    }

    // Find and print the most common bigram if there are more than 1 bigrams
    if (totalBigrams > 1) {
        char mostCommon[2];
        findMostCommonBigram(bigramCounts, mostCommon);
        
        printf("\nMost common bigram: \"%c%c\"\n", mostCommon[0], mostCommon[1]);
    } else {
        printf("\nThe input did not contain any bigrams.\n");
    }

    return 0;
}
