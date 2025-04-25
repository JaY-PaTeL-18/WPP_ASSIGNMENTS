#include <stdio.h>

void bubbleSortDescending(int arr[], int n){
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements and swap if the current one is smaller
            if (arr[j] < arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of element for both array : ");
    scanf("%d",&n);
   
    //For define array1...
    printf("Enter %d integer for first array:\n",n);
    
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    //for define array2...
    printf("Enter %d integer for second array:\n",n);
    
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    //printing of both arrays....
    printf("First array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr1[i]);
    }
    printf("\nsecond array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr2[i]);
    }

    int size = 2*n ;                                  //for define size of merge_array...
    int merge_arr[size];

    for (int i = 0; i < n; i++)
    {
        merge_arr[i] = arr1[i];
        merge_arr[n+i] = arr2[i];
    }

    printf("\nElement in merged array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",merge_arr[i]);
    }
    
    bubbleSortDescending(merge_arr,size);
    
    printf("\n");

    printf("Arranging in decreasing order :");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",merge_arr[i]);
    }
    

    return 0;
}