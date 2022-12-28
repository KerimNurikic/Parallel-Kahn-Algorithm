#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct LinkedList{
    int data;						
    struct LinkedList *next;
};

// Define 'node' as pointer to a variable of 'struct LinkedList' data type:
typedef struct LinkedList *node; 

// Creates a new node:
node createNode();

// Adds the new node at the end of the linked list:
node insertNode(node head, int value);

// Removes the first node of the linked list:
node removeNode(node head);

// Checks if the linked list is empty:
bool isEmpty(node head);

// Prints all nodes of the linked list:
void printLinkedList(node head);

// Returns the size of linked list
int calculateSize(node head);

#endif
