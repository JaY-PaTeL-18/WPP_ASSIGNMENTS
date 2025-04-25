//Write a program in C to insert a new node at the beginning of a Singly Linked List.

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

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);   // Create the new node
    newNode->next = *head;                      // Make the next of the new node point to the current head
    *head = newNode;                            // Update the head to the new node
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;   // Start from the head
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);  // Print the data of the current node
        current = current->next;          // Move to the next node
    }
    printf("NULL\n");  // End of the list
}

int main() {
    struct Node* head = NULL;   // Initialize the head of the linked list
    int n, data, newData;

    // Ask the user for the number of nodes to create
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list by inserting nodes at the beginning
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        // Insert each node at the beginning
        insertAtBeginning(&head, data);
    }

    // Display the linked list
    printf("\nThe linked list is: ");
    displayList(head);

    // Ask the user for the new node data to insert at the beginning
    printf("Enter data for the new node to insert at the beginning: ");
    scanf("%d", &newData);

    // Insert the new node at the beginning
    insertAtBeginning(&head, newData);

    // Display the updated linked list
    printf("\nThe updated linked list is: ");
    displayList(head);

    return 0;
}
