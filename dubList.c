#include <stdlib.h>
#include <stdio.h>

// Create node of a doubly linked list
struct Node
{

    int data;
    struct Node *next;
    struct Node *prev;
};

void printValue(struct Node *value)
{
    if (value == NULL)
    {
        printf("\nSorry, the list is empty.\n");
    }
    while (value != NULL)
    {
        printf(" %d ", value->data);
        value = value->next;
    }
}

// Added a new node and place it at the top of the list
void addToHead(struct Node **headNode, int new_data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = new_data;
    newNode->next = (*headNode);
    newNode->prev = NULL;

    if ((*headNode) != NULL)
    {
        (*headNode)->prev = newNode;
    }

    (*headNode) = newNode;
}

// added a new node and place it at the end of the list
void addToEnd(struct Node **head_ref, int new_data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (*head_ref);

    newNode->data = new_data;

    newNode->next = NULL;

    if ((*head_ref) == NULL)
    {
        newNode->prev = NULL;
        (*head_ref) = newNode;

        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// get number of elements for the list and return it as an integer
int getLength(struct Node *head_ref)
{
    int len = 0;

    if (head_ref == NULL)
    {
        printf("The list is empty");
        return 0;
    }

    while (head_ref != NULL)
    {
        head_ref = head_ref->next;
        len++;
    }
    return len;
}

// Destory all nodes from the list
void destoryList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

// Not completed yet, get element at given index
int getValue(struct Node **value, int key)
{
    struct Node *temp_ref;
    int counter = 0;

    temp_ref = (*value);

    while (temp_ref != NULL)
    {
        counter++;
        printf("%d %d ", temp_ref->data, counter);
        temp_ref = temp_ref->next;

        if (counter == key)
        {
            temp_ref->data = temp_ref->prev;
            printf("\n\n%d \n", temp_ref->data);
            return temp_ref->data;
        }
    }

    // temp_ref = (*value);
    // free(temp_ref);

    return 4;
}

int main()
{
    // Create three nodes and declare them
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    //assign data to each node and link it to the next node
    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    // initialize(head, second, thrid);

    printf("\nThe created list is: ");
    printValue(head);

    printf("\n\nAdded a node to the beginning: ");
    addToHead(&head, 8);
    addToHead(&head, 10);
    addToHead(&head, 13);
    printValue(head);

    printf("\n\nAdded a node to the end: ");
    addToEnd(&head, 7);
    addToEnd(&head, 9);
    addToEnd(&head, 12);
    printValue(head);

    int length;
    length = getLength(head);
    printf("\n\nThe number of elements is: %d\n\n", length);

    // printf("\n\nDestory all the list: ");
    // destoryList(&head);
    // printValue(head);

    int k;
    k = getValue(&head, 1);
    printf("\n\nThe 1st element number is: %d", k);

    printf("\n\n");

    return 0;
}