#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of an array : ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %dth elment : ", i + 1);
        scanf("%d", &arr[i]);
    }


    int even_arr[n] , odd_arr[n];
    int even_numbs = 0 , odd_nums = 0 ;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_arr[even_numbs] = arr[i];
            even_numbs++;
        }

        else
        {
            odd_arr[odd_nums] = arr[i];
            odd_nums++;
        }
    }

    // for printing odd and even array::
    printf("Even number's array : ");
    for (int i = 0; i < even_numbs; i++)
    {
        printf("%d ", even_arr[i]);
    }

    printf("\nOdd number's array : ");
    for (int i = 0; i < odd_nums; i++)
    {
        printf("%d ", odd_arr[i]);
    }

    return 0;
}