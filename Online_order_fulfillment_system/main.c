#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "orders.h"
#include "utils.h"

int main() {
    printf("Welcome to Inventory & Order Management System\n");
    printf("------------------------------------------------\n");
    printf("Input Rules:\n");
    printf("1. Item ID: numeric only.\n");
    printf("2. Item Name: alphabets only.\n");
    printf("3. Quantity: > 0.\n\n");

    Inventory inventory = {NULL};
    OrderQueue queue = {NULL, NULL};
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add/Update Inventory\n");
        printf("2. Add Order\n");
        printf("3. Process Order\n");
        printf("4. Track Item Stock\n");
        printf("5. Display Pending Orders\n");
        printf("6. Display Inventory\n");
        printf("7. Cancel order \n");
        printf("8. Exit\n\n");

        choice = getValidatedChoice();

        switch (choice) {
            case 1: {
                int id = getValidatedInt("Enter Item ID: ");
                char name[50];
                getValidatedName("Enter Item Name: ", name, sizeof(name));

                int qty = getValidatedInt("Enter Quantity to Add: ");
                addOrUpdateInventory(&inventory, id, name, qty);
                break;
            }

           case 2: {
    int id = getValidatedInt("Enter Item ID to Order: ");
    int qty = getValidatedInt("Enter Quantity: ");
    addOrderWithInventory(&queue, &inventory, id, qty);
    break;
}


            case 3:
                processOrder(&queue, &inventory);
                break;

            case 4: {
                int id = getValidatedInt("Enter Item ID to Track: ");
                trackStock(&inventory, id);
                break;
            }

            case 5:
                displayPendingOrders(&queue);
                break;

            case 6:
                displayInventory(inventory.root);

                break;
            case 7: {
                int oid = getValidatedInt("Enter Order ID to cancel: ");
                cancelOrder(&queue, &inventory, oid);
                
                break;
             }
            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid input! Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}
