#include <stdlib.h>
#include <stdio.h>
#include "linkList.h"

int main()
{
    // Declare variables
    struct Node *head = NULL;
    struct Node *List2 = NULL;

    // Create a list of 5 nodes
    printf("\n\nList1 of five nodes: ");
    addNewNode(&head, 50);
    addNewNode(&head, 40);
    addNewNode(&head, 30);
    addNewNode(&head, 20);
    addNewNode(&head, 10);
    printValue(head);

    printf("List2 of 3 nodes: ");
    addNewNode(&List2, 3);
    addNewNode(&List2, 2);
    addNewNode(&List2, 1);
    printValue(List2);

    // Print the length of the list
    printf("\nBelow Example is corresponding to List1.\n");

    // Get a number of length and return the value as an integer
    int length;
    length = getLength(head);
    printf("\n\nThe number of elements in the list is: %d\n", length);

    // Get the first node value
    getFirst(head);

    // Get the last node value
    getLast(head);

    // Get data at specific location - list starts from 0-n
    getItem(head, 2);
    getItem(head, 4);
    getItem(head, 5);

    // Obtain node's index based on its data value
    printf("\n");
    int val = findIndex(head, 20);
    printf("The number of index in the list where the given value 20 is: %d\n", val);
    val = findIndex(head, 50);
    printf("The number of index in the list where the given value 50 is: %d\n", val);
    val = findIndex(head, 30);
    printf("The number of index in the list where the given value 30 is: %d\n", val);

    // Append two list together
    printf("\nAppend two list togther: \n");
    appendList(head, List2);
    printValue(head);
    printf("\n");

    // Delete a node at specific location
    removeNodeAtPos(&head, 0);
    printf("Remove node at position 0\n");
    printf("The new List is : ");
    printValue(head);
    removeNodeAtPos(&head, 2);
    printf("Remove node at position 2\n");
    printf("The new List is : ");
    printValue(head);
    removeNodeAtPos(&head, 5);
    printf("Remove node at position 5\n");
    printf("The new List is : ");
    printValue(head);

    // delete all elements in the list
    printf("\nDestory all the list.\n");
    destoryList(&head);

    return 0;
}