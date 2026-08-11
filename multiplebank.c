#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int accNo[100];
int pin[100];
char name[100][50];
float balance[100];

int transaction[100][5];
int txnCount[100];

int accCount = 0;

int findAccount(int number)
{
    for (int i = 0; i < accCount; i++)
    {
        if (accNo[i] == number)
        {
            return i;
        }
    }

    return -1;
}

void addTransaction(int index, int amount)
{
    if (txnCount[index] < 5)
    {
        transaction[index][txnCount[index]] = amount;
        txnCount[index]++;
    }
    else
    {
        for (int i = 1; i < 5; i++)
        {
            transaction[index][i - 1] = transaction[index][i];
        }

        transaction[index][4] = amount;
    }
}

void createAccount()
{
    int index = accCount;

    printf("Enter Name: ");
    scanf("%s", name[index]);

    printf("Enter PIN: ");
    scanf("%d", &pin[index]);

    printf("Enter Initial Balance: ");
    scanf("%f", &balance[index]);

    accNo[index] = rand() % 9000 + 1000;

    txnCount[index] = 0;

    accCount++;

    printf("Account Created Successfully!\n");
    printf("Your Account Number: %d\n", accNo[index]);
}

void checkBalance()
{
    int number;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1)
    {
        printf("Account Not Found!\n");
    }
    else
    {
        printf("Balance = %.2f\n", balance[index]);
    }
}

void deposit()
{
    int number;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1)
    {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    if (amount > 0)
    {
        balance[index] = balance[index] + amount;

        addTransaction(index, amount);

        printf("Deposit Successful!\n");
        printf("New Balance = %.2f\n", balance[index]);
    }
    else
    {
        printf("Invalid Amount!\n");
    }
}

void withdraw()
{
    int number;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1)
    {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter Withdraw Amount: ");
    scanf("%f", &amount);

    if (amount > 0)
    {
        if (amount <= balance[index])
        {
            balance[index] = balance[index] - amount;

            addTransaction(index, -amount);

            printf("Withdrawal Successful!\n");
            printf("New Balance = %.2f\n", balance[index]);
        }
        else
        {
            printf("Insufficient Balance!\n");
        }
    }
    else
    {
        printf("Invalid Amount!\n");
    }
}

void transfer()
{
    int sender, receiver;
    float amount;

    printf("Enter Sender Account Number: ");
    scanf("%d", &sender);

    int senderIndex = findAccount(sender);

    if (senderIndex == -1)
    {
        printf("Sender Account Not Found!\n");
        return;
    }

    printf("Enter Receiver Account Number: ");
    scanf("%d", &receiver);

    int receiverIndex = findAccount(receiver);

    if (receiverIndex == -1)
    {
        printf("Receiver Account Not Found!\n");
        return;
    }

    printf("Enter Transfer Amount: ");
    scanf("%f", &amount);

    if (amount > 0 && amount <= balance[senderIndex])
    {
        balance[senderIndex] =
            balance[senderIndex] - amount;

        balance[receiverIndex] =
            balance[receiverIndex] + amount;

        addTransaction(senderIndex, -amount);
        addTransaction(receiverIndex, amount);

        printf("Transfer Successful!\n");
    }
    else
    {
        printf("Invalid Amount or Insufficient Balance!\n");
    }
}

void miniStatement()
{
    int number;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1)
    {
        printf("Account Not Found!\n");
        return;
    }

    printf("\n----- MINI STATEMENT -----\n");

    printf("Account Number : %d\n", accNo[index]);
    printf("Account Holder : %s\n", name[index]);
    printf("Balance        : %.2f\n", balance[index]);

    printf("\nTransactions:\n");

    for (int i = 0; i < txnCount[index]; i++)
    {
        if (transaction[index][i] >= 0)
        {
            printf("Credit : %d\n",
                   transaction[index][i]);
        }
        else
        {
            printf("Debit  : %d\n",
                   -transaction[index][i]);
        }
    }
}

void changePin()
{
    int number;
    int oldPin;
    int newPin;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1)
    {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter Old PIN: ");
    scanf("%d", &oldPin);

    if (oldPin == pin[index])
    {
        printf("Enter New PIN: ");
        scanf("%d", &newPin);

        pin[index] = newPin;

        printf("PIN Changed Successfully!\n");
    }
    else
    {
        printf("Incorrect PIN!\n");
    }
}

void accountDetails()
{
    int number;

    printf("Enter Account Number: ");
    scanf("%d", &number);

    int index = findAccount(number);

    if (index == -1)
    {
        printf("Account Not Found!\n");
        return;
    }

    printf("\n----- ACCOUNT DETAILS -----\n");

    printf("Account Number : %d\n", accNo[index]);
    printf("Account Holder : %s\n", name[index]);
    printf("Balance        : %.2f\n", balance[index]);
}

int main()
{
    int choice;
     int index = accCount;
     printf("------PHONE BANK---------\n");

    printf("Enter Name: ");
    scanf("%s", name[index]);

    printf("Enter PIN: ");
    scanf("%d", &pin[index]);

    printf("Enter Initial Balance: ");
    scanf("%f", &balance[index]);

    accNo[index] = rand() % 9000 + 1000;

    txnCount[index] = 0;

    accCount++;

    printf("Account Created Successfully!\n");
    printf("Your Account Number: %d\n", accNo[index]);

    

    srand(time(NULL));

    do
    {
        printf("\n========== BANK SYSTEM ==========\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Transfer\n");
        printf("6. Mini Statement\n");
        printf("7. Change PIN\n");
        printf("8. Account Details\n");
        printf("9. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                checkBalance();
                break;

            case 3:
                deposit();
                break;

            case 4:
                withdraw();
                break;

            case 5:
                transfer();
                break;

            case 6:
                miniStatement();
                break;

            case 7:
                changePin();
                break;

            case 8:
                accountDetails();
                break;

            case 9:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 9);

    return 0;
}