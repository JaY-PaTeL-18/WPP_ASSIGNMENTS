#include<stdio.h>

void Insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int ptr = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > ptr) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = ptr;
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements for array: ");
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    Insertionsort(arr, n);

    printf("The sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}