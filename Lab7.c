#include <stdio.h>

void bubbleSort(int arr[], int n, int swapCount[]) {
    int i, j, temp, totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // Count swaps
                swapCount[arr[j]]++;
                swapCount[arr[j+1]]++;
                totalSwaps++;
            }
        }
    }
    // Print individual swaps
    for (i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swapCount[arr[i]]);
    }
    // Print total swaps
    printf("Total # of swaps: %d\n\n", totalSwaps);
}

void selectionSort(int arr[], int n, int swapCount[]) {
    int i, j, minIdx, temp, totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        minIdx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            // Swap elements
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;

            // Count swaps
            swapCount[arr[i]]++;
            swapCount[arr[minIdx]]++;
            totalSwaps++;
        }
    }
    // Print individual swaps
    for (i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swapCount[arr[i]]);
    }
    // Print total swaps
    printf("Total # of swaps: %d\n\n", totalSwaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int swapCount1[100] = {0}; // Assuming values in array do not exceed 100

    printf("Array1 - Bubble Sort:\n");
    bubbleSort(array1, n1, swapCount1);

    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swapCount2[100] = {0}; // Assuming values in array do not exceed 100

    printf("Array2 - Selection Sort:\n");
    selectionSort(array2, n2, swapCount2);

    return 0;
}
