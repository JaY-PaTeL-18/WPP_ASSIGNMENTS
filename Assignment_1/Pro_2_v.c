#include<stdio.h>

void rearrangeArray(int arr[], int n) {
    int i = 0, j = n - 1;
    
    while (i < j) {
        // If arr[i] is negative and arr[j] is positive, don't swap
        if (arr[i] < 0 && arr[j] >= 0) {
            i++;
            j--;
        }
        // If arr[i] is positive and arr[j] is negative, swap
        else if (arr[i] >= 0 && arr[j] < 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        // If both are negative, move left pointer forward
        else if (arr[i] < 0 && arr[j] < 0) {
            i++;
        }
        // If both are positive, move right pointer backward
        else {
            j--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int n ;
    printf("Enter number of element for array : ");
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Original array : ");
    printArray(arr,n);

    rearrangeArray(arr,n);
    printf("arranged array : ");
    printArray(arr,n);    



    return 0;
}