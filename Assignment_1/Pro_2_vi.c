#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int findMaxSumPath(int *arr1, int len1, int *arr2, int len2) {
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0;
    int maxSum = 0;

    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            sum1 += arr1[i];
            i++;
        } else if (arr1[i] > arr2[j]) {
            sum2 += arr2[j];
            j++;
        } else {
            maxSum += (sum1 > sum2) ? sum1 : sum2;
            maxSum += arr1[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }

    while (i < len1) {
        sum1 += arr1[i];
        i++;
    }
    while (j < len2) {
        sum2 += arr2[j];
        j++;
    }

    maxSum += (sum1 > sum2) ? sum1 : sum2;
    return maxSum;
}

void findClosestPair(int *arr1, int len1, int *arr2, int len2, int x) {
    int i = 0, j = len2 - 1;
    int closestSum = INT_MAX;
    int closestPair[2];

    while (i < len1 && j >= 0) {
        int sum = arr1[i] + arr2[j];

        if (abs(x - sum) < abs(x - closestSum)) {
            closestSum = sum;
            closestPair[0] = arr1[i];
            closestPair[1] = arr2[j];
        }

        if (sum < x) {
            i++;
        } else {
            j--;
        }
    }

    printf("The closest pair is: (%d, %d) with sum %d\n", closestPair[0], closestPair[1], closestSum);
}

int main() {
    int arr1[] = {2, 3, 5, 7, 11, 13};
    int arr2[] = {1, 3, 6, 7, 13, 19};
    int x = 10;

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    int maxPathSum = findMaxSumPath(arr1, len1, arr2, len2);
    printf("The max sum path b/w the two arrays is: %d\n", maxPathSum);

    findClosestPair(arr1, len1, arr2, len2, x);

    return 0;
}
