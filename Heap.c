#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct Heap {
    int* array;
    int size;
} Heap;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap* create_heap() {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->array = (int*) malloc(MAX_HEAP_SIZE * sizeof(int));
    heap->size = 0;
    return heap;
}

void heapify(Heap* heap, int index) {
    int largest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child < heap->size && heap->array[left_child] > heap->array[largest]) {
        largest = left_child;
    }

    if (right_child < heap->size && heap->array[right_child] > heap->array[largest]) {
        largest = right_child;
    }

    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        heapify(heap, largest);
    }
}

void insert(Heap* heap, int value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full, cannot insert.\n");
        return;
    }

    int index = heap->size;
    heap->array[index] = value;
    heap->size++;

    while (index != 0 && heap->array[(index - 1) / 2] < heap->array[index]) {
        swap(&heap->array[index], &heap->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void remove_max(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty, cannot remove.\n");
        return;
    }

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
}

void print_heap(Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main() {
    Heap* heap = create_heap();

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 5);

    print_heap(heap);

    remove_max(heap);

    print_heap(heap);

    return 0;
}
