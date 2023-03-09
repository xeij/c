#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow!\n");
        exit(1);
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Queue underflow!\n");
        exit(1);
    }
    queue->front++;
    return queue->data[queue->front];
}

int main() {
    Queue queue = { .front = 0, .rear = -1 };

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("%d\n", dequeue(&queue)); // prints 1
    printf("%d\n", dequeue(&queue)); // prints 2
    printf("%d\n", dequeue(&queue)); // prints 3

    return 0;
}
