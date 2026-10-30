#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

#define MAX_ACCOUNTS 5

#define NAME_LENGTH 50

#define FILE_NAME "bank_accounts.dat"

 

typedef struct {

    int accountNo;

    char name[NAME_LENGTH];

    int pin;

    double balance;

} Account;

 

Account accounts[MAX_ACCOUNTS] = {

    {1001, "Aarav Sharma", 1234, 5000.00},

    {1002, "Priya Verma", 2345, 7500.00},

    {1003, "Rahul Patel", 3456, 6200.00}

};

int accountCount = 3;

 

/* Function prototypes */

int login(int *loggedInIndex);

void showMenu(void);

void checkBalance(const Account *account);

void deposit(Account *account);

void withdraw(Account *account);

void transfer(Account *sender);

void showAccount(const Account *account);

void showAllAccounts(void);

void saveAccounts(void);

void loadAccounts(void);

int findAccount(int accountNo);

void printLine(void);

 

int main(void) {

    int loggedInIndex = -1;

    int choice;

 

    loadAccounts();

 

    printf("\n====================================\n");

    printf("       SIMPLE BANKING SYSTEM V2\n");

    printf("====================================\n");

 

    if (!login(&loggedInIndex)) {

        printf("\nAccess denied. Too many incorrect attempts.\n");

        return 0;

    }

 

    do {

        showMenu();

        printf("Enter your choice: ");

 

        if (scanf("%d", &choice) != 1) {

            printf("Invalid input. Please enter a number.\n");

            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF) { }

            choice = 0;

            continue;

        }

 

        switch (choice) {

            case 1:

                checkBalance(&accounts[loggedInIndex]);

                break;

            case 2:

                deposit(&accounts[loggedInIndex]);

                break;

            case 3:

                withdraw(&accounts[loggedInIndex]);

                break;

            case 4:

                transfer(&accounts[loggedInIndex]);

                break;

            case 5:

                showAccount(&accounts[loggedInIndex]);

                break;

            case 6:

                showAllAccounts();

                break;

            case 7:

                saveAccounts();

                printf("Data saved. Thank you for using the system.\n");

                break;

            default:

                printf("Invalid choice. Select 1 to 7.\n");

        }

    } while (choice != 7);

 

    return 0;

}

 

int login(int *loggedInIndex) {

    int enteredId, enteredPin, attempts;

 

    for (attempts = 1; attempts <= 3; attempts++) {

        printf("\nEnter account number: ");

        if (scanf("%d", &enteredId) != 1) {

            printf("Invalid account number format.\n");

            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF) { }

            continue;

        }

 

        printf("Enter PIN: ");

        if (scanf("%d", &enteredPin) != 1) {

            printf("Invalid PIN format.\n");

            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF) { }

            continue;

        }

 

        int index = findAccount(enteredId);

        if (index != -1 && accounts[index].pin == enteredPin) {

            *loggedInIndex = index;

            printf("\nLogin successful. Welcome, %s!\n", accounts[index].name);

            return 1;

        }

        printf("Incorrect account number or PIN. Attempt %d of 3.\n", attempts);

    }

    return 0;

}

 

void showMenu(void) {

    printLine();

    printf("\n1. Check Balance\n");

    printf("2. Deposit Money\n");

    printf("3. Withdraw Money\n");

    printf("4. Transfer Money\n");

    printf("5. View My Account\n");

    printf("6. View All Accounts (Demo)\n");

    printf("7. Save and Exit\n");

    printLine();

}

 

void checkBalance(const Account *account) {

    printf("\nCurrent balance: Rs. %.2f\n", account->balance);

}

 

void deposit(Account *account) {

    double amount;

    printf("Enter deposit amount: Rs. ");

    if (scanf("%lf", &amount) != 1) {

        printf("Invalid amount format.\n");

        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) { }

        return;

    }

    if (amount <= 0) {

        printf("Amount must be greater than zero.\n");

        return;

    }

    account->balance += amount;

    printf("Deposit successful. New balance: Rs. %.2f\n", account->balance);

}

 

void withdraw(Account *account) {

    double amount;

    printf("Enter withdrawal amount: Rs. ");

    if (scanf("%lf", &amount) != 1) {

        printf("Invalid amount format.\n");

        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) { }

        return;

    }

    if (amount <= 0) {

        printf("Amount must be greater than zero.\n");

    } else if (amount > account->balance) {

        printf("Insufficient balance.\n");

    } else {

        account->balance -= amount;

        printf("Withdrawal successful. New balance: Rs. %.2f\n", account->balance);

    }

}

 

void transfer(Account *sender) {

    int receiverNo, receiverIndex;

    double amount;

 

    printf("Enter receiver account number: ");

    if (scanf("%d", &receiverNo) != 1) {

        printf("Invalid account number.\n");

        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) { }

        return;

    }

 

    receiverIndex = findAccount(receiverNo);

    if (receiverIndex == -1 || receiverNo == sender->accountNo) {

        printf("Receiver account not found or invalid.\n");

        return;

    }

 

    printf("Enter transfer amount: Rs. ");

    if (scanf("%lf", &amount) != 1) {

        printf("Invalid amount format.\n");

        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) { }

        return;

    }

 

    if (amount <= 0) {

        printf("Amount must be greater than zero.\n");

    } else if (amount > sender->balance) {

        printf("Insufficient balance.\n");

    } else {

        sender->balance -= amount;

        accounts[receiverIndex].balance += amount;

        printf("Transfer of Rs. %.2f to account %d completed.\n",

               amount, receiverNo);

        printf("Updated balance: Rs. %.2f\n", sender->balance);

    }

}

 

void showAccount(const Account *account) {

    printf("\nACCOUNT DETAILS\n");

    printLine();

    printf("Account number : %d\n", account->accountNo);

    printf("Account holder : %s\n", account->name);

    printf("Account status : Active\n");

    printf("Balance        : Rs. %.2f\n", account->balance);

}

 

void showAllAccounts(void) {

    int i;

    printf("\nDEMO ACCOUNT LIST\n");

    printLine();

    for (i = 0; i < accountCount; i++) {

        printf("%d | %-20s | Rs. %.2f\n",

               accounts[i].accountNo, accounts[i].name,

               accounts[i].balance);

    }

}

 

int findAccount(int accountNo) {

    int i;

    for (i = 0; i < accountCount; i++) {

        if (accounts[i].accountNo == accountNo)

            return i;

    }

    return -1;

}

 

void saveAccounts(void) {

    FILE *fp = fopen(FILE_NAME, "wb");

    if (fp == NULL) {

        printf("Error: unable to open file for saving.\n");

        return;

    }

    fwrite(&accountCount, sizeof(int), 1, fp);

    fwrite(accounts, sizeof(Account), accountCount, fp);

    fclose(fp);

}

 

void loadAccounts(void) {

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)

        return; /* First run: use the sample accounts above. */

 

    int storedCount;

    if (fread(&storedCount, sizeof(int), 1, fp) == 1 &&

        storedCount > 0 && storedCount <= MAX_ACCOUNTS) {

        size_t readCount = fread(accounts, sizeof(Account), storedCount, fp);

        if (readCount == (size_t)storedCount)

            accountCount = storedCount;

    }

    fclose(fp);

}

 

void printLine(void) {

    printf("------------------------------------\n");

}