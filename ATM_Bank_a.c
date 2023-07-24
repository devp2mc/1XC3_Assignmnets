#include <stdio.h> // inits stdio library for basic functions and statements
int main()
{
    float userBank = 0;    // inits user initial bank balance to 0 as a float
    int initialLoop = 0;   // default loop to run initial deposit
    int userSelection; // inits variable to store user's menu selection

    float userDeposit; // inits variable to store users initial deposit as a float
    float userBal;     // inits user balance initial deposit
    float withD;       // inits user withdrawal amount

    while (initialLoop == 0) // loop to keep asking user for initial balance until a valid input is entered
    {
        printf("Set your initial balance: $"); // asks for initial balance
        scanf("%f", &userBal);
        if (userBal > 0)
        {
            userBank += userBal;
            initialLoop = 1;
        }
        else if (userBal <= 0) // error handling for negative values
        {
            printf("Please enter a positive value...\n");
        }
    }

    while (1) // main program loop
    {
        printf("Select an operation: \n 1. Deposit \n 2. Withdraw \n 3. Check Balance \n 0. Exit \n-> "); // prompts user with main menu options
        scanf("%d", &userSelection);                                                                      // reads the input

        switch (userSelection)
        {
        case 0: // if 0 input is entered the program quits
            return 0;
        case 3:
            printf("Your balance: $%.2f \n", userBank); // prints balance in float with two rounded decimal places
            break;
        case 2:
            printf("Select Withdrawal Amount: $"); // prompts user to choose withdrawal amnt
            scanf("%f", &withD);                   // reads the input
            if (withD > userBank)                  // checks to see if withdrawal amnt is greater than their balance
            {
                printf("You cannot withdraw greater than your balance!\n"); // doesn't allow withdrawal if so                                        // resets back to main menu after
            }
            else if (withD <= 0)
            {
                printf("Please enter a positive value...\n");
            }
            else if (userBank >= withD) // if they have the balance to do so, they can withdraw
            {
                userBank -= withD; // withdraw amnt removed from user balance
                printf("You withdrew $%.2f.\n", withD);
            }
            break;
        case 1:
            printf("Select Deposit Amount: $");
            if ((scanf("%f", &userDeposit) == 1) && userDeposit > 0) // error handling to make sure deposit amnt is positive
            {
                userBank += userDeposit;
                printf("Deposited $%.2f\n", userDeposit);
            }
            else if (userDeposit <= 0)
            {
                printf("Please enter a positive value...\n");
            }
            break;
        default: // error handling when they did not choose a valid menu option
            printf("Please choose from the following options...\n");
        }
    }
}