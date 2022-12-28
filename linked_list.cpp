#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

// Creates a new node:
node createNode(){
    node temp;
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    return temp;
}

// Adds the new node at the end of the linked list:
node insertNode(node head, int value){
	node temp, p; 					// Declare two nodes (pointers to 'LinkedList' objects), temp and p
	
	temp = createNode();			// Create temp
	temp->data = value;				// Set its data equal to the function's argument
	
	if (head == NULL){				// If the linked list is empty...
		head = temp;				// ...temp becomes the head of the list
	}
	else{						// If the linked list is not empty...
		p = head; 				// ...make p point to the head
		while (p->next != NULL){		// While p is not pointing to the last node...
			p = p->next;			// ...make p point to the next node until it reaches the last node
		}
		p->next = temp;			// When p points to the last node of the list and add temp after it
	}
	return head;					
}

// Removes the first node of the linked list:
node removeNode(node head){
	node temp;					// Declare (pointer to) node, temp	
	
	if (head == NULL){				
		printf("It's empty!\n");
	}
	else{
		temp = head->next;			// Make temp point to the node after the head
		free(head);				// Delete current head
		head = temp;				// The node after the old head becomes the new head
	}
	
	return head;
}

// Checks if the linked list is empty:
bool isEmpty(node head){
	if (head == NULL)
		return true;
	else
		return false;
}

// Prints all nodes of the linked list:
void printLinkedList(node head){
	node temp;						// Deaclare (pointer to) node, temp
	if (head == NULL)
		printf("There's nothing here!\n");
	else{
		temp = head;					// Make temp point to the current head
		while (temp != NULL){			// While temp is pointing to some node...
			printf("%d ", temp->data);	//...print that node's data and...
			temp = temp->next;			//...make temp point to the node next to it
		}
		printf("\n");
	}	
}

// Returns the size of linked list
int calculateSize(node head){
    node temp;
    int size = 0;
    if (head == NULL)
        return 0;
    else{
        temp = head;
        while (temp != NULL){
            size++;
            temp = temp->next;
        }
        return size;
    }
}
