/* Write a C program to hold two integer pointers as structure members. Allocate space
   for the structure and its data members during runtime. Get one array as input. In the
   second array copy the elements of the first array and replace the odd positioned
   elements by the product of its adjacent elements. Access the array elements and
   structures using pointers instead of subscript notation.
*/

#include <stdio.h>
#include <stdlib.h>

struct two_pointer {
    int* n1;
    int* n2;
};

int main() {
    struct two_pointer* a = (struct two_pointer*)malloc(sizeof(struct two_pointer));
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    a->n1 = (int*)malloc(size * sizeof(int));
    a->n2 = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", (a->n1 + i));
    }

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            *(a->n2 + i) = *(a->n1 + i);
        } else {
            if (i == size - 1) {
                *(a->n2 + i) = *(a->n1 + i); // Last element remains the same if odd positioned
            } else {
                *(a->n2 + i) = (*(a->n1 + (i - 1))) * (*(a->n1 + (i + 1)));
            }
        }
    }

    printf("First array (n1):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(a->n1 + i));
    }
    printf("\n");

    printf("Second array (n2):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(a->n2 + i));
    }
    printf("\n");

    free(a->n1);
    free(a->n2);
    free(a);

    return 0;
}