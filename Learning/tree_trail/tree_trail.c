#include <stdio.h>
#include <stdlib.h>

// binary tree

typedef struct bin_tree bin_tree;
typedef struct sub_tree sub_tree;
typedef struct tree_node tree_node;

struct sub_tree {

    struct tree_node *parent;
    struct tree_node *left_child , *right_child ;

};

struct tree_node {

    int data;

    struct tree_node *left;
    struct tree_node *right;
};

struct bin_tree
{
    // root
    //  2 children type subtree
    struct tree_node *root;
    struct sub_tree *left_child ;
    struct sub_tree *right_child;
};
//creating tree_node
tree_node* create_tree_node(int data){
    tree_node *node = malloc( sizeof(tree_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//creating sub_tree
sub_tree* create_sub_tree(sub_tree** sub_tree_in){
     *sub_tree_in  = malloc(sizeof(sub_tree));
    (*sub_tree_in)->parent       = NULL;
    (*sub_tree_in)->left_child   = NULL;
    (*sub_tree_in)->right_child  = NULL;
    return *sub_tree_in;
}
//creating bin_tree
bin_tree* create_bin_tree(bin_tree** bin_tree_in){

    *bin_tree_in = malloc(sizeof(bin_tree_in));

    sub_tree* sub_tree_left = create_sub_tree(&sub_tree_left);
    sub_tree* sub_tree_right = create_sub_tree(&sub_tree_right);
    (*bin_tree_in)->root->data    = 0;
    (*bin_tree_in)->root->left    = sub_tree_left->parent;
    (*bin_tree_in)->root->right   = sub_tree_right->parent;
    sub_tree_left->parent  = (*bin_tree_in)->root;
    sub_tree_right->parent = (*bin_tree_in)->root;
    (*bin_tree_in)->left_child    = sub_tree_left ;
    (*bin_tree_in)->right_child   = sub_tree_right;

    return *bin_tree_in;
}



// -.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.-.-.-.-

/*

//insert_node_into_queue
void enqueue ( queue** queue_in ,int node_data, int par,int dead_time ){
    queue_node *node= create_queue_node(node_data, par,dead_time);
    if( (*queue_in)->Front == NULL){
            //printf("entered\n");
        (*queue_in)->Front = node;
        (*queue_in)->Rear = node;
        (*queue_in)->Front->next = (*queue_in)->Rear ;

    }
    else {
        //printf("entered rear next\n");
        (*queue_in)->Rear->next = node;
    }
    (*queue_in)->Rear = node;
    (*queue_in)->counter++;

}


//extract_node_from_queue
int dequeue (queue** queue_in){
    int data_dequeued;
    queue_node *temp;
    if( (*queue_in)->Front == NULL){
        //printf("queue is empty\n");
        return 0;
    }

    else{
        data_dequeued= ((*queue_in)->Front->data);
        temp = (*queue_in)->Front;
        (*queue_in)->Front = (*queue_in)->Front->next;
        (*queue_in)->counter--;
        free(temp);
        return data_dequeued;
    }
}

*/

int main()
{
    bin_tree* new_tree = create_bin_tree(&new_tree);


    return 0;
}
