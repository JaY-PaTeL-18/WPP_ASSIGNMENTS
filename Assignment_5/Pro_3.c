#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *link;
};

// Function for sorting list...
struct node *insert(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *newP = malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expo = ex;
    newP->link = NULL;

    if (head == NULL || ex > head->expo)
    {
        newP->link = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->expo >= ex)
        {
            temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

// Function for create list...
struct node* create(struct node *head)
{
    int n, i, expo;
    float coeff;

    printf("Enter number of terms : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d : ", i + 1);
        scanf("%f", &coeff);

        printf("Enter the power of term %d : ", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
};

// Function for display polynomial...
void DisplayList(struct node *head)
{
    if (head == NULL)
    {
        printf("No such a polynomial!!");
    }
    else
    {
        struct node *temp = head;
        printf("Polynomial : ");
        while (temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

// Funtion for multiply two polynomial..
void polymult(struct node* head1 , struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3;

    if (head1 ==NULL || head2 == NULL)
    {
        printf("0");
        return;
    }

    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            head3 = insert(head3 , (ptr1->coeff * ptr2->coeff) , (ptr1->expo + ptr2->expo));
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }

    DisplayList(head3);
    
    //final ans..
    struct node* temp = NULL;
    struct node* ptr3 = head3;
    
    while (ptr3->link!=NULL)
    {
        if (ptr3->expo == ptr3->link->expo)
        {
            ptr3->coeff = ptr3->coeff + ptr3->link->coeff;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
            temp=NULL;
        }
        else{
            ptr3 = ptr3->link;
        }
        
    }
    DisplayList(head3);
    
}


int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Enter the first polynomial\n");
    head1 = create(head1);

    printf("\n");

    printf("Enter the second polynomial\n");
    head2 = create(head2);

    DisplayList(head1);
    DisplayList(head2);

    printf("After multiply this two polynomial:\n ");
    polymult(head1,head2);

    return 0;
}