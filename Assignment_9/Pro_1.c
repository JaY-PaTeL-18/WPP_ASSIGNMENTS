#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

void init(PriorityQueue *pq) {
    pq->size = 0;
}

void insert(PriorityQueue *pq, int value) {
    if (pq->size == MAX) {
        printf("Priority Queue is full\n");
        return;
    }
    pq->data[pq->size++] = value;
    int i = pq->size - 1;
    while (i > 0 && pq->data[i] > pq->data[(i - 1) / 2]) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void heapify(PriorityQueue *pq, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->data[left] > pq->data[largest])
        largest = left;

    if (right < pq->size && pq->data[right] > pq->data[largest])
        largest = right;

    if (largest != i) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[largest];
        pq->data[largest] = temp;
        heapify(pq, largest);
    }
}

int extractMax(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int max = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    heapify(pq, 0);
    return max;
}

int peek(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }
    return pq->data[0];
}

void delete(PriorityQueue *pq, int index) {
    if (index < 0 || index >= pq->size) {
        printf("Index out of bounds\n");
        return;
    }
    pq->data[index] = pq->data[--pq->size];
    heapify(pq, index);
}

int main() {
    PriorityQueue pq;
    init(&pq);

    int choice, value, index;
    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Peek\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&pq, value);
                break;
            case 2:
                printf("Extracted max: %d\n", extractMax(&pq));
                break;
            case 3:
                printf("Max element: %d\n", peek(&pq));
                break;
            case 4:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                delete(&pq, index);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    printf("Max element: %d\n", peek(&pq));
    printf("Extracted max: %d\n", extractMax(&pq));
    printf("Max element after extraction: %d\n", peek(&pq));

    delete(&pq, 2);
    printf("Max element after deletion: %d\n", peek(&pq));

    return 0;
}