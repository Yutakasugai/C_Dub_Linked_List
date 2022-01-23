#include <stdlib.h>
#include <stdio.h>
#include "linkList1.h"

int main()
{
    //Declare variables
    struct Node *head = NULL;
    struct Node *List2 = NULL;

    //Create a list of 5 nodes 
    printf("List1 of five nodes: ");
    addToHead(&head, 50);
    addToHead(&head, 40);
    addToHead(&head, 30);
    addToHead(&head, 20);
    addToHead(&head, 10);
    printValue(head);

    printf("List2 of 3 nodes: ");
    addToHead(&List2, 3);
    addToHead(&List2, 2);
    addToHead(&List2, 1);
    printValue(List2);
    //Print the length of the list 
    printf("\nBelow Example is corresponding to List1.\n");
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

    //Append two list together
    printf("\nAppend two list togther: \n");
    appendList(head, List2);
    printValue(head);
    printf("\n");
    //Delete a node at specific location 
    removeNodeAtPos(&head, 0);
    printf("Remove node at position 0\n");
    printf("The new List is : ");
    printValue(head);
    removeNodeAtPos(&head, 2);
    printf("Remove node at position 2\n");
    printf("The new List is : ");
    printValue(head);

    //delete all elements in the list 
    printf("\nDestory all the list.");
    destoryList(head);
    destoryList(List2);

}
