#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int top = -1;
int stack_arr[MAX];

// Function for checking stake is empty or not...
int IsEmpty(){
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function for checking stack is full or not..
int Isfull(){
    if (top == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}


// Function PUSH for add element in stack..
void push(int data){
    if (Isfull())
    {
        printf("Stack is overflow");
        return;
    }
    top++;
    stack_arr[top] = data;
}

// Function POP for delete element in stack...
int pop(){
    int value;
    
    if (IsEmpty())
    {
        printf("Stack underflow");
        exit(1);
    }
    
    value = stack_arr[top];
    top--;
    return value;
}

int peek(){
    if (IsEmpty())
    {
        printf("Stack underflow");
        exit(1);
    }
    return stack_arr[top];
}

// Function for printing stack...
void print(){
    if (top == -1)
    {
        printf("Stack underflow");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d ",stack_arr[i]);
    } 
    printf("\n");
}



int main(){

    int choise , data;

    printf("\nPress 1 : for push\n");
    printf("Press 2 : for pop\n");
    printf("Press 3 : for print top element\n");
    printf("Press 4 : for printing all element\n");
    printf("Enter 0 for exit\n");

    while (choise != 0)
    {
        printf("\nEnter Your choise : ");
        scanf("%d",&choise);

        switch (choise)
        {
        case 1:
            printf("Enter data for add element in stack : ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Deleted element from the stack is : %d",data);
            break;
        case 3:
            printf("Top element of this stack : %d",peek());
            break;
        case 4:
            print();
            break;
        case 0:
            printf("Thank You");
            break;
        }
        
    }
    
    
    return 0;
}