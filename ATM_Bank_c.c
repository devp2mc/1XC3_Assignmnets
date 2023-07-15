# include <stdio.h> //Include standard input and output library 
# include <stdbool.h> //Include boolean library 
# include <math.h> //Include math library 

# define MAX_ACCOUNTS 10 //Defines Max_Accounts as set variable 10

int main() //Main function
{
  int options = 0; //Initialize variable options as integer 
  float interest_Rate = 0.0; //Initialize variable interrest_Rate as float
  int years = 0; //Initialize variable years as integer
  float balances[MAX_ACCOUNTS]; //Initialize arrary with float elemtns and maximum of 10 elements
  int num_of_Acc = 0; //Initialize variable num_of_acc as integer 
  int account_Num = 0; //Initialize variable account_Num as integer

  printf("Welcome to the banking system\n"); //Introduces system 

  while(1) //While loop that will run repeatedly until the user inputs a valid number of accounts
  {
    printf("Please enter the number of accounts you have (MAX 10): ");
    scanf("%d", &num_of_Acc);
    while (getchar() != '\n') continue; //Ensures that no other chracter besides a integer is inputed by clearing that input scan so it does not store (From TA).

    if (MAX_ACCOUNTS >= num_of_Acc && num_of_Acc >= 0) //Checks if number of accounts does not reach limit and if input is not negative
    {
      break;
    }
    else
    {
      printf("Invalid entry. Please try again\n"); //Error message
    }
  }

  for (int i = 0; i < num_of_Acc; i++) //For loop that allows the user to input balances into each of thier accounts
  {
    while(1)
    {
      printf("Please enter your balance for the account #%d: ", 1+i);
      scanf("%f", &balances[i]);

      if (balances[i] >= 0) //Checks if balance is negative 
      {
        break;
      }
      else
      {
        printf("Invalid entry. Please try again\n"); //Error message
      }
    }

  }

  while(1) //While loop that will run repeatedly until the user inputs a valid operation
  {
    printf("\nSelect an operation:\n"); //Different options user can select 
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Future Balance Using Interest Rate\n");
    printf("5. Switch Account\n");
    printf("6. Display All Balances\n");
    printf("0. Exit\n");

    printf("Please select the option you would like to proceed with by entering the number: ");
    scanf("%d", &options); //Scans for the operation that user has input
    while (getchar() != '\n') continue; //Ensures that no other chracter besides a integer is inputed by clearing that input scan so it does not store (From TA).

    switch(options) //A switch that alocates the user to the operation based on cases that are determined by user input 
    {
      case 1: //Case for deposit 
      {
        float amount;
        printf("\nPlease enter the amount you would like to deposit: ");
        scanf("%f", &amount);

        if (amount >= 0)
        {
          balances[account_Num] = balances[account_Num] + amount;
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
        float amount;
        printf("\nPlease enter the amount you would like to withdraw: ");
        scanf("%f", &amount);

        if (balances[account_Num] >= amount && amount >= 0)
        {
          balances[account_Num] = balances[account_Num] - amount;
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
        printf("\nYour current balance is: $%.2f\n", balances[account_Num]);
        break;
      }
      case 4: //Case for future balance 
      {
        while(1)
        {
          printf("\nPlease enter your desired interest rate: ");

          if (scanf("%f", &interest_Rate) == 1 && interest_Rate >= 0)
          {
            break;
          }
          else
          {
            printf("Invalid interest rate. Please try again.\n"); //Error message
          }
        }

        printf("Please enter the number of years you would like to compund: ");
        scanf("%d", &years);
        while (getchar() != '\n') continue;

        if (years >= 0) //If statement to check if user inputs negative years
        {
          float future_Balance = balances[account_Num] * pow((1 + interest_Rate), years); //EQ for future balance
          printf("The future balance after %d year(s) with an interest rate of %f will be $%.2f\n", years, interest_Rate, future_Balance); //Displays results with input information
        }
        else
        {
          printf("Invalid entry. Please try again\n"); //Error message
        }
        break;
      }
      case 5: //Case for swtiching accounts
      {
        printf("\nPlease enter the account number you would like to swtich to: ");
        scanf("%d", &account_Num);
        while (getchar() != '\n') continue;

        if (num_of_Acc >= account_Num && account_Num >= 0) //Condtion to check if the account number entered is an account they have 
        {
          printf("You account has now been switched to account #%d\n", account_Num);
          account_Num -= 1; //deacreses variable by 1 because arrary value starts at 0
        }
        else
        {
          printf("Invalid entry. Please try again\n"); //Error message
        }
        break;
      }
      case 6: //Case for all accounts balance
      {
        printf("\nYour account balances for all accounts:\n");
        for (int i = 0; i < num_of_Acc; i++) //For loop that displays all the balances for each account
        {
          printf("Account #%d: $%.2f\n", i + 1, balances[i]); //formating for each account with its balance 
        }
        break;
      }
      case 0: //Case for existing system 
      {
        printf("\nYou have now existed the system. Thank you for using the Banking System!\n");
        return 0; //ends code 
      }
      default: //deafult case if the user enters an incorrect value 
      {
        printf("\nInvalid entry. Please try again.\n"); //Error message
        break;
      }
    }
  }
  return 0; //ends code 
}
