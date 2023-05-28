#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    int accountNumber;
    char name[100];
    float balance;
};

void createAccount(struct Customer *customers, int *count) {
    if (*count >= 100) {
        printf("Customer database is full. Cannot create more accounts.\n");
        return;
    }

    struct Customer newCustomer;

    printf("Enter customer details:\n");
    printf("Account Number: ");
    scanf("%d", &newCustomer.accountNumber);
    printf("Customer Name: ");
    scanf(" %[^\n]", newCustomer.name);
    printf("Initial Balance: ");
    scanf("%f", &newCustomer.balance);

    customers[*count] = newCustomer;
    (*count)++;

    printf("Account created successfully.\n");
}

void deposit(struct Customer *customers, int count) {
    int accountNumber;
    float amount;
    int found = 0;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < count; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);

            customers[i].balance += amount;
            printf("Amount deposited successfully.\n");
            printf("Updated balance: %.2f\n", customers[i].balance);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void withdraw(struct Customer *customers, int count) {
    int accountNumber;
    float amount;
    int found = 0;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < count; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > customers[i].balance) {
                printf("Insufficient balance.\n");
            } else {
                customers[i].balance -= amount;
                printf("Amount withdrawn successfully.\n");
                printf("Updated balance: %.2f\n", customers[i].balance);
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void viewBalance(struct Customer *customers, int count) {
    int accountNumber;
    int found = 0;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < count; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Customer Name: %s\n", customers[i].name);
            printf("Current Balance: %.2f\n", customers[i].balance);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

int main() {
    struct Customer customers[100];
    int count = 0;
    int choice;

    printf("Bank Management System\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Create an account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount(customers, &count);
                break;
            case 2:
                deposit(customers, count);
                break;
            case 3:
                withdraw(customers, count);
                break;
            case 4:
                viewBalance(customers, count);
                break;
            case 5:
                printf("Thank you for using the bank management system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}