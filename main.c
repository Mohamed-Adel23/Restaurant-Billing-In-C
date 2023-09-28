// بسم الله الرحمن الرحيم

// === Restaurant Billing Console APP ===
// Author: Mohamed Adel Elsayed (BnAdel)
// --------------------
// --- TIME LINE ---   |
// --------------------
// Day(1) => 26-9-2023
// Day(2) => 28-9-2023


#include <stdio.h>
#include <string.h>

// STRUCT For Items
struct Items {
    char itemName[50];
    double unitPrice;
    int quantity;
};
// STRUCT For Orders
struct Orders {
    char customerName[50];
    char date[50];
    int numOfItems;
    // An Array Of Items, Because An Order May Have Many Items
    struct Items item[50]; // Max Num Of Items
};

void greeting();
void customerData();
void generateInvoice(struct Orders order);

int main() {
    printf("\t======================================\n");
    printf("\t==== WELCOME TO BnAdel RESTAURANT ====\n");
    printf("\t======================================\n");
    // Greeting Function
    greeting();

    /* {
        printf("Name is: ");
        char name[50];
        fgets(name, 50, stdin);
        printf("Welcome %s and The Length: %d", name, strlen(name));

        printf("Number is: ");
        int n;
        scanf("%d", &n);
        printf("The Number is %d", n);
    } */

    // Receiving The Choice From The User
    while(true) {
        printf("--> Your Choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();

        if (choice == 1) { // Create New Invoice

            customerData();

            printf("Do You Want To Make Another Operation [y/n]?");
            char c;
            scanf("%c", &c);
            if(c == 'n') break;
            greeting();

        } else if (choice == 2) {
            // Your Code

        } else if (choice == 3) {
            // Your Code

        } else if (choice == 4) {
            break;
        } else {
            printf("=> Your Choice Is Not Available, Try Again!! <=\n");
        }
    }
    printf("\n\t================\n");
    printf("\t| SEE YOU SOON |\n");
    printf("\t================\n");

    return 0;
}

void greeting() {
    printf("\nPlease Choose One Of The Following Choices...\n");
    printf("  1. Create New Invoice.\n");
    printf("  2. Show All Invoices.\n");
    printf("  3. Search Invoice.\n");
    printf("  4. EXIT.\n-----------------------\n");
}

void customerData() {
    printf("\n\t============================\n");
    printf("\t|++ GENERATE NEW INVOICE ++|\n");
    printf("\t============================\n");

    struct Orders order;
    printf("\n--> Enter The Customer Name:");
    fgets(order.customerName, 50, stdin);

    printf("\n--> Enter The Number Of Items: ");
    char nfi[10];
    fgets(nfi, 10, stdin);
    sscanf(nfi, "%d", &order.numOfItems); // To Avoid newline (\n)

    generateInvoice(order);
}

void generateInvoice(struct Orders order) {

    for (int i = 1; i <= order.numOfItems; ++i) {
        printf("\n--> ITEM [ %d ] <--\n", i);

        printf("Enter Item Name: ");
        fgets(order.item[i-1].itemName, 50, stdin);

        printf("Enter Item Unit Price: ");
        char up[10];
        fgets(up, 10, stdin);
        sscanf(up,"%lf", &order.item[i-1].unitPrice);

        printf("Enter Item Quantity: ");
        fgets(up, 10, stdin);
        sscanf(up,"%d", &order.item[i-1].quantity);

        printf("\nCustomer Name: %sItem Name: %sUnit Price: %.2f$\nItem Quantity: %d items\n----------------\n", order.customerName, order.item[i-1].itemName, order.item[i-1].unitPrice, order.item[i-1].quantity);
    }
}