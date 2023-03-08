#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void insert_node(struct node **head_ref, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void delete_node(struct node **head_ref, int data){


}

void print_list(struct node *head){
    printf("List contents: ");
    while(head != NULL){
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

int main(){

    struct node *head = NULL; 

    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);
    
    print_list(head);
    free_temp(head);

    return 0;
}