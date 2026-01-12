#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct InventoryNode {
    int itemID;
    char itemName[50];
    int quantity;
    struct InventoryNode *left, *right;
    int height;
} InventoryNode;

typedef struct {
    InventoryNode *root;
} Inventory;

int height(InventoryNode *N);
int max(int a, int b);
int getBalance(InventoryNode *N);

InventoryNode *createInventoryNode(int id, char *name, int qty);
InventoryNode *insertInventory(InventoryNode *node, int id, char *name, int qty);
InventoryNode *searchInventory(InventoryNode *root, int id);
void displayInventory(InventoryNode *root);

void addOrUpdateInventory(Inventory *inventory, int id, char *name, int qty);
void trackStock(Inventory *inventory, int id);

#endif
