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
        printf("%d ", value->data);
        value = value->next;
    }
}

// Get the first item in the list
void getFirst(struct Node *value)
{
    if (value == NULL)
    {
        printf("\nSorry, the list is empty.\n");
        return;
    }

    printf(" %d ", value->data);
}

void getLast(struct Node *value)
{

    if (value == NULL)
    {
        printf("\nSorry, the list is empty.\n");
        return;
    }

    while (value != NULL && value->next != NULL)
    {
        value = value->next;
    }

    // printf("\nLast value: %d\n", value->data);
    printf("The last value: ");
    printValue(value);
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
int getValue(struct Node *value, int key)
{
    struct Node *current = value;
    int counter = 0;

    if (current == NULL)
    {
        printf("The head node does not hold any value inside.");
        return 0;
    }

    while (current != NULL)
    {
        if (counter == key)
        {
            return (current->data);
        }
        counter++;
        current = current->next;
    }

    return 0;
}

void getItem(struct Node *value, int key)
{
    struct Node *curr = value;
    int counter = 0;

    // Get the link size
    int listLength = getLength(value);

    if (key < 0 || key >= listLength)
    {
        printf("\nThe value %d provided is out of range\n", key);
        printf("You can choose a value between 0 and %d\n", listLength - 1);
        return;
    }

    while (curr != NULL)
    {
        if (counter == key)
        {
            printf("\nValue is %d\n", curr->data);
        }
        counter++;
        curr = curr->next;
    }
}

void removeFirNode(struct Node **head_ref)
{
    struct Node *tmp;

    /*Linked list does not exist or the list is empty*/
    if (head_ref == NULL || *head_ref == NULL)
        return;

    /*Storing the head to a temporary variable*/
    tmp = *head_ref;

    /*Moving head to the next node*/
    *head_ref = (*head_ref)->next;

    /*Deleting the first node*/
    free(tmp);
}

/*
void removeNode(struct Node **head_ref, int key)
{
    struct Node *current = *head_ref;
    struct Node *tracker;
    struct Node *next;
    struct Node *temp;

    int counter = 0;
    int getLen = getLength(head_ref);
    print("\n%d\n", getLen);

    if (key == 0)
    {
        temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
    }

    else
    {
        while (current != NULL)
        {
            tracker = current->prev;
            next = current->next;
            if (counter == key)
            {
                free(current);
                tracker->next = next;
                next->prev = tracker;
            }
            current = current->next;
            counter++;
        }
    }
}
*/

// Delete a node at a given position
void delNodeAtPos(struct Node **head, struct Node *node)
{
    // Check if the node is the head
    if (*head == node)
    {
        *head = node->next;
    }
    // Change next if it is not the last node
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }

    // change prev if the node is not the head
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }

    // Free the memory
    free(node);
}

// Remove a node at a given position
void removeNodeAtPos(struct Node **head, int key)
{
    struct Node **headAddress = head;
    struct Node *current = *head;

    // Get the link size
    int linklen = getLength(*head);

    // Check if the ndoe is NULL or value is greater than link size
    if (*head == NULL || key < 0 || key > linklen)
    {
        printf("\nThe value %d provided is out of range\n", key);
        printf("You can choose a value between 0 and %d\n", linklen - 1);
        return;
    }

    // check if the key is zero then delete the head
    /*if (key == 0 && *head != NULL)
    {
        removeFirNode(headAddress);
        return;
    }*/

    // Travel the list to find the node at the given key
    for (int i = 0; current != NULL && i < key; i++)
    {
        current = current->next;
    }

    // Pass to delete function
    delNodeAtPos(head, current);
}

void appendNode(struct Node **head_node, int key)
{
    int counter = 0;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = *head_node;
    struct Node *next;

    newNode->data = 20;

    if (head_node == NULL)
    {
        printf("The head node does not hold any value inside.");
    }

    else
    {
        while (current != NULL)
        {
            next = current->next;
            if (counter == key)
            {
                current->next = newNode;
                newNode->next = next;
            }
            current = current->next;
            counter++;
        }
    }
}

int main()
{
    // Create three nodes and declare them
    struct Node *head = NULL;
    // struct Node *second = NULL;
    // struct Node *third = NULL;

    printf("\n\nAdded a node to the beginning: ");
    addToHead(&head, 8);
    addToHead(&head, 10);
    addToHead(&head, 13);
    printValue(head);

    printf("\n");
    removeNodeAtPos(&head, 2);
    printValue(head);
    // getItem(head, -1);

    // getItem(head, 3);
    // printf("\n");
    // getFirst(head);

    // printf("\n\nAdded a node to the end: ");
    // addToEnd(&head, 7);
    // addToEnd(&head, 9);
    // addToEnd(&head, 12);
    // printValue(head);

    // printf("\n");
    // getLast(head);

    // int length;
    // length = getLength(head);
    // printf("\n\nThe number of elements is: %d", length);

    printf("\n\nDestory all the list: ");
    destoryList(&head);

    printValue(head);

    // int value;
    // int key = 0;
    // value = getValue(head, key);
    // printf("\n\nThe value at the %d element is: %d", key, value);

    /*removeFirNode(&head);
    printValue(head);

    int key2 = 0;
    removeNode(&head, key2);
    printf("\n\nRemove the node at the %d element: ", key2);
    printValue(head);

    int key3 = 6;
    int key4 = key3 + 1;
    appendNode(&head, key3);
    printf("\n\nAppend a new node in the list between %d and %d: ", key3, key4);
    printValue(head);*/

    printf("\n\n");

    return 0;
}