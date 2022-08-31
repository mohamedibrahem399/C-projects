#include <stdio.h>
#include <stdlib.h>
typedef struct single_linked_list single_linked_list;
typedef struct linked_list_node linked_list_node;


struct single_linked_list{
    single_linked_list* head;
    single_linked_list* tail;
};

struct linked_list_node {
    int data; //Data part
    linked_list_node *next; //Address part
};


linked_list_node* create_linked_list_node(int node_data) {
    linked_list_node* node = malloc(sizeof(linked_list_node));

    node->data = node_data;
    node->next = NULL;
    return node;
}

// ##########################################################

typedef struct double_linked_list double_linked_list;
typedef struct linked_list_node_double linked_list_node_double;

struct double_linked_list{
    double_linked_list* head;
    double_linked_list* tail;
};


struct linked_list_node_double{

    int data;
    linked_list_node_double *next; // Pointer to next node in DLL
    linked_list_node_double *prev; // Pointer to previous node in DLL

};

linked_list_node_double* create_double_linked_list_node(int node_data) {
    linked_list_node_double* node_double = malloc(sizeof(linked_list_node_double));

    node_double->prev = NULL;
    node_double->data = node_data;
    node_double->next = NULL;
    return node_double;
}


int main()
{
    printf("here we see how to define single or double linked list\n");

    return 0;
}
