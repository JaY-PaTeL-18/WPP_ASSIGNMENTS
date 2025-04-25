//2. Write a C program to create a doubly linked list and perform the following operations on it.
//    a) Insert an element at any position
//    b) Delete an element at any position

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* previous;
    struct Node* next;
};


void create_linked_list(struct Node** Head, struct Node** Tail, int n) {
    struct Node* prev, *new_node;
    for (int i = 0; i < n; i++)
    {
        if ((*Head)==NULL)
        {
            (*Head) = (struct Node*) malloc(sizeof(struct Node));
            scanf("%d", &(*Head)->data);
            (*Head)->next = NULL;
            (*Head)->previous = NULL;
            prev = (*Head);
        } else
        {
            new_node = (struct Node*) malloc(sizeof(struct Node));
            scanf("%d", &new_node->data);
            new_node->previous = prev;
            new_node->next = NULL;
            prev->next = new_node;
            prev = new_node;
        }
    }
    (*Tail) = prev;
}


void display(struct Node* Head) {
    struct Node* temp = Head;
    printf("Your linked list: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void insert_elem(struct Node** Head, int position, int elem) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = elem;
    if (position==1)
    {
        temp->next = (*Head);
        temp->previous = NULL;
        (*Head)->previous = temp;
        (*Head) = temp;
    } else {
        struct Node* prev = (*Head);
        for (int i = 1; i < position-1; i++) {
            prev = prev->next;
        }
        temp->next = prev->next;
        temp->previous = prev;
        prev->next = temp;
        prev->next->previous = temp;
    }
}


void delete_elem(struct Node** Head, int position) {
    struct Node* temp;
    if (position==1)
    {
        temp = (*Head)->next;
        free((*Head));
        (*Head) = temp;
        printf("%d", (*Head)->data);
    } else {
        struct Node* prev = (*Head), *curr = prev->next;
        for (int i = 1; i < position-1; i++) {
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
    }
}


int main() {
    struct Node* Head;
    struct Node* Tail;
    Head = NULL;

    // creating linked list
    int n;
    printf("How many elements you wanna enter: ");
    scanf("%d", &n);
    printf("Enter Elements: ");

    create_linked_list(&Head, &Tail, n);
    display(Head);

    
    // (a) insert at any node in linked list by taking input from user
    int position, elem;
    printf("Enter position of element for insertion: ");
    scanf("%d", &position);
    printf("Enter Element: ");
    scanf("%d", &elem);

    insert_elem(&Head, position, elem);
    display(Head);


    // (b) deletion of element
    printf("Enter position of element to delete: ");
    scanf("%d", &position);

    delete_elem(&Head, position);
    display(Head);

    return 0;
}