#include <stdlib.h>
#include <stdio.h>


// Create node of a doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

//Print the stored value for each node
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
    printf("\n");
}

// Get the first item in the list
void getFirst(struct Node *value)
{
    //Check if the list is empty 
    if (value == NULL)
    {
        printf("\nSorry, the list is empty.\n");
        return;
    }
    //Print the data of the first node
    printf("The first value: %d\n", value->data);
    
}

//Get the last node in the list 
void getLast(struct Node *value)
{
    //Check if the list is empty
    if (value == NULL)
    {
        printf("\nSorry, the list is empty.\n");
        return;
    }

    //Travel through the list till the last node
    while (value != NULL && value->next != NULL)
    {
        value = value->next;
    }

    //Print the last value 
    printf("The last value: %d\n", value->data);
    
}

// Add a new node and place it at the start of the list
void addToHead(struct Node **headNode, int new_data)
{
    //Declare new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    //Link the new node and assign proper values
    newNode->data = new_data;
    newNode->next = (*headNode);
    newNode->prev = NULL;

    //Link the previous head pointer to the new added node
    if ((*headNode) != NULL)
    {
        (*headNode)->prev = newNode;
    }

    //Move the head pointor to the new node 
    (*headNode) = newNode;
}

// Add a new node to the end of the list 
void addToEnd(struct Node **head_ref, int new_data)
{
    //Declare new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (*head_ref);

    //Link the new node and assign proper values
    newNode->data = new_data;
    newNode->next = NULL;

    //Check if this is the only node in the list 
    if ((*head_ref) == NULL)
    {
        newNode->prev = NULL;
        (*head_ref) = newNode;

        return;
    }
    //Travel through the list till the last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    //Place new node at the end of the list to assign the pointors
    last->next = newNode;
    newNode->prev = last;
}

// Count the number of elements in the list and return its length
int getLength(struct Node *head_ref)
{
    //Declare a value to count teh element in the list 
    int len = 0;
    //Check if the list is empty 
    if (head_ref == NULL)
    {
        printf("The list is empty");
        return 0;
    }
    //traverse the list till the last node
    while (head_ref != NULL)
    {
        head_ref = head_ref->next;
        //Increment the len value to count each node
        len++;
    }
    return len;
}

// Delete all nodes from the list
void destoryList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *next;
    //Traverse the list and delete every node
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    //Assign NULL to head 
    *head = NULL;
}

//Get data at specific poistion in the list. List starts at position 0 
void getItem(struct Node *value, int key)
{
    struct Node *curr = value;
    int counter = 0;

    // Get the link size
    int listLength = getLength(value);
    //Check if the value is not valid and print to user
    if (key < 0 || key >= listLength)
    {
        printf("The provided value %d is out of range\n", key);
        //Print to user the valid range of the list 
        printf("You can choose a value between 0 and %d\n", listLength - 1);
        return;
    }
    //Ensure list is not empty and then traverse the list till value is found 
    while (curr != NULL)
    {
        if (counter == key)
        {
            printf("Value at poistion %d is %d\n",key , curr->data);
        }
        counter++;
        curr = curr->next;
    }
}

//Delete the head node from the list 
void removeFirstNode(struct Node **head_ref)
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

// Delete a node at a given position
void deleteNode(struct Node **head, struct Node *node)
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


    // Travel the list to find the node at the given key
    for (int i = 0; current != NULL && i < key; i++)
    {
        current = current->next;
    }

    // Pass to delete function to delete the node
    deleteNode(head, current);
}

//Print the index for the given value
void findIndex(struct Node *head_ref, int key)
{
    int index = 0;

    //Check if the list exits and not empty 
    if (head_ref == NULL)
    {
        printf("The list is empty.\n");
        return 0;
    }

    //Traverse the list to find the given value 
    while (head_ref != NULL && head_ref->data != key)
    {
        head_ref = head_ref->next;
        index++;
    }

    //Value is not found in the list 
    if (head_ref == NULL)
    {
        printf("The value does't exist.\n");
    }
    else{
        printf("The index of %d is %d \n", key, index);
    }
    
}

//Connect two list together 
void appendList(struct Node *list1, struct Node *list2)
{
    struct Node *L1 = list1;
    struct Node *L2 = list2;
    if (list1 == NULL || list2 == NULL)
    {
        printf("One of the lists is empty. Please ensure both lists have at least one node\n");
        return;
    }

    //Traverse the first list till the last node 
    while (L1->next != NULL)
    {
        L1 = L1->next;
        
    }

    L1->next = L2;
    L2->prev = L1;
    


}