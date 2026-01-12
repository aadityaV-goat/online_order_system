#include <stdio.h>
#include <stdlib.h>
#include "orders.h"

//  Find item in inventory
static InventoryNode* findItem(Inventory *inventory, int itemID) {
    return searchInventory(inventory->root, itemID);
}
// New function with inventory validation
void addOrderWithInventory(OrderQueue *queue, Inventory *inventory, int itemID, int qty) {
    InventoryNode *item = findItem(inventory, itemID);

    if (item == NULL) {
        printf("Error: Cannot place order. Item ID %d not found in inventory.\n", itemID);
        return;
    }

    if (qty > item->quantity) {
        printf("Error: Cannot place order. Only %d '%s' in stock.\n", item->quantity, item->itemName);
        return;
    }

    // Deduct from inventory immediately
    item->quantity -= qty;

    // Create new order
    Order *newOrder = malloc(sizeof(Order));
    newOrder->orderID = rand() % 10000;  // random order ID
    newOrder->itemID = itemID;
    newOrder->quantity = qty;
    newOrder->next = NULL;

    // Enqueue order
    if (queue->rear == NULL)
        queue->front = queue->rear = newOrder;
    else {
        queue->rear->next = newOrder;
        queue->rear = newOrder;
    }

    printf("Order Added: [OrderID: %d | ItemID: %d | Qty: %d]\n", newOrder->orderID, itemID, qty);
    printf("Inventory Updated: '%s' remaining stock = %d\n", item->itemName, item->quantity);
}
//NEW FUNCTIONALITY ADDED 
void displayPendingOrders(OrderQueue *queue) {
    if (queue->front == NULL) {
        printf("No pending orders.\n");
        return;
    }

    printf("\nPending Orders:\n");
    Order *temp = queue->front;
    while (temp != NULL) {
        printf("[OrderID: %d | ItemID: %d | Qty: %d]\n", temp->orderID, temp->itemID, temp->quantity);
        temp = temp->next;
    }
}

// Process first order in queue
void processOrder(OrderQueue *queue, Inventory *inventory) {
    if (queue->front == NULL) {
        printf("No pending orders to process.\n");
        return;
    }

    Order *order = queue->front;
    InventoryNode *item = searchInventory(inventory->root, order->itemID);

    if (item == NULL) {
        printf("Error: Item ID %d not found in inventory.\n", order->itemID);
        return;
    }

    printf("Order Processed: ID %d | Item %s | Qty %d\n",
           order->orderID, item->itemName, order->quantity);

    // Remove processed order
    queue->front = order->next;
    if (queue->front == NULL)
        queue->rear = NULL;

    free(order);    }
//NEW FUNCTIONALITY ADDED
    void cancelOrder(OrderQueue *queue, Inventory *inventory, int orderID) {

    if (queue->front == NULL) {
        printf("No orders to cancel.\n");
        return;
    }

    Order *temp = queue->front;
    Order *prev = NULL;

    // Search for the order in queue
    while (temp != NULL && temp->orderID != orderID) {
        prev = temp;
        temp = temp->next;
    }

    // Order not found
    if (temp == NULL) {
        printf("Order ID %d not found.\n", orderID);
        return;
    }

    // Restore item quantity in inventory
    InventoryNode *item = searchInventory(inventory->root, temp->itemID);
    if (item != NULL) {
        item->quantity += temp->quantity; // restore cancelled quantity
    }

    // Delete the order from queue
    //front
    if (prev == NULL) {
        queue->front = temp->next;
    }
    //at any position 
    else {
        prev->next = temp->next;
    }
    //end 
    if (temp == queue->rear)
        queue->rear = prev;

    printf("Order ID %d cancelled successfully.\n", orderID);
    printf("Restored stock: Item %d new quantity = %d\n",
           temp->itemID, item->quantity);

    free(temp);
}




