#include <stdio.h>

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[0;32m");
}

void cyan () {
  printf("\033[0;36m");
}

void reset () {
  printf("\033[0m");
}

void purple () {
  printf("\033[0;35m");
}

int main() {

int option;
int balance = 66;
int temp_withdraw;
int pin = 4567;
int temp_pin;
int deposit;
int loop = 1;

while(loop) {
  purple();
  printf("\n |  !!!Welcome To Swiss Bank!!!    |\n");
  reset();
  printf(" |                                 |\n");
  cyan();
  printf(" |  1.Balance Enquiry              |\n");
  printf(" |  2.Withdraw amount              |\n");
  printf(" |  3.Change pin                   |\n");
  printf(" |  4.Deposit amount               |\n");
  printf(" |  5.Exit                         |\n");
  red();
  printf("\nChoose a Option: ");
  green();
  scanf("%d", &option);
  reset();
switch (option) {
  case 1:
     green();
     printf("\nYour Current Balance is: $%d\n", balance);
     break;
  case 2:
     cyan();
     printf("\nEnter the amount to withdraw: ");
     scanf("%d", &temp_withdraw);
     if(temp_withdraw < balance) {
       printf("Enter the pin: ");
       scanf("%d", &temp_pin);
       if(pin == temp_pin) {
          green();
          printf("\nSuccessfully withdrawn: $%d", temp_withdraw);
          balance = balance - temp_withdraw;
          printf("\nCurrent Balance is: $%d\n", balance);
       } else {
          red();
          printf("\nPin is Wrong\n");
       }
     } else {
       red();
       printf("\nAmount Should be lesser than Current Balance\n");
     }
     break;
  case 3:
     cyan();
     printf("Enter the Previous pin: ");
     scanf("%d", &temp_pin);
     if(pin == temp_pin) {
        printf("Enter the New pin: ");
        scanf("%d", &pin);
        green();
        printf("\nSuceessfully PIN changed\n");
     } else {
        red();
        printf("\nIncorrect Previous pin\n");
     }
     break;
  case 4:
     cyan();
     printf("\nEnter the Deposit amount: ");
     scanf("%d", &deposit);
     balance = balance + deposit;
     green();
     printf("\nDeposit of $%d is Success", deposit);
     printf("\nCurrent Balance is: $%d\n", balance);
     break;
  case 5:
     loop = 0;
     green();
     printf("\nThank you for using Swiss Bank!\n");
     break;
  default:
     red();
     printf("\nIncorrect option\n");
}
}

return 0;
}
