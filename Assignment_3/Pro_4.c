// Write a program in C to copy the elements of the array to a singly
// linked list.

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

// Function to copy elements from array to linked list
void arrayToLinkedList(int arr[], int size, struct Node** head) {
    for (int i = 0; i < size; i++) {
        // Create a new node for each element in the array
        struct Node* newNode = createNode(arr[i]);
        
        // If the linked list is empty, set the head to the new node
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
        printf("%d -> ", current->data); // Print the data of the current node
        current = current->next;         // Move to the next node
    }
    printf("NULL\n");
}

int main() {
    int n;
    
    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Ask the user to input the elements of the array
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    struct Node* head = NULL; // Initialize the head of the linked list

    // Copy elements from the array to the linked list
    arrayToLinkedList(arr, n, &head);

    // Display the linked list
    displayList(head);

    return 0;
}
