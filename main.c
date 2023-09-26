// بسم الله الرحمن الرحيم

// === Restaurant Billing Console APP ===
// Author: Mohamed Adel Elsayed (BnAdel)
// --------------------
// --- TIME LINE ---   |
// --------------------
// Day(1) => 26-9-2023


#include <stdio.h>

void greeting();

int main() {
    // Greeting Function
    greeting();

    // Receiving The Choice From The User
    while(true) {
        int choice;
        printf("--> Your Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Your Code

        } else if (choice == 2) {
            // Your Code

        } else if (choice == 3) {
            // Your Code

        } else if (choice == 4) {
            printf("\n\t================\n");
            printf("\t| SEE YOU SOON |\n");
            printf("\t================\n");
            break;
        } else {
            printf("=> Your Choice Is Not Available, Try Again!! <=\n");
        }
    }

    return 0;
}

void greeting() {
    printf("\t======================================\n");
    printf("\t==== WELCOME TO BnAdel RESTAURANT ====\n");
    printf("\t======================================\n");
    printf("\nPlease Choose One Of The Following Choices...\n");
    printf("  1. Create New Invoice.\n");
    printf("  2. Show All Invoices.\n");
    printf("  3. Search Invoice.\n");
    printf("  4. EXIT.\n-----------------------\n");
}