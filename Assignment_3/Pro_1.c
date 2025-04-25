// Write a program in C to create and display a Singly link list.

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
    struct Node* temp = NULL;
    int n, data;

    // Ask the user for the number of nodes to create
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        // Create a new node
        struct Node* newNode = createNode(data);

        // If it's the first node, set the head
        if (head == NULL) {
            head = newNode;
        } else {
            // Otherwise, find the last node and append the new node
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display the linked list
    printf("\nThe linked list is: ");
    displayList(head);

    return 0;
}
