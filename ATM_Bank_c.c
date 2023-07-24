#include <stdio.h> // inits stdio library for basic functions and statements
#include <math.h>  // inits math library for calculations

int main()
{
    int userSelection;   // inits variable to store user's menu selection
    int initialLoop = 0; // inits var for # of accs loop
    int initialInt = 0; // imits var for interest loop

    float inRate;      // inits interest rate
    float userDeposit; // inits variable to store users deposit
    float userWith;       // inits user withdraw amount
    float numYears;    // inits user's desired amnt of users for calculation
    int userAccs;      // inits empty int to hold user # of accounts
    float userAccsF;
    int switchAcc = 0; // inits default bank balance to account 1
    int uR = 1;

    while (initialLoop == 0)
    { // loop to ask user for # of accounts until valid input is given e.t.c non negative value
        printf("Please enter the amount of account(s): ");
        scanf("%f", &userAccsF);
        if (userAccsF > 0 && userAccsF <= 10)
        { // checks if user entered a valid input for accouns greater than 0
            // User entered a float
            userAccs = (int)round(userAccsF); // rounds the input so if they entered a float i.e 2.3, it rounds down to 2 accounts and if whole float is entered it's taken as it is
            break;
        } else if (userAccsF > 10) {
            printf("Max accounts you can have is 10...\n");
        }
        else
        {
            printf("You must have at least one account...\n");
        }
    }

    float accBalances[userAccs];
    for (int i = 0; i < userAccs; i++)
    { // for loop to loop thru the amount of accs and ask for each account balance
        float accAmnt;
        printf("Enter balance for account %d: $", i + 1);
        scanf("%f", &accAmnt);
        while (accAmnt < 0)
        { // checks to see if user added a valid deposit value, loops until they do
            printf("Please enter a positive value...\n");
            printf("Enter balance for account %d: $", i + 1);
            scanf("%f", &accAmnt);
        }
        accBalances[i] = accAmnt;
    }

    while (1)
    {
        printf("Current Account: %d - Balance: $%.2f \nSelect an operation: \n 1. Deposit \n 2. Withdraw \n 3. Check Balance \n 4. Future Balance Using Interest Rate \n 5. Switch Account \n 6. Display All Balances \n 0. Exit \n-> ", (switchAcc + 1), accBalances[switchAcc]); // prompts user with main menu options
        scanf("%d", &userSelection);                                                                                                                                                               // reads the input

        switch (userSelection)
        {
        case 5:
            printf("You have %d accounts\n", userAccs);
            printf("Which account would you like to switch to: ");
            scanf("%d", &uR);
            if (uR <= 0 && switchAcc != 0)
            {
                printf("You cannot switch to an account you do not have...\n");
                switchAcc = switchAcc;
            }
            else if (uR > userAccs)
            {
                printf("You cannot switch to an account you do not have...\n");
            }
            else if (uR >= 1 && uR <= userAccs)
            {
                switchAcc = uR-1;
            } else if (uR <= 0 && switchAcc == 0) {
                printf("Account 0 does not exist or you've entered a negative value...\n");
            }
            break;
        case 6:
            for (int i = 0; i < userAccs; i++)
            { // for loop to loop over balances
                printf("[Account %d Balance: $%.2f]\n", i + 1, accBalances[i]);
            }
            break;
        case 0: // if 0 input is entered the program quits
            return 0;
        case 3:
            printf("Your balance for account %d: $%.2f \n", switchAcc + 1, accBalances[switchAcc]); // prints balance in float with two rounded decimal places
            break;
        case 2:
            printf("Select Withdrawal Amount: $"); // prompts user to choose withdraw amnt
            scanf("%f", &userWith);                   // reads the input
            if (userWith > accBalances[switchAcc])    // checks to see if withdraw amnt is greater than their balance
            {
                printf("You cannot withdraw greater than your balance!\n");                                       // resets back to main menu after
            }
            else if (userWith <= 0)
            {
                printf("Please enter a positive value...\n");
            }
            else if (accBalances[switchAcc] >= userWith) // if they have the balance to do so, they can withdraw
            {
                accBalances[switchAcc] -= userWith; // withdraw amnt removed from user balance
                printf("You withdrew $%.2f.\n", userWith);
            }
            break;
        case 1:
            printf("Select Deposit Amount: $");
            if ((scanf("%f", &userDeposit) == 1) && userDeposit > 0) // error handling to make sure deposit amnt is positive
            {
                accBalances[switchAcc] += userDeposit;
                printf("Deposited $%.2f\n", userDeposit);
            }
            else if (userDeposit <= 0)
            {
                printf("Please enter a positive value...\n");
            }
            break;
        case 4: // interest calculation

            while (initialInt == 0) // loop to keep asking for interest rate until a valid input is entered
            {
                printf("Set your desired interest rate: "); // asks for the rate
                scanf("%f", &inRate);                       // reads the input
                if (inRate > 0 && inRate < 1)
                {
                    printf("You've set your interest rate to: %.2f percent\n", (inRate * 100));
                    float const inRate = inRate;
                    initialInt = 1; // if the rate is valid loop exits
                }
                else if (inRate <= 0)
                { // invalid rate  such as negative or 0 results in a continous loop until a valid rate is entered
                    printf("Please enter a positive value...\n");
                }
                else if (inRate >= 1)
                {
                    printf("Interest rate cannot be more than 100%%...\n");
                }
            }
            printf("Enter number amount of years for interest calculation: "); // asks user for amnt of years
            scanf("%f", &numYears);                                            // reads the input
            if (numYears <= 0)                                                 // error handling for invalid input
            {
                printf("Please enter a value greater than 0...\n");
            }
            else if (numYears > 0) // checks for valid input
            {
                float interestCalc = accBalances[switchAcc] * pow((1 + (inRate)), numYears); // does the calculation with the interest formula
                printf("Your balance in %.2f year(s) with an interest rate of %.2f percent is: $%.2f\n", numYears, inRate, interestCalc);
            }
            break;
        default:
            printf("Please choose a valid option from the menu...\n"); // default error handling when they chose an invalid from the menu
        }
    }
}