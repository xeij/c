//Shaya Arya

#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
    };    

struct node *head = NULL;

void insert_node(struct node **head_ref, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    }

void insert_data(){
    int array[5];
    int data;
    int size = sizeof(array)/sizeof(array[0]);
    
        for(int i=0; i<size; i++){
            scanf("%d", &data);
            insert_node(&head, data);
        }
    }

void print_data(struct node *head){
    printf("\nLinked List now contains data: ");
    printf("\n");
        while(head != NULL){
            printf("%d ", head->data);
            head = head->next;
        }
    printf("\n");
}

void free_mem(struct node *head){
    while(head != NULL){
        struct node *temp = head;
        head=head->next;
        free(temp);
    }
}

int main(){

    insert_data();
    print_data(head);
    free_mem(head);

    return 0;
}


    