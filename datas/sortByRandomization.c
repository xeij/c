#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int arr[], int size) {
    if (size > 1) {
        int i;
        for (i = 0; i < size - 1; i++) {
            int j = i + rand() / (RAND_MAX / (size - i) + 1);
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
}

int isSorted(int arr[], int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;  // Array is not sorted
        }
    }
    return 1;  // Array is sorted
}

void randomizeSort(int arr[], int size) {
    if (isSorted(arr, size) == 0) {
        shuffle(arr, size);
        randomizeSort(arr, size);
    }
}

int main() {
    srand(time(NULL));
    int arr[] = {1, 5, 4, 2, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    randomizeSort(arr, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}