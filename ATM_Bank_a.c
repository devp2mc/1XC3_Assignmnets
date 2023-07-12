# include <stdio.h>
# include <stdbool.h>

int main() 
{
  int options; //Initialize variable options as integer 
  float balance = 0.0;

  printf("Welcome to the banking system\n");

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
        balance = balance + amount;
        printf("Deposit successful. You have deposited, $%.2f\n", amount);
        break;

      }
      case 2:
      {
        float amount;
        printf("\nPlease enter the amount you would like to withdraw: ");
        scanf("%f", &amount);

        if (balance >= amount)
        {
          balance = balance - amount;
          printf("Withdrawal successful. You have withdrawn, $%.2f\n", amount);
        }
        else
        {
           printf("Insufficient balance. Withdrawal unsuccessful.\n");
        }
        break;
      }
      case 3:
      {
        printf("\nYour current balance is: $%.2f\n", balance);
        break;
      }
      case 0:
      {
        printf("\nYou have now existed the system. Thank you for using the Banking System!");
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
