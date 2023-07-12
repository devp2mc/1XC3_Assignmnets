# include <stdio.h>
# include <stdbool.h>
# include <math.h>

int main() 
{
  int options; //Initialize variable options as integer 
  float balance = 0.0;
  float interest_Rate = 0.0;
  int years;

  printf("Welcome to the banking system\n");

    while(1)
  {
    printf("Please enter your desired interest rate: ");

    if (scanf("%f", &interest_Rate) == 1 && interest_Rate >= 0)
    {
      break;
    }
    else
    {
      printf("Invalid interest rate. Please try again.\n\n");
    }
  }

  while(1)
  {
    printf("Please enter your starting balance: ");

    if (scanf("%f", &balance) == 1 && balance >= 0)
    {
      break;
    }
    else
    {
      printf("Invalid balance. Please try again.\n\n");
    }
  }

  while(1)
  {
    printf("\nSelect an operation:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Future Balance Using Interest Rate\n");
    printf("0. Exit\n");

    printf("Please select the option you would like to proceed with by entering the number: ");
    scanf("%d", &options);

    switch(options)
    {
      case 1:
      {
        float amount;
        printf("\nPlease enter the amount you would like to deposit: ");
        scanf("%f", &amount);

        if (amount >= 0)
        {
          balance = balance + amount;
          printf("Deposit successful. You have deposited, $%.2f\n", amount);
        }
        else
        {
          printf("Deposit unsuccessful. Invalid entry\n");
        }
        break;
      }
      case 2:
      {
        float amount;
        printf("\nPlease enter the amount you would like to withdraw: ");
        scanf("%f", &amount);

        if (balance >= amount && amount >= 0)
        {
          balance = balance - amount;
          printf("Withdrawal successful. You have withdrawn, $%.2f\n", amount);
        }
        else
        {
           printf("Insufficient balance or invalid withdraw request. Withdrawal unsuccessful.\n");
        }
        break;
      }
      case 3:
      {
        printf("\nYour current balance is: $%.2f\n", balance);
        break;
      }
      case 4:
      {
        printf("\nPlease enter the number of years you would like to compund: ");
        scanf("%d", &years);
        if (years >= 0)
        {
          float future_Balance = balance * pow((1 + interest_Rate), years);
          printf("The future balance after %d year(s) with an interest rate of %.2f will be $%.2f\n", years, interest_Rate, future_Balance);
        }
        else
        {
          printf("Invalid entry\n");
        }
      }
      case 0:
      {
        printf("\nYou have now existed the system. Thank you for using the Banking System!\n");
        return 0;
      }
      default:
      {
        printf("\nInvalid entry. Please try again.\n");
        break;
      }
    }
  }
  return 0;
}
