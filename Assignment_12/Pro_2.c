#include<stdio.h>

void redixsort(int arr[], int n) {
    int i, j, k;
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (k = 1; max / k > 0; k *= 10) {
        int output[n];
        int count[10] = {0};
        for (i = 0; i < n; i++) {
            count[(arr[i] / k) % 10]++;
        }
        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / k) % 10] - 1] = arr[i];
            count[(arr[i] / k) % 10]--;
        }
        for (i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}   

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the elements: ");
        scanf("%d", &arr[i]);
    }
    redixsort(arr, n);
    printArray(arr, n);
    
    return 0;
    
}