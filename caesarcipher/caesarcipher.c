/*
 * Princess Alexander
 * 03/04/24
 * Homework 5: Encryption
 * 
 * Resources: 
 * Class Website: 
 * 
 * Encryption
 * 
 * Description:
 * This program is designed to perform both encoding and decoding of messages 
 * using the Caesar Cipher encryption technique. When given a lowercase string, 
 * the program then displays the results with all possible keys. It includes 
 * input validation and follows specific style guidelines.
 * 
 * 
 * Overview:
 * For this assignment, you will implement a classic (but not recommended!!) 
 * encryption technique known as the Caesar Cipher. The Caesar Cipher is a 
 * substitution cipher where each letter in the plaintext is shifted a certain 
 * number of places down or up the alphabet. This shift is known as the key. 
 * For example, with a shift of 1, 'a' would be replaced by 'b', 'b' would 
 * become 'c', and so on. The method is named after Julius Caesar, who is 
 * reported to have used it to communicate with his officials. 
 * 
 * Requirements:
 * - The program should accept inputs with a maximum length of 100 characters. 
 *   If the user provides a longer input, truncate the message to the first 100 characters.
 * 
 * - The program should limit the user to inputs containing lowercase characters only 
 *   (no uppercase letters, numbers, punctuation, or whitespace). If the user input 
 *   contains any disallowed characters, the program must print an error and ask the 
 *   user to try again with a valid input.
 * 
 * - The program must display all 26 possible ways of encoding or decoding the given string.
 * 
 * - The format of the output should be identical to the sample executions provided in 
 *   the assignment description.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Caesar Cipher encryption
void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (islower(message[i])) {
            message[i] = (char)(((message[i] - 'a' + key) % 26) + 'a');
        }
    }
}

// Function to perform Caesar Cipher decryption
void decrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (islower(message[i])) {
            message[i] = (char)(((message[i] - 'a' - key + 26) % 26) + 'a');
        }
    }
}

// Function to print the result of encoding/decoding with all possible keys
void printResults(char message[]) {
    for (int key = 0; key < 26; ++key) {
        printf("n = %d: %s\n", key, message);
        decrypt(message, 1);  // Reset the message for the next iteration
    }
}

int main() {
    char message[101];  // Limit input to 100 characters (+1 for null terminator)
    char choice[10];

    printf("This program encrypts and decrypts messages using the Caesar Cipher.\n");
    printf("Type 'e' to encode or 'd' to decode a message: ");
    scanf("%s", choice);

    if (strcmp(choice, "e") != 0 && strcmp(choice, "d") != 0) {
        printf("Valid options are 'e' to encode or 'd' to decode.\n");
        return 1;
    }

    printf("Enter the string to %s (lowercase letters only): ", (strcmp(choice, "e") == 0) ? "encode" : "decode");
    scanf("%s", message);

    // Validate input characters
    for (int i = 0; message[i] != '\0'; ++i) {
        if (!islower(message[i])) {
            printf("Error: Invalid character found. Please use lowercase letters only.\n");
            return 1;
        }
    }

    // Truncate the message if it exceeds 100 characters
    message[100] = '\0';

    printf("Result of %s with all possible keys:\n", (strcmp(choice, "e") == 0) ? "encoding" : "decoding");
    if (strcmp(choice, "e") == 0) {
        printResults(message);
    } else {
        encrypt(message, 1);  // Encrypt once to start with the original message
        printResults(message);
    }

    return 0;
}