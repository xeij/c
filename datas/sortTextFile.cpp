/*Sorts a text file of words.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_NUM_WORDS 10000

void quick_sort(char *arr[], int left, int right) {
    if (left < right) {
        int pivot = (left + right) / 2;
        int i = left - 1;
        int j = right + 1;

        while (1) {
            do {
                i++;
            } while (strcmp(arr[i], arr[pivot]) < 0);

            do {
                j--;
            } while (strcmp(arr[j], arr[pivot]) > 0);

            if (i >= j) {
                break;
            }

            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        quick_sort(arr, left, j);
        quick_sort(arr, j + 1, right);
    }
}

int main() {
    char filename[] = "words.txt";
    char *words[MAX_NUM_WORDS];
    int num_words = 0;
    FILE *fp;
    char word[MAX_WORD_LEN];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }

    while (fscanf(fp, "%s", word) == 1) {
        words[num_words] = (char *)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(fp);

    quick_sort(words, 0, num_words - 1);

    printf("Sorted words:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    return 0;
}