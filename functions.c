#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "constants.h"
#include "functions.h"

bool playWordGuessingGame(const char* randomWord) 
{
    int wordLength = strlen(randomWord);
    char guessedWord[wordLength + 1]; // Store the guessed word with dashes and letters
    int attempts = 0;
    char guess;

    // Initialize guessedWord with dashes
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '-';
    }
    guessedWord[wordLength] = '\0';

    printf("The server has generated a random word. You have %d attempts to guess the word.\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: ", attempts + 1);
        scanf(" %c", &guess);

        // Check if the guessed letter is present in the randomWord
        bool correctGuess = false;
        for (int i = 0; i < wordLength; i++) {
            if (randomWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        // Print the current state of the guessed word
        printf("%s\n", guessedWord);

        // Check if all letters were guessed correctly
        if (strcmp(guessedWord, randomWord) == 0) {
            return true;
        }

        // If the guess was incorrect, inform the user and increase the attempts count
        if (!correctGuess) {
            printf("Incorrect guess. Try again.\n");
            attempts++;
        }
    }

    printf("Out of attempts. The word was: %s\n", randomWord);
    return false;
}
