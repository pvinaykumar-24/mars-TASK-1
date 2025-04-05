#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*The logic follows these steps:

1.Convert all letters to uppercase.
2.Reverse the shift pattern:
 The first letter is shifted back by 1.
 The second letter is shifted back by 2.
 The third letter is shifted back by 3, and so on.
3.Print the decoded message in all uppercase. 

*/


// Function to decode the encrypted message
void decodeMessage(char encrypted[]) {
    int length = strlen(encrypted);
    char decoded[length + 1]; // Array to store the decoded message

    for (int i = 0; i < length; i++) {
        if (isalpha(encrypted[i])) { // Ensure it's a letter
            char decodedChar = encrypted[i] - (i + 1); // Reverse the shift pattern
            if (decodedChar < 'A') { // Handle wrap-around cases
                decodedChar += 26;
            }
            decoded[i] = decodedChar; // Store the decoded character
        } else {
            decoded[i] = encrypted[i]; // If not a letter, keep it unchanged (though input contains only alphabets)
        }
    }
    decoded[length] = '\0'; // Null terminate the string
    
    printf("Decoded Message: %s\n", decoded); // Print the final decoded message
}



int main() {
    char encryptedMessage[100]; // Buffer to store input
    
    printf("Enter the encrypted message: ");
    scanf("%s", encryptedMessage); // Read the input message
    
    // Convert the input to uppercase to ensure consistency
    for (int i = 0; encryptedMessage[i] != '\0'; i++) {
        encryptedMessage[i] = toupper(encryptedMessage[i]);
    }
    
    decodeMessage(encryptedMessage); // Call function to decode
    
    return 0;
}
