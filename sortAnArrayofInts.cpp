#include <iostream>

void algo(int array[], int size){

    int i,j,temp;
        for(int i =0; i<size-1; i++){
            for(int j =0; j<size-i-1; j++){
                 if(array[j] > array[j+1]){

                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                 }
            }
        }
    }

int main(){

    int array[]= {1,4,3,2};
    int size = sizeof(array) / sizeof(array[0]);

    printf("\nOriginal array: ");
    for(int i=0; i<size; i++){
        printf("%d", array[i]);
    }

    algo(array,size);

    printf("\nSorted   array: ");
    for(int i=0; i<size; i++){
        printf("%d", array[i]);
    }

    return 0;
}







 










