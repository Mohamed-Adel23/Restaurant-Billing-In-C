// بسم الله الرحمن الرحيم

// === Restaurant Billing Console APP ===
// Author: Mohamed Adel Elsayed (BnAdel)
//  --------------------
// | --- TIME LINE ---  |
//  --------------------
// Day(1) => 26-9-2023
// Day(2) => 28-9-2023
// Day(3) => 30-9-2023


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
char *removeSpaces(char *name);
void generateInvoice(struct Orders order);
void invoiceHeader(char *customerName, char *date);
void invoiceBody(struct Items item, int count);
void invoiceFooter(double totalPrice, double discount);

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
            printf("\n---------------------------------------------\n");
            greeting();

        }
        else if (choice == 2) {
            // Your Code

        }
        else if (choice == 3) {
            // Your Code

        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("=> Your Choice Is Not Available, Try Again!! <=\n");
        }
    }
    printf("\n\t================\n");
    printf("\t| SEE YOU SOON |\n");
    printf("\t================\n");

    return 0;
}

char *removeSpaces(char *name) {
    bool isStart = true;
    // Remove The Starting Spaces
    int j = 0;
    for (int i = 0; name[i] != '\0'; ++i) {
        if(name[i] == ' ' && isStart) continue;
        name[j++] = name[i];
        isStart = false;
    }
    // The Ending Of The String
    name[j] = '\0';

    // Remove The Ending Spaces
    j = 0;
    for (int i = 0; name[i] != '\0'; ++i) {
        if(name[i] == ' ' && name[i+1] == ' ') continue;
        name[j++] = name[i];
    }
    // The Ending Of The String
    name[j] = '\0';

    return name;
}

void greeting() {
    printf("\nPlease Choose One Of The Following Choices...\n");
    printf("  1. Create New Invoice.\n");
    printf("  2. Show All Invoices.\n");
    printf("  3. Search Invoice.\n");
    printf("  4. EXIT.\n-----------------------\n");
}

void invoiceHeader(char *customerName, char *date) {
    printf("\n\t-----------------------\n");
    printf("\t--- INVOICE DETAILS ---\n");
    printf("\t-----------------------\n");
    printf("Customer Name: %s\n", customerName);
    printf("Date: %s\n", date);
    printf("------------------------------------------|\n");
    printf("# | Name \t| Unit Price \t| Quantity\n");
    printf("------------------------------------------|\n");
}

void invoiceBody(struct Items item, int count) {
    printf("%d | %s \t| $%.2f \t| %d\n", count, item.itemName, item.unitPrice, item.quantity);
    printf("------------------------------------------|\n");
}

void invoiceFooter(double totalPrice, double discount) {
    printf("Total Price: \t\t\t $%.2f\n", totalPrice);
    printf("Discount:  \t\t\t %.2f%%\n", discount*100);
    double finalPrice = totalPrice - (discount * totalPrice);
    printf("Total Price: \t\t\t $%.2f\n", finalPrice);
    printf("-------------BnAdel Restaurant-------------\n");
}

void customerData() {
    printf("\n\t============================\n");
    printf("\t|++ GENERATE NEW INVOICE ++|\n");
    printf("\t============================\n");

    struct Orders order;
    printf("\n--> Enter The Customer Name:");
    fgets(order.customerName, 50, stdin);
    // To Remove The (\n) After The Name
    order.customerName[strlen(order.customerName) - 1] = 0;
    // Removing Spaces
    strcpy(order.customerName, removeSpaces(order.customerName));

    // Storing The Date
    strcpy(order.date, __DATE__);

    printf("\n--> Enter The Number Of Items: ");
    scanf("%d", &order.numOfItems);
    getchar(); // To Avoid Not Consuming (\n)
    // Validation
    if(order.numOfItems <= 0 || order.numOfItems > 50) {
        printf("ERROR :( Invalid Number of Items, It Should Be Between (1 and 50)!!\n");
        return;
    }

    generateInvoice(order);
}

void generateInvoice(struct Orders order) {

    for (int i = 1; i <= order.numOfItems; ++i) {
        printf("\n--> ITEM [ %d ] <--\n", i);

        printf("Enter Item Name: ");
        fgets(order.item[i-1].itemName, 50, stdin);
        // To Remove The (\n) After The Name
        order.item[i-1].itemName[strlen(order.item[i-1].itemName) - 1] = 0;
        // Remove Spaces
        strcpy(order.item[i-1].itemName, removeSpaces(order.item[i-1].itemName));

        printf("Enter Item Unit Price: ");
        scanf("%lf", &order.item[i-1].unitPrice);
        getchar(); // To Avoid Not Consuming (\n)
        // Validation
        if(order.item[i-1].unitPrice <= 0 || order.item[i-1].unitPrice > 500) {
            printf("ERROR :( Invalid Unit Price, It Should Be Between (10 and 500)!!\n");
            return;
        }

        printf("Enter Item Quantity: ");
        scanf("%d", &order.item[i-1].quantity);
        getchar(); // To Avoid Not Consuming (\n)
        // Validation
        if(order.item[i-1].quantity <= 0 || order.item[i-1].quantity > 100) {
            printf("ERROR :( Invalid Quantity, It Should Be Between (1 and 100)!!\n");
            return;
        }
    }

    // Show The Whole Invoice Of The Current Customer
    invoiceHeader(order.customerName, order.date);
    double totalPrice = 0.0, discount = 0.2;
    for (int i = 0; i < order.numOfItems; ++i) {
        totalPrice += (order.item[i].unitPrice * order.item[i].quantity);
        invoiceBody(order.item[i], i+1);
    }
    invoiceFooter(totalPrice, discount);
}

