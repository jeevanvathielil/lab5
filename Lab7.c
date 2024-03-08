#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n, int swapCounts[]);
void selectionSort(int arr[], int n, int swapCounts[]);
void printSwapCounts(int arr[], int n, int swapCounts[], int totalSwaps);
void initializeSwapCounts(int swapCounts[], int n);
int findIndex(int arr[], int n, int value);

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int swapCounts1[n1];
    initializeSwapCounts(swapCounts1, n1);
    
    printf("array1 bubble sort:\n");
    bubbleSort(array1, n1, swapCounts1);
    
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swapCounts2[n2];
    initializeSwapCounts(swapCounts2, n2);
    
    printf("array2 bubble sort:\n");
    bubbleSort(array2, n2, swapCounts2);

    int swapCounts3[n1];
    initializeSwapCounts(swapCounts3, n1);
    
    printf("array1 selection sort:\n");
    selectionSort(array1, n1, swapCounts3);

    int swapCounts4[n2];
    initializeSwapCounts(swapCounts4, n2);
    
    printf("array2 selection sort:\n");
    selectionSort(array2, n2, swapCounts4);

    return 0;
}

void bubbleSort(int arr[], int n, int swapCounts[]) {
    int i, j, temp, totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapCounts[j]++;
                swapCounts[j+1]++;
                totalSwaps += 2; // Incrementing by 2 since two elements are swapped
            }
        }
    }
    printSwapCounts(arr, n, swapCounts, totalSwaps);
}

void selectionSort(int arr[], int n, int swapCounts[]) {
    int i, j, minIdx, temp, totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        minIdx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;

            swapCounts[i]++;
            swapCounts[minIdx]++;
            totalSwaps += 2; // Incrementing by 2 since two elements are swapped
        }
    }
    printSwapCounts(arr, n, swapCounts, totalSwaps);
}

void printSwapCounts(int arr[], int n, int swapCounts[], int totalSwaps) {
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swapCounts[i]);
    }
    printf("%d\n\n", totalSwaps / 2); // Divide by 2 because we incremented by 2 for each swap
}

void initializeSwapCounts(int swapCounts[], int n) {
    for (int i = 0; i < n; i++) {
        swapCounts[i] = 0;
    }
}
