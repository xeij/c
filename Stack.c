#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int data[MAX_STACK_SIZE];
} Stack;

void push(Stack* stack, int value) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

int main() {
    Stack stack = { .top = -1 };

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("%d\n", pop(&stack)); // prints 3
    printf("%d\n", pop(&stack)); // prints 2
    printf("%d\n", pop(&stack)); // prints 1

    return 0;
}
