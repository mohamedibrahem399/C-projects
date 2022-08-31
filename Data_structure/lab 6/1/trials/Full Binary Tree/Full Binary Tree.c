#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// front == head
// rear  == end

//***********************************************************

typedef struct fifo queue;
typedef struct queue_node queue_node;

//***********************************************************

typedef struct bin_tree bin_tree;
typedef struct tree_node tree_node;

//***********************************************************


// Tree part

struct tree_node {

    signed int data;

    struct tree_node *left;
    struct tree_node *right;
};

struct bin_tree
{
    // root
    //  2 children type subtree
    struct tree_node *root;
    struct tree_node *left_child ;
    struct tree_node *right_child;
};
//creating tree_node
tree_node* create_tree_node(signed int data){
    tree_node *node = malloc( sizeof(tree_node));
    node->data  = data   ;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

//creating bin_tree
void create_bin_tree(bin_tree** bin_tree_in){
    *bin_tree_in = malloc(sizeof(bin_tree_in));
    (*bin_tree_in)->root  = malloc( sizeof(tree_node));
    tree_node* tree_node_left     = create_tree_node(-1);
    tree_node* tree_node_right    = create_tree_node(-1);
    (*bin_tree_in)->left_child    = tree_node_left ;
    (*bin_tree_in)->right_child   = tree_node_right;
    (*bin_tree_in)->root->data    = -1;
    (*bin_tree_in)->root->left    = (*bin_tree_in)->left_child ;
    (*bin_tree_in)->root->right   = (*bin_tree_in)->right_child;
}

void link_tree_nodes(tree_node** tree_node1 , tree_node** tree_node2 , tree_node** tree_node3 ){

    (*tree_node1)->left  = *tree_node2;
    (*tree_node1)->right = *tree_node3;

}

//***********************************************************

//Queue part

struct queue_node {
    tree_node *tn;
    struct queue_node *next;
};
struct fifo
{
    queue_node* Rear;
    queue_node* Front;
    int counter;

};
//creating queue node
queue_node* create_queue_node(tree_node *tn){
    queue_node *node = malloc( sizeof(queue_node));
    node->tn = tn;
    node->next = NULL;
    return node;
}
//creating queue
queue* create_queue(queue** queue_in){
     *queue_in = malloc(sizeof(queue));
    (*queue_in)->Front   = NULL;
    (*queue_in)->Rear    = NULL;
    (*queue_in)->counter = 0   ;

    return *queue_in;
}
//insert_node_into_queue
void enqueue ( queue** queue_in ,tree_node *tn){
    queue_node *node = create_queue_node(tn);
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
tree_node* dequeue (queue** queue_in){
    tree_node *node_dequeued = create_tree_node(-1);
    queue_node *temp;
    if( (*queue_in)->Front == NULL){
        printf("queue is empty\n");
        return NULL;
    }

    else{
        node_dequeued= ((*queue_in)->Front->tn);
        temp = (*queue_in)->Front;
        (*queue_in)->Front = (*queue_in)->Front->next;
        (*queue_in)->counter--;
        free(temp);
        return node_dequeued;
    }
}

//***********************************************************


int main()
{
    //create binary tree
    bin_tree* new_tree ;
    create_bin_tree(&new_tree);

    // making some nodes to help us later
    tree_node *node1, *node2;
    tree_node *node3, *node4;

    // create new_queue from function
    queue* new_queue= create_queue(&new_queue);

    //enter number of elements in the tree
    int elements_number = 0;
    printf("enter elements number :- \n");
    scanf("%d",&elements_number);

    // enter root data
    printf("enter first element :-\n");
    signed int data=0;
    scanf("%d",&data);
    if(data != -1){
        new_tree->root->data = data;
        enqueue(&new_queue , new_tree->root );
    }
    else if (data == -1){
        printf("YES\n");
        return 0;
    }

    int counter=2;
    int in_left , in_right;
    int level=1;

    // Enter tree elements:-
    while ( counter < elements_number +1 ) {

        if(counter == 2){//root left element
            printf("enter left element :-\n");
            scanf("%d",&data);
            if (data != -1){
                node1 = dequeue (&new_queue );
                node2 = node1->left;
                node2->data = data;
                enqueue(&new_queue , node2 );
                in_left = 2;
                level = 1;
                }
            else if ( data == -1){
                node1 = dequeue (&new_queue );
                node1->left = NULL;
                free(node1->left) ;
                node2= node1->left;
                in_left = 2;
                level = 1;
                //enqueue(&new_queue , node2 );
            }
        }

        else if(counter == 3){//root right element
            printf("enter right element :-\n");
            scanf("%d",&data);
            printf("data = %d\n",data);
             if (data != -1){
                printf("entered1\n");
                node3 = node1->right;
                node3->data = data;
                enqueue(&new_queue , node3 );
                in_right = 3;
                level = 1;
                }
            else if ( data == -1){
                printf("entered2\n");
                node1->right =  NULL;
                free( node1->right );
                node3 = node1->right;
                in_right = 3;
                level = 1;
                //enqueue(&new_queue , node3 );
                }
        }

        else if(counter > 3 && counter >= in_left * 2 && counter < in_right * 2 ){// placing nodes in left branch
            printf("entered left side\n");
            if(node2 != NULL){
                if(counter == in_left * 2 ){
                    printf("enter next left element :-\n");
                    scanf("%d",&data);
                    if(data != -1){
                        node4 = dequeue(&new_queue );
                        node4->left = create_tree_node(data);
                        enqueue(&new_queue , node4->left );
                    }
                    if(data == -1){
                            node4 = dequeue(&new_queue );
                            node4->left = NULL;
                            free(node4->left);
                    }
                }
                else if( counter == (in_left *2 +1)  ){
                    printf("enter next right element :-\n");
                    scanf("%d",&data);
                    if (data != -1){
                    node4->right = create_tree_node(data);
                    enqueue(&new_queue , node4->right );
                    }
                    else if (data == -1){
                        node4->right = NULL;
                        free(node4->right);
                    }
                    if(in_left +1 == in_right ){
                        level ++;
                        in_left = (int) pow(2,level) * 2;
                        printf("level = %d and in_left = %d \n",level,in_left);
                        }
                    else if (in_left +1 < in_right){
                        in_left = in_left + 1 ;
                        printf("level = %d and in_left = %d \n",level,in_left);
                    }
                }
            }
            else if(node2 == NULL){
                printf("entered3\n");
                level ++;
                //printf("%i\n", (int) pow(2,level) );
                in_left = (int) pow(2,level) * 2;
                counter = in_right *2 - 1;
                printf("level = %d and in_left = %d , counter = %d \n",level,in_left,counter);
                //return 0;
            }
        }

        else if(counter > 3 && counter >= in_right * 2 && counter < in_left * 2 ){// placing nodes in right branch
            printf("entered right side \n");
            if (node3 != NULL){
                    if(counter == in_right * 2 ){
                        node4 = dequeue(&new_queue);
                        printf("enter next right element :-\n");
                        scanf("%d",&data);
                        if(data != -1){
                                node4->left = create_tree_node(data);
                                enqueue(&new_queue , node4->left );
                        }
                        else if (data == -1){
                            node4->left = NULL;
                            free(node4->left);
                        }
                    }

                    else if( counter == (in_right *2 +1)  ){
                        scanf("%d",&data);
                        if (data != -1){
                            node4->right = create_tree_node(data);
                            enqueue(&new_queue , node4->right );
                        }
                        else if (data == -1){
                            node4->right = NULL;
                            free(node4->right);
                        }

                        if(in_right +1 == in_left ){
                            in_right = (int) pow(2,level) * 3 ;
                            printf("level = %d and in_right = %d \n",level,in_right);
                        }
                        else if ( in_right +1 < in_left ){
                            in_right = in_right + 1 ;
                            printf("level = %d and in_right = %d \n",level,in_right);
                        }
                    }
                }
            else if (node3 == NULL){
                printf("entered4\n");
                counter = in_left -1;
                in_right = (int) pow(2,level) * 3 ;
                printf("level = %d and in_right = %d , counter = %d  \n",level,in_right,counter);
            }
        }


        else{ // other
            counter = counter;
        }
    counter++;
    printf("counter = %d , level = %d , data = %d \n",counter,level,data);
    }


printf("\n");
printf("tree elements:-\n");
printf("\n");
int counter2 = 1;
int counter_test =0;
queue* new_queue2 = create_queue(&new_queue2);

enqueue(&new_queue2 , new_tree->root );

// print tree elements
while(counter2 < elements_number + 1) {

        if(counter2 == 1){
            node1 = dequeue (&new_queue2 );
            printf("root_data = %d \n",node1->data);
            counter_test++;
        }
        else if(counter2 == 2){
            node2 = node1->left;
            if(node2 != NULL){
                enqueue(&new_queue2 , node2 );
                printf("left_data = %d \n",node2->data);
                in_left = 2;
                level = 1;
                counter_test++;
            }
            else if (node2 == NULL){
                level =1;
                in_left=2;
            }
        }
        else if(counter2 == 3){
            node3 = node1->right;
             if(node3 != NULL){
                enqueue(&new_queue2 , node3 );
                printf("right_data = %d \n",node3->data);
                in_right = 3;
                level = 1;
                counter_test++;
             }
             else if (node3 == NULL){
                in_right = 3;
                level = 1;
             }
        }
        else if(counter2 > 3 && counter2 >= in_left * 2 && counter2 < in_right * 2 ){
            if (node2 != NULL){
                    if(counter2 == in_left * 2 ){
                        node4 = dequeue(&new_queue2);
                        if(node4->left != NULL){
                                printf("data number %d is = %d \n",counter2 ,node4->left->data);
                                enqueue(&new_queue2 , node4->left );
                                counter_test++;
                        }
                        else if(node4->left == NULL){
                                counter2 = counter2;
                        }
                    }
                    else if( counter2 == (in_left *2 +1)  ){
                        if(node4->right != NULL){
                                printf("data number %d is = %d \n",counter2 ,node4->right->data);
                                enqueue(&new_queue2 , node4->right );
                                counter_test++;
                        }
                        else if (node4->right == NULL){
                                counter2 = counter2;
                        }

                        if(in_left +1 == in_right ){
                            level ++;
                            in_left = (int) pow(2,level) * 2;
                        }
                        else if (in_left +1 < in_right){
                            in_left = in_left + 1 ;
                        }
                    }
                }
            else if (node2 == NULL){
                    printf("entered3\n");
                    level ++;
                    in_left = (int) pow(2,level) * 2;
                    counter2 = in_right *2 - 1;
                    printf("level = %d and in_left = %d , counter = %d \n",level,in_left,counter);
                }
        }

        else if(counter2 > 3 && counter2 >= in_right * 2 && counter2 < in_left * 2 ){

            if (node3 != NULL){
                    if(counter2 == in_right * 2 ){
                        node4 = dequeue(&new_queue2);
                        if(node4->left != NULL){
                                printf("data number %d is = %d \n",counter2 ,node4->left->data);
                                counter_test++;
                                enqueue(&new_queue2 , node4->left );
                        }
                        else if (node4->left == NULL){
                                counter2 = counter2;
                        }
                    }

                    else if( counter2 == (in_right *2 +1)  ){
                        if(node4->right != NULL){
                                printf("data number %d is = %d \n",counter2 ,node4->right->data);
                                enqueue(&new_queue2 , node4->right );
                                counter_test++;
                        }
                        else if (node4->right == NULL){
                                counter2 = counter2;
                        }
                        if(in_right +1 == in_left ){
                            in_right = (int) pow(2,level) * 3 ;
                        }
                        else if ( in_right +1 < in_left ){
                            in_right = in_right + 1 ;
                        }
                    }
            }
            else if(node3 == NULL){
                printf("entered4\n");
                counter = in_left -1;
                in_right = (int) pow(2,level) * 3 ;
                printf("level = %d and in_right = %d , counter = %d  \n",level,in_right,counter);
            }
        }

    else{
            counter2 = counter2;
        }
      counter2++;
    }
    printf("counter_test = %d\n",counter_test);

    if(counter_test +1 == counter2 ){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}
