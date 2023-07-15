# include <stdio.h>
# include <stdbool.h>
# include <math.h>

# define MAX_ACCOUNTS 10

int main() 
{
  int options = 0; 
  float balance = 0.0;
  float interest_Rate = 0.0 ;
  int years = 0;
  float balances[MAX_ACCOUNTS];
  int num_of_Acc = 0;
  int account_Num = 0;

  printf("Welcome to the banking system\n");
  while(1)
  {
    printf("Please enter the number of accounts you have (MAX 10): ");
    scanf("%d", &num_of_Acc);
    while (getchar() != '\n') continue;

    if (MAX_ACCOUNTS >= num_of_Acc && num_of_Acc >= 0)
    {
      break;
    }
    else
    {
      printf("Invalid entry. Please try again\n");
    }
  }

  for (int i = 0; i < num_of_Acc; i++)
  {
    while(1)
    {
      printf("Please enter your balance for the account #%d: ", 1+i);
      scanf("%f", &balances[i]);

      if (balances[i] >= 0)
      {
        break;
      }
      else
      {
        printf("Invalid entry. Please try again\n");
      }
    }

  }

  while(1)
  {
    printf("\nSelect an operation:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Future Balance Using Interest Rate\n");
    printf("5. Switch Account\n");
    printf("6. Display All Balances\n");
    printf("0. Exit\n");

    printf("Please select the option you would like to proceed with by entering the number: ");
    scanf("%d", &options);
    while (getchar() != '\n') continue;

    switch(options)
    {
      case 1:
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
          printf("Deposit unsuccessful. Invalid entry\n");
        }
        break;
      }
      case 2:
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
           printf("Insufficient balance or invalid withdraw request. Withdrawal unsuccessful.\n");
        }
        break;
      }
      case 3:
      {
        printf("\nYour current balance is: $%.2f\n", balances[account_Num]);
        break;
      }
      case 4:
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
            printf("Invalid interest rate. Please try again.\n");
          }
        }

        printf("Please enter the number of years you would like to compund: ");
        scanf("%d", &years);
        while (getchar() != '\n') continue;

        if (years >= 0)
        {
          float future_Balance = balances[account_Num] * pow((1 + interest_Rate), years);
          printf("The future balance after %d year(s) with an interest rate of %f will be $%.2f\n", years, interest_Rate, future_Balance);
        }
        else
        {
          printf("Invalid entry. Please try again\n");
        }
        break;
      }
      case 5:
      {
        printf("\nPlease enter the account number you would like to swtich to: ");
        scanf("%d", &account_Num);
        while (getchar() != '\n') continue;

        if (num_of_Acc >= account_Num && account_Num >= 0)
        {
          printf("You account has now been switched to account #%d\n", account_Num);
          account_Num -= 1; 
        }
        else
        {
          printf("Invalid entry. Please try again\n");
        }
        break;
      }
      case 6:
      {
        printf("\nYour account balances for all accounts:\n");
        for (int i = 0; i < num_of_Acc; i++) 
        {
          printf("Account #%d: $%.2f\n", i + 1, balances[i]);
        }
        break;
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
