#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function for create newNode....
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!!!");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 1 --> Function for insert an element at any index..
struct node* insertInBet(struct node* head , int data , int index){
    struct node* p = head;
    struct node* newP = createNode(data);
    int i = 1;
    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    newP->next = p->next;
    p->next = newP;
    return head;
}

// 2--> Function for insert an element at the beginning..
struct node* insertAtBeg(struct node* head , struct node* tail , int data){
    struct node* newP = createNode(data);
    newP->next = head;
    tail->next = newP;
    head = newP;
    return head;
}

// 3--> Function for insert an element at last...
struct node* insertAtlast(struct node* head ,struct node* tail ,int data){
    struct node* newP = createNode(data);
    newP->next = head;
    tail->next = newP;
    tail = head;
    return head;
}

// 4--> Function for delete any node at any index..
struct node* delAnyNode(struct node* head, int index){
    struct node* temp = head;
    struct node* temp2;
    int i = 1;
    while (i != index-1)
    {
        temp = temp->next;
        i++;
    }
    temp2 = temp->next;
    
    temp->next = temp2->next;
    free(temp2);
    temp2 = NULL;
    return head;
} 

// 5--> Function for delete first element..
struct node* delFirstNode(struct node* head , struct node* tail){
    struct node* temp = head;
    temp = head->next;
    tail->next = temp;
    free(head);
    head = temp;
    return head;
}

// 6--> Function for delete last node..
struct node* delLastNode(struct node* head,struct node* tail){
    struct node* temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != tail);
    temp->next = head;
    free(tail);
    tail = temp;
    return head;
}


// Function for display list...
void Display_list(struct node* head){
    struct node* current = head;
    if (current == NULL)
    {
        printf("No such List is present yet!");
        exit(1);
    }

    do
    {
        printf("%d ",current->data);
        current = current->next;
    } while (current != head);  
    
}

int main()
{
    int n, data;
    struct node *head = NULL;
    struct node *tail;

    printf("Enter number of node : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d : ", i + 1);
        scanf("%d", &data);

        struct node *newNode = createNode(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    Display_list(head);

    printf("\nPress 1 : Insert an element into specific index\n");
    printf("Press 2 : Insert an element at the beginning of the linked list\n");
    printf("Press 3 : Insert an element at the last index of the linked list\n");
    printf("Press 4 : Delete an element from a user-specific index\n");
    printf("Press 5 : Delete an element from the beginning of the linked list\n");
    printf("Press 6 : Delete an element from last index of the linked list\n");
    printf("Enter 0 for exit\n");

    int choise,index,newData;
    
    while (choise != 0)
    {
        printf("Enter Your Choise : ");
        scanf("%d",&choise);
        
        switch (choise)
        {
        case 1:
            printf("Enter an index where you want to insert an element : ");
            scanf("%d",&index);

            printf("Enter a data for this node : ");
            scanf("%d",&newData);

            head = insertInBet(head ,newData, index);
            printf("New circular linked list : ");
            Display_list(head);
            printf("\n");
            break;
        
        case 2:
            printf("Enter a data for node which insert at first : ");
            scanf("%d",&newData);

            head = insertAtBeg(head,tail,newData);
            printf("New circular linked list : ");
            Display_list(head);
            printf("\n");
            break;

        case 3:
            printf("Enter a data for node which insert at last : ");
            scanf("%d",&newData);

            head = insertAtlast(head,tail,newData);
            printf("New circular linked list : ");
            Display_list(head);
            printf("\n");
            break;

        case 4:
            printf("Enter index for delete a node : ");
            scanf("%d",&index);

            head = delAnyNode(head , index);
            printf("New circular linked list : ");
            Display_list(head);
            printf("\n");
            break;
        
        case 5:
            head = delFirstNode(head,tail);
            printf("New circular linked list : ");
            Display_list(head);
            printf("\n");
            break;

        case 6:
            head = delLastNode(head,tail);
            printf("New circular linked list : ");
            Display_list(head);
            printf("\n");
            break;

        case 0:
            printf("Thank You!!");
            break;
        }
    }
    

    return 0;
}