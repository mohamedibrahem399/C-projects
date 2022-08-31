#include <stdio.h>
#include <stdlib.h>
/*
int bipartiteDfs(int node, int *adj[], int color[],int n) {
    int it;
    for(it=0; it<n ;it++){
        if(adj[node][it]==1){
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(!bipartiteDfs(it, adj, color,n)) {
                    return 0;
                }
            } else if(color[it] == color[node]) return 0;
        }
    }
    return 1;
}
int checkBipartite(int *adj[], int n) {
    int *color = malloc(n*sizeof(int));
    int i=0;
    for(i=0;i<n;i++){
        color[i]=-1;
    }

    //memset(color, -1, sizeof color);

    for(i = 0;i<n;i++){
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color,n)) {
                return 0;
            }
        }
    }
    return 1;
}
*/


// stack part
typedef struct lifo stack;
struct lifo{
    signed int value;
    struct lifo *next;
};
stack *top;
void create (stack **top)
{ *top = NULL; }
void push (stack **top, signed int element)
{
    stack *new;
    new = (stack *)malloc (sizeof(stack));
    if (new == NULL) {  return; }
    new->value = element;
    new->next = *top;
    *top = new;
}
signed int pop (stack **top)
{
   signed int t;
   stack *p;
   if (*top == NULL) {  return 0;  }
   else{
      t = (*top)->value;
      p = *top;
      *top = (*top)->next;
      free (p);
   }
   return t;
}

//.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-

struct Graph_node {
    int data;
    int *connected;
};

int search_for_index(int *arr, int arr_number ,int n){
    int i;
    for(i=0; i<arr_number ; i++){
        if(n == arr[i]){
            return i;
        }
    }
    return arr_number *10;

}




int each_element_and_neibours_check(int *Graph[], int element_num, int arr_colour[],int n_vertices)
{
    arr_colour[element_num] = 1;

    stack *A;
    create(&A);
    push(&A,element_num);

    while (A!=NULL){
        int i = pop(&A);
        int j;

        if (Graph[i][i] == 1)
            return 0;

        for (j = 0; j < n_vertices; ++j) {
            if (Graph[i][j] && arr_colour[j] == -1) {
                arr_colour[j] = 1 - arr_colour[i];
                push(&A,j);
            }

            else if (Graph[i][j] && arr_colour[j] == arr_colour[i])
               {
                   return 0;
               }
        }
    }

    return 1;
}

int check_Bipartite(int *Graph[],int n_vertices)
{
    int i;
    int *arr_colour = malloc(n_vertices * sizeof(int) );
    for (i = 0; i < n_vertices; ++i)
        {
            arr_colour[i] = -1;
        }

    for (i = 0; i < n_vertices; i++)
       {
        if (arr_colour[i] == -1)
          {
            if (each_element_and_neibours_check(Graph, i, arr_colour,n_vertices) == 0)
                {
                    return 0;
                }
          }
       }
    return 1;
}





















int main()
{
    /*
    int graph_elements[8]={1,2,3,4,5,6,7,8};

    int graph[8][8]=    { 1  {0,1,1,0,0,0,1,0},
                          2  {1,0,0,1,0,0,0,1},
                          3  {1,0,0,1,1,0,0,0},
                          7  {1,0,0,0,1,0,0,1},
                          4  {0,1,1,0,0,1,0,0},
                          8  {0,1,0,0,0,1,1,0}};
                          5  {0,0,1,0,0,1,1,0},
                          6  {0,0,0,1,1,0,0,1},
    */
/*
    stack *A,*B;
    create(&A);
    create(&B);
*/
    int i,j;
    int n_vertices , n_edges;
    scanf("%d",&n_vertices);
    scanf("%d",&n_edges);
    //making 2d array to store graph elements connections
    int **graph = malloc(n_vertices * sizeof(int*));
    for(i=0; i< n_vertices ; i++){
        graph[i] = malloc(n_vertices * sizeof(int));
    }
    //making graph elements connections all with 0
    for(i=0;i<n_vertices;i++){
        for(j=0;j<n_vertices;j++){
            graph[i][j]=0;
        }
    }
    int *graph_elements =  malloc(n_vertices * sizeof(int));
    int counter=0;
    int elements_count=0;
    int data_from , data_into ;
    while (counter< n_edges){
        scanf("%d",&data_from);
        scanf("%d",&data_into);
        /*
        struct Graph_node *new_node = malloc(sizeof(struct Graph_node));
        new_node->data = data_from;
        new_node->connected = malloc(n_vertices * sizeof(int));
        */
        if(counter == 0){
            if(data_from == data_into){
                graph_elements[elements_count] = data_from;
                graph[elements_count][elements_count]=1;
                elements_count++;
            }
            else if (data_from != data_into){
                graph_elements[elements_count] = data_from;
                elements_count++;
                graph_elements[elements_count] = data_into;
                graph[elements_count-1][elements_count] =1;
                graph[elements_count][elements_count-1] =1;
                elements_count++;
            }
        }
        else if(counter!= 0){
                //if(data_from != data_into)

                int temp_from = search_for_index(graph_elements,elements_count,data_from);
                int temp_into = search_for_index(graph_elements,elements_count,data_into);

                if(temp_into == 10 *elements_count){

                    graph_elements[elements_count] = data_into;
                    elements_count++;
                    if(temp_from == 10 *elements_count){
                        graph_elements[elements_count] = data_from;
                        graph[elements_count][elements_count-1]=1;
                        graph[elements_count-1][elements_count]=1;
                        elements_count++;
                    }
                    else if(temp_from != 10*elements_count){
                            graph[temp_from][elements_count-1]=1;
                            graph[elements_count-1][temp_from]=1;
                    }
                    //elements_count++;

                }

                else if(temp_into != 10*elements_count){

                    if(temp_from == 10 *elements_count){
                        graph_elements[elements_count] = data_from;
                        graph[elements_count][temp_into]=1;
                        graph[temp_into][elements_count]=1;
                        elements_count++;
                    }
                    else if(temp_from != 10*elements_count){
                            graph[temp_from][temp_into]=1;
                            graph[temp_into][temp_from]=1;
                    }

                }

        }
        counter++;
    }
/*
    for(i=0;i<n_vertices;i++){printf("%d ",graph_elements[i]);}
    printf("\n");

    for(i=0;i<n_vertices;i++){
        for(j=0;j<n_vertices;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
*/
/*
    int *set1 = malloc(n_vertices* sizeof(int));
    int *set2 = malloc(n_vertices* sizeof(int));
    int count_set1=0 , count_set2 = 0;
    int temp_count=0;
    while (temp_count < n_vertices){

        if(temp_count == 0 ){
            for(i=0 ; i < n_vertices ; i++){
                set1[count_set1] = graph_elements[temp_count];
                count_set1++;
                if( graph[temp_count][i] == 1 && i != temp_count ){
                        set2[count_set2] = graph_elements[i];
                }
            }
        }

        else if(temp_count>0){

            int temp1= search_for_index(set1,count_set1,graph_elements[temp_count]);
            int temp2= search_for_index(set2,count_set2,graph_elements[temp_count]);

            if(temp1 == 10 * count_set1){
                if(temp2 == 10 * count_set2){
                    set1[count_set1]= graph_elements[temp_count];

                    for(i=0;i<n_vertices;i++){
                        set1[count_set1]= graph_elements[temp_count];
                        count_set1++;
                        if( graph[temp_count][i] == 1){
                                int temp3= search_for_index(set2,count_set2,graph_elements[i]);
                                if(temp3 == 10*count_set2){
                                set2[count_set2]= graph_elements[i];
                                }
                                else if(temp3 != 10 *count_set2);
                        }
                    }


                }
            }
            else if(temp1!= count_set1 *10 || temp2!= count_set2 *10){
                printf("known before\n");
            }
        }

        temp_count++;
    }

    for(i=0;i<count_set1;i++){
        printf("%d ",set1[i]);
    }
    printf("\n");

    for(i=0;i<count_set2;i++){
        printf("%d ",set2[i]);
    }
    printf("\n");
*/

    if ( check_Bipartite(graph,n_vertices) == 1){
        printf("Yes\n");
    }
    else printf("No\n");

    return 0;
}
