#include <iostream>

void sorter(char array[], int size) {

    int i, j, temp;

    for (i = 0;i < size - 1;i++) {
        for (j = 0; j < size - i - 1;j++) {

            if (array[j] > array[j + 1]) {

                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

}

int main() {

    char array[] = {'N','B','W','H','S','P'};

    int size = sizeof(array) / sizeof(array[0]);
    printf("\n Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", array[i]);
    }

    sorter(array, size);


    printf("\n Sorted   Array: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", array[i]);
    }

    return 0;
}
