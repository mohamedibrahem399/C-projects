#include <stdio.h>
#include <stdlib.h>

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




    return 0;
}
