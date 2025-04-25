#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*top = NULL;

int isEmpty(){
    if (top == NULL){return 1;}
    else{ return 0 ;}
}

struct node* push(struct node* top , int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Stack overflow!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;
    return top;
}

struct node* pop(struct node* top){
    struct node* ptr = top;
    if (isEmpty())
    {
        printf("Stack underflow.");
        exit(1);
    }
    
    int val = ptr->data;
    
    top = ptr->next;
    free(ptr);
    ptr = NULL;

    printf("Deleted element is %d.\n",val);
    return top;
}

int peek(){
    if (isEmpty())
    {
        printf("Stack underflow.");
        exit(1);
    }
    return top->data;
}

void Display(){
    struct node* temp = top;
    if (isEmpty())
    {
        printf("Stack underflow.");
        exit(1);
    }

    printf("Stack elements are : ");
    while (temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}

int main(){
    int choise , data;

    printf("Press 1 : For push data into stack-->[push()].\n");
    printf("Press 2 : For delete data from stack-->[pop()].\n");
    printf("Press 3 : For print first elment-->[peek()]\n");
    printf("Press 4 : For print stack.\n");
    printf("For exit click 0.\n");

    while (choise != 0)
    {
        printf("Enter your choise : ");
        scanf("%d",&choise);

        switch (choise)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            top = push(top,data);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            data = peek();
            printf("Top element is : %d.\n",data);
            break;
        case 4:
            Display();
            break;
        case 0:
            printf("\nThank You!!");
            exit(1);
        default:
            printf("Not vaild choise..");
        }
    }
    
    
    return 0;
}
