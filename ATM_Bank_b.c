# include <stdio.h> //Include standard input and output library 
# include <stdbool.h> //Include boolean library 
# include <math.h> //Include math library 

int main() //Main function
{
  int options = 0; //Initialize variable options as integer 
  float balance = 0.0; //Initialize variable balance as float
  float interest_Rate = 0.0; //Initialize variable interrest_Rate as float
  int years = 0; //Initialize variable years as integer

  printf("Welcome to the banking system\n"); //Introduces system 

  while(1) //While loop that will run repeatedly until the user inputs a valid rate
  {
    printf("Please enter your desired interest rate: ");

    if (scanf("%f", &interest_Rate) == 1 && interest_Rate >= 0) //Checks if input is correct type and is not negative
    {
      break;
    }
    else
    {
      printf("Invalid interest rate. Please try again.\n\n"); //Error message
    }
  }

  while(1) //While loop that will run repeatedly until the user inputs a valid balance 
  {
    printf("Please enter your starting balance: ");

    if (scanf("%f", &balance) == 1 && balance >= 0) //Checks if input is correct type and is not negative
    {
      break;
    }
    else
    {
      printf("Invalid balance. Please try again.\n\n"); //Error message
    }
  }

  while(1) //While loop that will run repeatedly until the user inputs a valid operation
  {
    printf("\nSelect an operation:\n"); //Different options user can select 
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Future Balance Using Interest Rate\n");
    printf("0. Exit\n");

    printf("Please select the option you would like to proceed with by entering the number: ");
    scanf("%d", &options); //Scans for the operation that user has input
    while (getchar() != '\n') continue; //Ensures that no other chracter besides a integer is inputed by clearing that input scan so it does not store (From TA).

    switch(options) //A switch that alocates the user to the operation based on cases that are determined by user input 
    {
      case 1: //Case for deposit 
      {
        float amount; //Variable for the amount the user wants to deposit 
        printf("\nPlease enter the amount you would like to deposit: ");
        scanf("%f", &amount);

        if (amount >= 0) //Condtion to check if deposit is not negative
        {
          balance = balance + amount; //EQ for deposit
          printf("Deposit successful. You have deposited, $%.2f\n", amount);
        }
        else
        {
          printf("Deposit unsuccessful. Invalid entry\n"); //Error message
        }
        break;
      }
      case 2: //Case for withdraw
      {
        float amount; //Variable for the amount the user wants to withdraw
        printf("\nPlease enter the amount you would like to withdraw: ");
        scanf("%f", &amount);

        if (balance >= amount && amount >= 0) //Condtion to ensure that the user can withdraw form balance
        {
          balance = balance - amount; //EQ for withdrawing
          printf("Withdrawal successful. You have withdrawn, $%.2f\n", amount);
        }
        else
        {
           printf("Insufficient balance or invalid withdraw request. Withdrawal unsuccessful.\n"); //Error message
        }
        break;
      }
      case 3: //Case for balance
      {
        printf("\nYour current balance is: $%.2f\n", balance); //Displays balance rounded to 2 decimal places
        break;
      }
      case 4: //Case for future balance
      {
        printf("\nPlease enter the number of years you would like to compund: ");
        scanf("%d", &years);
        while (getchar() != '\n') continue;

        if (years >= 0) //If statement to check if user inputs negative years
        {
          float future_Balance = balance * pow((1 + interest_Rate), years); //EQ for future balance
          printf("The future balance after %d year(s) with an interest rate of %.2f will be $%.2f\n", years, interest_Rate, future_Balance); //Displays results with input information
        }
        else
        {
          printf("Invalid entry. Please try again\n"); //Error message
        }
        break;
      }
      case 0: //Case for existing system 
      {
        printf("\nYou have now existed the system. Thank you for using the Banking System!\n");
        return 0; //Ends code 
      }
      default: //deafult case if the user enters an incorrect value 
      {
        printf("\nInvalid entry. Please try again.\n"); //Error message
        break;
      }
    }
  }
  return 0; //Ends code 
}
