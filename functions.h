#ifndef FUNCTIONS_H
#define FUNCTIONS_H

bool playWordGuessingGame(const char* randomWord); // Function for Hangman guessing game original (Part a) with input pointer randomWord.
bool playWordGuessingGameAutomatic(const char* randomWord, char** words, int numWords, int numSuggestion); // Function for Automatic Hangman guessing game original (Part b) with input pointer randomWord, words, numWords, and numSuggestion

#endif