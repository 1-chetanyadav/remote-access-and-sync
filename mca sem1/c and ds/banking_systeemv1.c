#include <stdio.h>
 
int main() {
    int id, pin, tries = 0, choice, receiver;
    int accountNo = 1001;
    float balance = 5000, amount;
 
    while (tries < 3) {
        printf("Enter User ID: ");
        scanf("%d", &id);
        printf("Enter PIN: ");
        scanf("%d", &pin);
 
        if (id == 101 && pin == 1234)
            break;
 
        printf("Invalid login! Try again.\n");
        tries++;
    }
 
    if (tries == 3) {
        printf("Access denied.\n");
        return 0;
    }
 
    do {
        printf("\n--- BANKING MENU ---\n");
        printf("1. Check Balance\n2. Deposit Money\n");
        printf("3. Withdraw Money\n4. Transfer Money\n");
        printf("5. Account Information\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Balance: Rs. %.2f\n", balance);
                break;
 
            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful.\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;
 
            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                if (amount <= 0)
                    printf("Invalid amount.\n");
                else if (amount > balance)
                    printf("Insufficient balance.\n");
                else {
                    balance -= amount;
                    printf("Withdrawal successful.\n");
                }
                break;
 
            case 4:
                printf("Enter receiver account number: ");
                scanf("%d", &receiver);
                printf("Enter transfer amount: ");
                scanf("%f", &amount);
                if (receiver <= 0 || receiver == accountNo)
                    printf("Invalid receiver account.\n");
                else if (amount <= 0)
                    printf("Invalid amount.\n");
                else if (amount > balance)
                    printf("Insufficient balance.\n");
                else {
                    balance -= amount;
                    printf("Transfer successful to account %d.\n",
                           receiver);
                }
                break;
 
            case 5:
                printf("Account Number: %d\n", accountNo);
                printf("Account Status: Active\n");
                printf("Current Balance: Rs. %.2f\n", balance);
                break;
 
            case 6:
                printf("Thank you for using the bank system.\n");
                break;
 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
 
    return 0;
}
