#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sorter(char array[], int size){
int i,j,temp;


for(i=0; i<size-1;i++){
    for(j=0; j<size-i-1;j++){

        if(array[j] > array[j+1]){
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;

            }
        }
    }
}

void sorter2(char array[][100], int size){

int i,j;
char temp[100];

    for(i=0; i<size; i++){
    strcpy(temp, array[i]);
    j = i-1;

        while(j>=0 && strcmp(array[j], temp) > 0){
            strcpy(array[j+1], array[j]);
            j--;
    }

        strcpy(array[j+1], temp);

    }

}



int main(){


    char array[][100] = {"Apple", "Orange", "Banana", "Pineapple"};
    int size = sizeof(array)/sizeof(array[0]);

    int i;
    printf("Original string: ");
    for(i=0; i<size; i++){
        printf("%s ", array[i]);
    }
    
    sorter2(array, size);

    printf("\nSorted string: ");
    for(i=0; i<size; i++){
        printf("%s ", array[i]);
    }
    
    return 0;
}