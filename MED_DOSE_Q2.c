 // MORSE DECODER.

 #include <stdio.h>
#include <string.h>

// Structure to store Morse code and its corresponding letter/number
struct MorseMap {
    char *code;
    char symbol;
};

// Morse code dictionary (letters A-Z and numbers 0-9)
struct MorseMap morseDictionary[] = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'},
    {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'},
    {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'}, {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
    {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'},
    {"----.", '9'}, {"/", ' '}  // '/' represents space between words
};

// Number of entries in our dictionary
int dictionarySize = sizeof(morseDictionary)/sizeof(morseDictionary[0]);

// Function to find the letter/number for a Morse code
char findMorseMatch(char *morse) {
    for(int i = 0; i < dictionarySize; i++) {
        if(strcmp(morse, morseDictionary[i].code) == 0) {
            return morseDictionary[i].symbol;
        }
    }
    return '?'; // Return '?' if Morse code not found
}

int main() {
    char morseMessage[500];  // To store the input Morse code
    char currentCode[10];    // Temporary storage for each Morse character
    int codePosition = 0;    // Position in currentCode
    
    printf("Enter Morse code (use '.' for dot, '-' for dash, space between letters, '/' between words):\n");
    fgets(morseMessage, sizeof(morseMessage), stdin);
    
    // Remove the newline character from input
    morseMessage[strcspn(morseMessage, "\n")] = '\0';
    
    printf("Decoded message:\n");
    
    // Process each character in the Morse message
    for(int i = 0; morseMessage[i] != '\0'; i++) {
        if(morseMessage[i] == ' ' || morseMessage[i] == '/') {
            // When we find a space or slash, decode the current Morse character
            if(codePosition > 0) {
                currentCode[codePosition] = '\0'; // End the string
                printf("%c", findMorseMatch(currentCode));
                codePosition = 0; // Reset for next Morse character
            }
            
            // Print space if we found a word separator
            if(morseMessage[i] == '/') {
                printf(" ");
            }
        } 
        else if(morseMessage[i] == '.' || morseMessage[i] == '-') {
            // Build the current Morse character
            if(codePosition < sizeof(currentCode) - 1) {
                currentCode[codePosition++] = morseMessage[i];
            }
        }
    }
    
    // Decode the last Morse character if there is one
    if(codePosition > 0) {
        currentCode[codePosition] = '\0';
        printf("%c", findMorseMatch(currentCode));
    }
    
    printf("\n");
    return 0;
}