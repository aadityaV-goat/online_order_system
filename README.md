# online_order_system
Introduction
The Online Order Fulfillment System is a data structure-based project designed to efficiently
handle customer orders and manage warehouse inventory. The system integrates both
linear(Queue) and non-linear(AVL Tree) data structures to automate order processing and
inventory tracking in an e-commerce environment.

System Overview
The system allows adding and updating inventory, placing customer orders, processing
them sequentially, and tracking stock levels. The Queue ensures that orders are processed
in the order they are placed, maintaining fairness. The AVL Tree provides efficient storage
and retrieval of inventory information by keeping the tree balanced automatically after each
insertion or update

Implemented Functionalities:
1. Add/Update Inventory -(already implemented)
Adds item to the inventory or updates quantity if its already there.
2. Add Order-(already implemented)
Allows user to place order with respect to the updated inventory.
3. Process Order-(already implemented)
Processes or “delivers” placed orders.
4. Track Item Stock (already implemented)
Track how much quantity of a certain item is left.
5. Display Pending Orders (Newly added)
Any orders that are yet to be processed are shown.
6. Display Inventory (already implemented –self added)
Display the inventory with its current content at any point of time.
7. Cancel order (newly added)
Cancelling placed orders- before we process them.
8. Exit : To stop the execution of the program.

9. Hierarchy
1.⁠ ⁠main.c (Top Level Controller)
Displays menu, takes input from user, calls functions from other modules, Does NOT contain
any logic itself, only coordinates modules
2.⁠ ⁠utils.c (Input Validation Layer)
Ensures all inputs are correct, prevents crashes, Provides clean, validated data to main.c
3.⁠ ⁠inventory.c (AVL Tree Module)
Stores items using AVL Tree- Handles:
• Insert item
• Update quantity
• Track item stock
• Search item
• Display items
Time complexity: O(log n)
4.⁠ ⁠orders.c (Queue Module + Inventory Interaction)
Responsible for the complete order workflow:
a. addOrderWithInventory()
• Validates item
• Checks quantity
• Updates stock
• Adds to queue
b. processOrder()
• Dequeues first order
• Displays processed order
c. cancelOrder()
• Removes a specific order
• Restores stock
d. displayPendingOrders()
• Shows all queue items
e. Queue implemented using Linked List
