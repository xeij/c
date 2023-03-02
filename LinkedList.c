#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Insert a new node at the beginning of the list
void insert_node(struct node **head_ref, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void delete_node(struct node **head_ref, int data) {
   
    if (*head_ref == NULL) {
        return;
    }

    struct node *current = *head_ref;
    struct node *previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (previous == NULL) {
        *head_ref = current->next;
    } else { 
        previous->next = current->next;
    }

    free(current);
}

void print_list(struct node *head) {
    printf("List contents: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}   

int main() {
  
    struct node *head = NULL;

    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);

    print_list(head);


    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
