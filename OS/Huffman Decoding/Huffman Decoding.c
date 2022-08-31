#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_IN 10001

int pu = 0;

typedef struct Node node;

struct Node
{
    int frequency;
    char data;
    struct Node *next;
    struct Node *left,*right;
};


node *create_node(char data , int frequency)
{
    node * node1 = (node*) malloc(sizeof(node));
    //data
    node1->frequency =frequency;
    node1->data  = data;
    //pointers
    node1->next  = NULL;
    node1->left  = NULL;
    node1->right = NULL;

    return node1;
}

node *sub_tree (node *node1 , node *node2){

    node * temp = (node*) malloc(sizeof(node));

    temp->frequency = node1->frequency + node2->frequency;
    temp->data='_';
    temp->next = NULL;
/*
    int frequency1 =node1-> frequency;
    int frequency2 =node2-> frequency;
    int data1 =node1->data;
    int data2 =node2->data;
*/
    if (( node1-> frequency  > node2-> frequency ) || ( ( node1-> frequency == node2-> frequency ) && ( node1->data < node2->data ) ) ) {
        node *temp_swap = node1;
        node1 = node2 ;
        node2 = temp_swap;
    }

    temp->left  = node1;
    temp->right = node2;

    return temp;
}


void insert_new_node (node **ls, node *node_in)
{
    node *temp_current = *ls;
    node *temp_pre  = *ls;

    if (temp_current == NULL || temp_pre == node_in) return;
    //zero duplicated elements
    if (temp_current->frequency == 0){
        temp_current = node_in;
        *ls = temp_current;
        return;
    }
/*
    int node_in_freq = node_in->frequency ;
    int current_temp_freq = temp_current->frequency;
*/
    while ( (temp_current->next !=NULL) && (node_in->frequency > temp_current->frequency) ){
        temp_pre = temp_current;
        temp_current = temp_current->next;
    }

    if (  (temp_current->next == NULL ) && (node_in->frequency > temp_current->frequency) ){
        temp_current->next = node_in;
        return;
    }

    while (temp_current->data >= node_in->data&& temp_current-> frequency == node_in->frequency){
            if(temp_current->next == NULL){
                temp_current->next = node_in;
                return;
            }
            temp_pre     = temp_current;
            temp_current = temp_current->next;
    }

    if (temp_pre == temp_current) {
        node_in->next = temp_current;
        *ls = node_in;
    }

    else {
        temp_pre->next = node_in;
        node_in->next = temp_current;
    }


}

int main() {
    int i;

    node * node_new = (node*) malloc (sizeof(node));

    node_new->frequency = 0;
    node_new->next = NULL;

    char s[MAX_IN];//string
    char e[MAX_IN];//entered code

    scanf("%[^\n]",s);
    scanf("%s",e);

    int string_length = strlen(s);
    int entered_code_length = strlen(e);

    //printf("string_length = %d , entered_code_length = %d \n",string_length,entered_code_length);

    if(string_length < 2 || entered_code_length < 1) return 0;

    int *arr1= malloc(string_length * sizeof(int));
    char *arr2 = malloc(string_length * sizeof(int));

    int j;
    int count=0;
    int counter2=0;

    for (i=0 ; i< string_length ; i++){
        counter2=0;
        char one_digit_from_the_string = s[i];
        for ( j = 0 ; j < count ; j++){
            if( one_digit_from_the_string == arr2[j]){
                counter2 = 1;
                break;
            }
        }
        if (counter2){
            //printf("counter2 = %d\n",counter2);
            arr1[j]++;
            continue;
        }

        arr2[count] = one_digit_from_the_string;
        arr1[count++] = 1 ;

    }


    for (i=0; i < count ; i++){
        insert_new_node(&node_new , create_node(arr2[i],arr1[i]));
    }
    node* temp4 = node_new;
    while( count > 1 ){
        insert_new_node(&node_new->next , sub_tree(node_new , node_new->next) );

        if(node_new->next != NULL){
            if(  (node_new == temp4) && ( (node_new->next->next) != NULL)  ){
            node_new = (node_new->next->next) ;
            temp4    =  node_new ;
            }
            else {
                node_new = node_new->next;
            }
        }
        count--;
    }

    i = 0;

    while (i<entered_code_length){
        node * tm = node_new;

        while(tm->left != NULL) {
            if(e[i++] == '1'){
                    tm= tm->right;
                }
            else {
                    tm= tm-> left;
                }
        }

        if(i <= entered_code_length){
            printf("%c",tm->data);
        }

    }
return 0;
}
