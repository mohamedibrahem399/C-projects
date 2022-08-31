#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct bin_tree bin_tree;
typedef struct sub_tree sub_tree;
typedef struct tree_node tree_node;

// stack part
typedef struct lifo stack;
struct lifo{
    int value;
    tree_node* stack_tree_node;
    sub_tree*  stack_sub_tree;
    struct lifo *next;
};
stack *top;
void create (stack **top)
{ *top = NULL;  }
void push (stack **top, int element )
{
    stack *new;
    new = (stack *)malloc (sizeof(stack));
    if (new == NULL) {  return; }
    new->value = element;
    new->next = *top;
    *top = new;
}

void push_tree_node (stack **top ,tree_node** new_tree_node )
{
    stack *new;
    new = (stack *)malloc (sizeof(stack));
    if (new == NULL) {  return; }

    if(*new_tree_node == NULL ){return; }
    else
    {
        new->stack_tree_node = *new_tree_node;
        new->next = *top;
        *top = new;
    }
}
void push_sub_tree (stack **top ,sub_tree** new_sub_tree )
{
    stack *new;
    new = (stack *)malloc (sizeof(stack));
    if (new == NULL) {  return; }

    if(*new_sub_tree == NULL ){return; }
    else
    {
        new->stack_sub_tree = *new_sub_tree;
        new->next = *top;
        *top = new;
    }
}
unsigned long int pop (stack **top)
{
   unsigned int t;
   stack *p;
   if (*top == NULL) {  return 0;  }
   else
   {
      t = (*top)->value;
      p = *top;
      *top = (*top)->next;
      free (p);
   }
   return t;
}

tree_node* pop_tree_node (stack **top)
{
   tree_node *t;
   stack *p;
   if (*top == NULL) {  return 0;  }
   else
   {
      t = (*top)->stack_tree_node;
      p = *top;
      *top = (*top)->next;
      free (p);
   }
   return t;
}
// Tree part
struct sub_tree {

    struct tree_node *parent;
    struct tree_node *left_child , *right_child ;

};

struct tree_node {

    char data;

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
tree_node* create_tree_node(char data){
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
void link_sub_tree(sub_tree** sub_tree_in , tree_node** tree_node1 , tree_node** tree_node2 , tree_node** tree_node3 ){

    (*sub_tree_in)->parent       = *tree_node1;
    (*sub_tree_in)->left_child   = *tree_node2;
    (*sub_tree_in)->right_child  = *tree_node3;

}
void link_sub_tree_with_node(sub_tree** sub_tree_in , tree_node** tree_node1 ){

    (*sub_tree_in)->parent       = *tree_node1;
    (*sub_tree_in)->left_child   = (*tree_node1)->left;
    (*sub_tree_in)->right_child  = (*tree_node1)->right;

}
void link_tree_nodes(tree_node** tree_node1 , tree_node** tree_node2 , tree_node** tree_node3 ){

    (*tree_node1)->left  = *tree_node2;
    (*tree_node1)->right = *tree_node3;

}

int main()
{
    int i;
    bin_tree* new_tree = create_bin_tree(&new_tree);

    tree_node *node1, *node2;

    tree_node *node3;
    //*node3 = malloc( 10  * sizeof(tree_node*) );

    //sub_tree *new_sub_tree;

    stack *A,*B,*C;
    create(&A);
    create(&B);
    create(&C);

    char s[10000];

    scanf("%s",s);
    //printf("%s\n",s);

    int counter = strlen(s);
    int number_counter=0;

    int in=0;

    for (i =0; i< counter; i++)
    {
        //printf("%d\n",s[i]);
        if((int) s[i] >= 48 && (int) s[i] <= 57){
            int value = (int) s[i] -48;
            printf("this is int and = %d \n",value);
            push(&A, value);
            number_counter++;
            in++;
        }
        else if ((int) s[i] >= 37 && (int) s[i] <= 47)
        {
            switch ((int) s[i]){
                    case 42: {//*
                        printf("number_counter = %d , in =%d \n",number_counter,in);
                            if (number_counter == 2){
                                signed int value2=pop(&A) +48;
                                signed int value1=pop(&A) +48;
                                node1 = create_tree_node( (char) value1 );
                                node2 = create_tree_node( (char) value2 );
                                node3 = create_tree_node( '*' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A , &node3 );
                                number_counter=0;
                                in--;
                            }
                            else if (number_counter == 1 && in > 0){
                                signed int  value2 = pop(&A) + 48;
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node2 = create_tree_node( (char) value2 );
                                node3 = create_tree_node( '*' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }
                            else if (number_counter == 0 && in > 0){
                                node2 = malloc(sizeof(tree_node));
                                node2 = pop_tree_node(&A);
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node3 = create_tree_node( '*' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }

                            break;}

                    case 43:{ // +
                        printf("number_counter = %d , in =%d \n",number_counter,in);
                            if (number_counter == 2){
                                signed int value2=pop(&A) +48;
                                signed int value1=pop(&A) +48;
                                node1 = create_tree_node( (char) value1 );
                                node2 = create_tree_node( (char) value2 );
                                node3 = create_tree_node( '+' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A , &node3 );
                                number_counter=0;
                                in--;
                            }
                            else if (number_counter == 1 && in > 0){
                                signed int  value2 = pop(&A) + 48;
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node2 = create_tree_node( (char) value2 );
                                node3 = create_tree_node( '+' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }
                            else if (number_counter == 0 && in > 0){
                                node2 = malloc(sizeof(tree_node));
                                node2 = pop_tree_node(&A);
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node3 = create_tree_node( '+' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }
                            break;}
                    case 45: {// -
                        printf("number_counter = %d , in =%d \n",number_counter,in);
                            if (number_counter == 2){
                                signed int value2=pop(&A) +48;
                                signed int value1=pop(&A) +48;
                                node1 = create_tree_node( (char) value1 );
                                node2 = create_tree_node( (char) value2 );
                                node3 = create_tree_node( '-' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A , &node3 );
                                number_counter=0;
                                in--;
                            }
                            else if (number_counter == 1 && in > 0){
                                signed int  value2 = pop(&A) + 48;
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node2 = create_tree_node( (char) value2 );
                                node3 = create_tree_node( '-' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }
                            else if (number_counter == 0 && in > 0){
                                node2 = malloc(sizeof(tree_node));
                                node2 = pop_tree_node(&A);
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node3 = create_tree_node( '-' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }

                            break;}
                    case 47:{ // /
                        printf("number_counter = %d , in =%d \n",number_counter,in);
                            if (number_counter == 2){
                                signed int value2=pop(&A) +48;
                                signed int value1=pop(&A) +48;
                                if(value2 == 48 )
                                    {
                                        printf("Not Valid\n");
                                        return 0;
                                    }
                                else{
                                    node1 = create_tree_node( (char) value1 );
                                    node2 = create_tree_node( (char) value2 );
                                    node3 = create_tree_node( '/' );
                                    link_tree_nodes(&node3,&node1,&node2);
                                    push_tree_node(&A , &node3 );
                                    number_counter=0;
                                    in--;
                                    }
                            }
                            else if (number_counter == 1 && in > 0){
                                signed int  value2 = pop(&A) + 48;
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node2 = create_tree_node( (char) value2 );
                                node3 = create_tree_node( '/' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }
                            else if (number_counter == 0 && in > 0){
                                node2 = malloc(sizeof(tree_node));
                                node2 = pop_tree_node(&A);
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node3 = create_tree_node( '/' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }
                            break;}

                     case 37:{ // %
                        printf("number_counter = %d , in =%d \n",number_counter,in);
                            if (number_counter == 2){
                                signed int value2=pop(&A) +48;
                                signed int value1=pop(&A) +48;
                                if(value2 == 48 )
                                    {
                                        printf("Not Valid\n");
                                        return 0;
                                    }
                                else{
                                    node1 = create_tree_node( (char) value1 );
                                    node2 = create_tree_node( (char) value2 );
                                    node3 = create_tree_node( '%' );
                                    link_tree_nodes(&node3,&node1,&node2);
                                    push_tree_node(&A , &node3 );
                                    number_counter=0;
                                    in--;
                                    }
                            }
                            else if (number_counter == 1 && in > 0){
                                signed int  value2 = pop(&A) + 48;
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node2 = create_tree_node( (char) value2 );
                                node3 = create_tree_node( '%' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }
                            else if (number_counter == 0 && in > 0){
                                node2 = malloc(sizeof(tree_node));
                                node2 = pop_tree_node(&A);
                                node1 = malloc(sizeof(tree_node));
                                node1 = pop_tree_node(&A);
                                node3 = create_tree_node( '%' );
                                link_tree_nodes(&node3,&node1,&node2);
                                push_tree_node(&A ,&node3 );
                                number_counter=0;
                                in--;
                            }
                            break;}
                    default:{
                            printf("Not Valid\n");
                            return 0;
                            break;}
                }
        }
    }
    printf("in= %d\n",in);
if (in== 1){
    if(A->stack_tree_node != NULL){
        node3 = pop_tree_node(&A);
    }

    while (1){
        printf("%c\n",node3->data);

        node1= node3->right;
        while(node1 != NULL ){
            printf("%c\n",node1->data);
            if(node1->right != NULL)
                printf("%c\n",node1->right->data);
            if(node1->right == NULL && node1->left == NULL){
                break;
            }
            node1 = node1->left;
            /*if(node1->right!= NULL){
                node2= node1->right;
                printf("%c\n",node2->data);
            }*/
        }
        node2 = node3->left;
        while(node2->left!=NULL){
            printf("%c\n",node2->data);
            if(node2->left != NULL)
                printf("%c\n",node2->left->data);
            if(node2->right != NULL)
                printf("%c\n",node2->right->data);
            node2 = node2->left;
        }
        if(node1->right ==NULL && node2->left==NULL )
            break;
        }
}

    return 0;
}
