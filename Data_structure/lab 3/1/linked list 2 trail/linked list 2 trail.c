#include <stdio.h>
#include <stdlib.h>


typedef struct linked_list_node linked_list_node;

struct linked_list_node {
    int data; //Data part
    linked_list_node *next; //Address part
};

typedef struct linked_list linked_list;



struct linked_list{
    linked_list_node* head;
    linked_list_node* tail;
};

linked_list* createList(int n); // Functions to create a list


linked_list_node* create_linked_list_node(int node_data) {
    linked_list_node* node = malloc(sizeof(linked_list_node));

    node->data = node_data;
    node->next = NULL;
    return node;
}

void insert_node_into_singly_linked_list(linked_list** singly_linked_list, int node_data) {
    linked_list_node* node = create_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    }
    else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

/*

typedef struct linked_list_node_double linked_list_node_double;

struct linked_list_node_double{

    int data;
    linked_list_node_double *next; // Pointer to next node in DLL
    linked_list_node_double *prev; // Pointer to previous node in DLL

};

linked_list_node_double* create_linked_list_node(int node_data) {
    linked_list_node_double* node_double = malloc(sizeof(linked_list_node_double));

    node_double->prev = NULL;
    node_double->data = node_data;
    node_double->next = NULL;
    return node_double;
}
*/




int main()
{
    int in;
    int test=0;
    int counter=1;

    scanf("%d",&in);
    int temp = in;

    while (test==0){
        if(temp/10 !=0){
                temp=temp/10;
                counter++;
    }
    else
        test=1;
   }
    char *charValue =   calloc(counter,sizeof(char));
    itoa(in,charValue,10);

    printf("number of digits in in = %d\n",counter);


    return 0;
}
