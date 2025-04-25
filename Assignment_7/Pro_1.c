#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return s->top == (MAX - 1);
}

// Function to push an element onto the stack
void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
    } else {
        s->arr[++(s->top)] = value;
    }
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

// Function to get the top element of the stack without removing it
char peek(struct Stack *s) {
    if (isEmpty(s)) {
        return -1;
    } else {
        return s->arr[s->top];
    }
}

// Function to check precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else {
        return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to check if a character is an operand (a digit)
int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);  // Letters or digits are operands
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        if (isOperand(current)) {
            // If the character is an operand, add it to the postfix expression
            postfix[j++] = current;
        } else if (current == '(') {
            // If the character is '(', push it onto the stack
            push(&s, current);
        } else if (current == ')') {
            // If the character is ')', pop from the stack until '(' is encountered
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Pop '(' from stack
        } else if (isOperator(current)) {
            // If the character is an operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(current)) {
                postfix[j++] = pop(&s);
            }
            push(&s, current);
        }

        i++;
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Main function to test the infix to postfix conversion
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    gets(infix);  // Use fgets for safer input handling in real applications
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
