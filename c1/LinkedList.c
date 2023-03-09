#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_node(struct node **head_ref, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void delete_node(struct node **head_ref, int position) {

    struct node *current = *head_ref;
    struct node *previous = *head_ref;

    if (*head_ref == NULL){
        return;
    } else if (position == 1){
        *head_ref= current->next;
        free(current);
        current = NULL;
    }
        else {

            while(position != 1){
                previous = current;
                current = current->next;
                position--;
            }
            previous->next = current->next;
            free(current);
            current = NULL;
    }
}

/*
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
*/

void print_list(struct node *head) {
    printf("List contents: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}   

void free_temp(struct node *head){
    
    while(head != NULL){
        struct node *temp = head;
        head = head->next;
        free(temp);
        }       
}

int main() {
  
    struct node *head = NULL;

    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);

    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    free_temp(head);

    return 0;
}