#include <stdlib.h>
#include <stdio.h>
#include "linkList1.h"

int main()
{
    //Declare variable 
    struct Node *head = NULL;

    //Create a list of 5 nodes 
    printf("\n\nList of five nodes: ");
    addToHead(&head, 50);
    addToHead(&head, 40);
    addToHead(&head, 30);
    addToHead(&head, 20);
    addToHead(&head, 10);
    printValue(head);

    //Print the length of the list 

    int length;
    length = getLength(head);
    printf("\n\nThe number of elements in the list is: %d\n", length);

    //Get the first node value 
    getFirst(head);

    //Get the last node value 
    getLast(head);

    //Get data at specific location - list starts from 0-n
    getItem(head, 2);
    getItem(head, 4);
    getItem(head, 5);

    //Obtain node's index based on its data value 
    printf("\n");
    findIndex(head, 20);
    findIndex(head, 50);
    findIndex(head, 40);
    findIndex(head, 10);

    //Delete a node at specific location 
    removeNodeAtPos(&head, 0);
    printf("The new List is : ");
    printValue(head);
    removeNodeAtPos(&head, 2);
    printf("The new List is : ");
    printValue(head);

    //delete all elements in the list 
    printf("\n\nDestory all the list: ");
    

    printValue(head);
}
