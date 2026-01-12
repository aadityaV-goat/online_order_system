#ifndef ORDERS_H
#define ORDERS_H

#include "inventory.h"

typedef struct Order {
    int orderID;
    int itemID;
    int quantity;
    struct Order *next;
} Order;

typedef struct {
    Order *front;
    Order *rear;
} OrderQueue;

void processOrder(OrderQueue *queue, Inventory *inventory);
void displayPendingOrders(OrderQueue *queue);
void addOrderWithInventory(OrderQueue *queue, Inventory *inventory, int itemID, int qty);
void cancelOrder(OrderQueue *queue, Inventory *inventory, int orderID);   // NEW

#endif