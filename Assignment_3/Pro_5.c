// Write a C program that converts a singly linked list into an array and returns it.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;    // Assign data to the node
    newNode->next = NULL;    // Initialize next to NULL
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Otherwise, find the last node and append the new node
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to convert the linked list to an array
int* linkedListToArray(struct Node* head, int* size) {
    // First, calculate the size of the linked list
    *size = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        (*size)++;
        temp = temp->next;
    }

    // Allocate memory for the array
    int* arr = (int*)malloc(*size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation for array failed!\n");
        exit(1);
    }

    // Copy data from the linked list to the array
    temp = head;
    for (int i = 0; i < *size; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    return arr;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);  // Print the data of the current node
        current = current->next;          // Move to the next node
    }
    printf("NULL\n");
}

// Function to display the array
void displayArray(int* arr, int size) {
    if (arr == NULL || size == 0) {
        printf("The array is empty.\n");
        return;
    }

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initialize the head of the linked list
    int n, data;

    // Ask the user for the number of nodes in the linked list
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    // Take user input for the linked list
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    // Display the linked list
    displayList(head);

    // Convert the linked list to an array
    int size;
    int* arr = linkedListToArray(head, &size);

    // Display the array
    displayArray(arr, size);

    // Free the allocated memory for the array
    free(arr);

    return 0;
}
