#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "constants.h"
#include "functions.h"

bool playWordGuessingGame(const char* randomWord) 
{
    int word_Length = strlen(randomWord);
    char word_Res[word_Length]; // Store the guessed word with dashes and letters
    int attempts = 0;
    char letter_guess;

    // Initialize word_Res with dashes
    for (int i = 0; i < word_Length; i++) 
	{
        word_Res[i] = '-';
    }
    word_Res[word_Length] = '\0';

    printf("\nThe server has generated a random word. You have %d attempts to guess the word.\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) 
	{
        printf("\nAttempt %d: ", attempts + 1);
        scanf("%c", &letter_guess);
		while (getchar() != '\n') continue; //Ensures that no other chracter besides a integer is inputed by clearing that input scan so it does not store (From TA).

        // Check if the guessed letter is present in the randomWord
		bool guess_flag = false;
        for (int i = 0; i < word_Length; i++) 
		{
            if (randomWord[i] == letter_guess) 
			{
                word_Res[i] = letter_guess;
                guess_flag = 1;
            }
        }

        // Print the current state of the guessed word
        printf("%s\n", word_Res);

        // Check if all letters were guessed correctly
        if (strcmp(word_Res, randomWord) == 0) 
		{
            return true;
        }

        // If the guess was incorrect, inform the user and increase the attempts count
        if (guess_flag == false) 
		{
            printf("Incorrect guess. Try again.\n");
            attempts++;
        }
    }
    return false;
}
