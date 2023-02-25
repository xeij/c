#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Node {
    char key[20];
    char value[20];
    struct Node* next;
} Node;

Node* create_node(char* key, char* value) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->key, key);
    strcpy(node->value, value);
    node->next = NULL;
    return node;
}

unsigned int hash(char* key) {
    unsigned int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

Node** create_table() {
    Node** table = (Node**) malloc(TABLE_SIZE * sizeof(Node*));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
    return table;
}

void put(Node** table, char* key, char* value) {
    unsigned int index = hash(key);
    Node* node = table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            strcpy(node->value, value);
            return;
        }
        node = node->next;
    }
    Node* new_node = create_node(key, value);
    new_node->next = table[index];
    table[index] = new_node;
}

char* get(Node** table, char* key) {
    unsigned int index = hash(key);
    Node* node = table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void print_table(Node** table) {
    printf("Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        Node* node = table[i];
        while (node != NULL) {
            printf("(%s, %s) ", node->key, node->value);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Node** table = create_table();

    put(table, "apple", "a sweet fruit");
    put(table, "banana", "a yellow fruit");
    put(table, "cherry", "a small red fruit");

    print_table(table);

    printf("Definition of apple: %s\n", get(table, "apple"));
    printf("Definition of banana: %s\n", get(table, "banana"));
    printf("Definition of cherry: %s\n", get(table, "cherry"));
    printf("Definition of grape: %s\n", get(table, "grape"));

    return 0;
}
