#include <stdio.h> //Include standard input and output library 
#include <stdlib.h> // Include standard library functions 
#include <string.h> // Include string library
#include <stdbool.h> //Include boolean library 

#include "constants.h" // Include custom header file "constants.h" 
#include "functions.h" // Include custom header file "functions.h"

bool playWordGuessingGame(const char* randomWord) // Function for Hangman guessing game original (Part a) with input randomWord 
{
    int word_Length = strlen(randomWord); //Initialize variable word_Length as integer 
    char word_Res[word_Length + 1]; //Initialize variable word_Res as char arrary to store guessed word (+1 for null)
    int attempts = 1; //Initialize variable attempts as integer 
    char letter_guess; //Initialize variable letter_guess as char

    for (int i = 0; i < word_Length; i++) // for loop that converts the letters in word_Res into dashes
	{
        word_Res[i] = '-';
    }
    word_Res[word_Length] = '\0'; // Add null character to the end of the arrary

    while ((attempts -1) < MAX_ATTEMPTS) // While loop that runs until the user goes over the Max amount of attempts
	{
        printf("\nAttempt %d: ", attempts); // Displays the current attempt the user is on 
        scanf("%c", &letter_guess); // The users guess
		while (getchar() != '\n') continue; //Ensures that no other chracter besides a integer is inputed by clearing that input scan so it does not store (From TA).

		bool guess_flag = false; // Checks if each time the user completes an attempt if thier guess is right or wrong
        for (int i = 0; i < word_Length; i++)  // For loop that checks if the letter is in the word 
		{
            if (randomWord[i] == letter_guess) 
			{
                word_Res[i] = letter_guess;
                guess_flag = true; // The users entered a correct letter
            }
        }
        
        printf("%s\n", word_Res); // Print the current state of the guessed word

        if (strcmp(word_Res, randomWord) == 0) // Checks if all letters were guessed correctly
		{
            return true;
        }

        // If the guess was incorrect, inform the user and increase the attempts count
        if (guess_flag == false) // Checks if the users guess was inccorect and informs them of thier mistake while moving on to the next attempt
		{
            printf("Incorrect guess. Try again.\n");
            attempts++;
        }

		if (guess_flag == true) // Checks if users enters a valid letter and infroms them 
		{
			printf("%c was a correct guess!\n", letter_guess);
        }
    }
    return false; // False if user does not guess the word
}

bool playWordGuessingGameAutomatic(const char* randomWord, char** words, int numWords, int numSuggestion) // Function for Automatic Hangman guessing game original (Part b) with input pointer randomWord, words, numWords, and numSuggestion
{
    int word_Length = strlen(randomWord); //Initialize variable word_Length as integer 
    char word_Res[word_Length + 1]; //Initialize variable word_Res as char arrary to store guessed word (+1 for null)
    int attempts = 1; //Initialize variable attempts as integer 
    char letter_guess; //Initialize variable letter_guess as char

    bool suggestion_Flag = true; //Initialize variable suggestion_Flag as boolean 
    bool similar_Word_Flag; //Initialize variable similar_Word_Flag as boolean 
    int num_Word_Suggest = 0; //Initialize variable num_Word_Suggest as integer
    char word_Suggestions[numSuggestion][word_Length + 1]; //Initialize variable word_Suggestions as char arrary to store the suggested words and the amount (+1 for null)

    for (int i = 0; i < word_Length; i++) // for loop that converts the letters in word_Res into dashes
	{
        word_Res[i] = '-';
    }
    word_Res[word_Length] = '\0'; // Add null character to the end of the arrary

    while ((attempts -1) < MAX_ATTEMPTS) // While loop that runs until the user goes over the Max amount of attempts
	{
        printf("\nAttempt %d: ", attempts); // Displays the current attempt the user is on 
        scanf("%c", &letter_guess); // The users guess
		while (getchar() != '\n') continue; //Ensures that no other chracter besides a integer is inputed by clearing that input scan so it does not store (From TA).

		bool guess_flag = false; // Checks if each time the user completes an attempt if thier guess is right or wrong
        for (int i = 0; i < word_Length; i++)  // For loop that checks if the letter is in the word 
		{
            if (randomWord[i] == letter_guess) 
			{
                word_Res[i] = letter_guess;
                guess_flag = true; // The users entered a correct letter
            }
        }
        
        printf("%s\n", word_Res); // Print the current state of the guessed word

        if (strcmp(word_Res, randomWord) == 0) // Checks if all letters were guessed correctly
		{
            return true;
        }

        // If the guess was incorrect, inform the user and increase the attempts count
        if (guess_flag == false) // Checks if the users guess was inccorect and informs them of thier mistake while moving on to the next attempt
		{
            printf("Incorrect guess. Try again.\n");
            attempts++;
        }

		if (guess_flag == true) // Checks if users enters a valid letter and infroms them 
		{
			printf("%c was a correct guess!\n", letter_guess);
        }

        if (attempts == MAX_ATTEMPTS && suggestion_Flag == true) // If statement for the last attempt to give them suggestions 
        {
            const char* guessed = word_Res; // Variable for how the current attempt looks like

            for (int m = 0; m < numWords; m++) // Loop for all the possible words 
            {
                if (strlen(words[m]) == word_Length) // Checks if they are the same length 
                {
                    for (int n = 0; n < word_Length; n++) // Loop to check if they have similar letters with spaces
                    {
                        if (guessed[n] != '-' && guessed[n] != words[m][n]) // Checks if the word is not similar with the selected word
                        {
                            similar_Word_Flag = false; // Flag to check if it is similar 
                            break;
                        }
                    }
                    if (similar_Word_Flag == true) // If statement to check if the word is similar 
                    {
                        if (num_Word_Suggest < numSuggestion) // Checks if the num of possible words is over the limit 
                        {
                            strcpy(word_Suggestions[num_Word_Suggest], words[m]); // stores the possible word in the arrary 
                            num_Word_Suggest++;   
                        }
                    }
                }
                similar_Word_Flag = true; // Reset similar_Word_Flag for each iteration
            }

            printf("\nThe number of possible words = %d\n", num_Word_Suggest);
            printf("Here is up to the first %d possible words:\n", numSuggestion);
            for (int i = 0; i < num_Word_Suggest && i < numSuggestion; i++) // foor loop to display all the words 
            {
                printf("%s\n", word_Suggestions[i]);
            }
            suggestion_Flag = false; // Flag to ensures that the number possible words does not appear agian each time they complete an attempt
        }
    }
    return false; // False if user does not guess the word
}
