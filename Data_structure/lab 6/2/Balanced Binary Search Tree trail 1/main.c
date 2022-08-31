#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// front == head
// rear  == end

//***********************************************************

typedef struct tree_node tree_node;

//***********************************************************


// Tree part

struct tree_node {
    signed int data;
    struct tree_node *left;
    struct tree_node *right;
};

//creating tree_node
tree_node* create_tree_node(signed int data){
    tree_node *node = malloc( sizeof(tree_node));
    node->data  = data   ;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

//***********************************************************
int counter=0;

tree_node* sorted_array_to_BST(int arr[], int start, int end)
{
	if (start > end)
    {
       return NULL;
    }
    else
    {
        int mid = (start + end)/2;
        tree_node *root = create_tree_node(arr[mid]);
        root->left = sorted_array_to_BST(arr, start, mid-1);
        root->right = sorted_array_to_BST(arr, mid+1, end);
        return root;
	}

}

void preorder(tree_node* node, int arr[])
{
	if (node == NULL)
	{
        return;
    }
    else
    {
        //printf("%d ", node->data);
        arr[counter]= node->data;
        counter++;
        preorder(node->left  , arr);
        preorder(node->right , arr);
    }
}


//***********************************************************


int main()
{
    //enter number of elements in the tree
    int elements_number = 0;
    //printf("enter elements number :- \n");
    scanf("%d",&elements_number);

    int *arr = malloc(elements_number * sizeof(int) );
    int i;
    signed int data=0;
    for(i=0; i< elements_number; i++){
        scanf("%d",&data);
        arr[i]= data;
    }
    int *arr2 = malloc(elements_number * sizeof(int) );
    tree_node *root = sorted_array_to_BST(arr, 0, elements_number-1 );
    preorder(root, arr2);

    for(i=0; i<counter ; i++){
        if(i<counter-1){
            printf("%d,",arr2[i]);
        }
        else {
            printf("%d",arr2[i]);
        }
    }
    //printf("counter = %d \n",counter);
    return 0;
}
