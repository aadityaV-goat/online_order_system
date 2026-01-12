#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

int max(int a, int b)
{ return (a > b) ? a : b; }

int height(InventoryNode *N) {
    return (N == NULL) ? 0 : N->height;
}

int getBalance(InventoryNode *N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

InventoryNode *rightRotate(InventoryNode *y) {
    InventoryNode *x = y->left;
    InventoryNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

InventoryNode *leftRotate(InventoryNode *x) {
    InventoryNode *y = x->right;
    InventoryNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

InventoryNode *createInventoryNode(int id, char *name, int qty) {
    InventoryNode *node = malloc(sizeof(InventoryNode));
    node->itemID = id;
    strcpy(node->itemName, name);
    node->quantity = qty;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

InventoryNode *insertInventory(InventoryNode *node, int id, char *name, int qty) {
    if (node == NULL) {
        printf("Item '%s' added to inventory with quantity %d.\n", name, qty);
        return createInventoryNode(id, name, qty);
    }

    if (id < node->itemID)
        node->left = insertInventory(node->left, id, name, qty);
    else if (id > node->itemID)
        node->right = insertInventory(node->right, id, name, qty);
    else {
        node->quantity += qty;
        printf("Item '%s' already exists. Updated quantity to %d.\n", name, node->quantity);
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && id < node->left->itemID)
        return rightRotate(node);
    if (balance < -1 && id > node->right->itemID)
        return leftRotate(node);
    if (balance > 1 && id > node->left->itemID) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && id < node->right->itemID) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void displayInventory(InventoryNode *root) {
    if (root != NULL) {
        displayInventory(root->left);
        printf("ItemID: %d | Name: %s | Stock: %d\n", root->itemID, root->itemName, root->quantity);
        displayInventory(root->right);
    }
}
//searching using recussion 
InventoryNode *searchInventory(InventoryNode *root, int id) {
    if (root == NULL || root->itemID == id)
        return root;
    if (id < root->itemID)
        return searchInventory(root->left, id);
    return searchInventory(root->right, id);
}
//inputs whole inventory struct
void addOrUpdateInventory(Inventory *inventory, int id, char *name, int qty) {
    inventory->root = insertInventory(inventory->root, id, name, qty);
}

void trackStock(Inventory *inventory, int id) {
    InventoryNode *item = searchInventory(inventory->root, id);
    if (item == NULL)
        printf(" Item not found in inventory.\n");
    else
        printf("Item: %s | Stock: %d\n", item->itemName, item->quantity);
}
