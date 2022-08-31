#include <stdio.h>
#include <stdlib.h>

// front == head
// rear  == end

typedef struct fifo queue;
typedef struct queue_node queue_node;


struct queue_node {
    int data;
    int pariority;
    struct queue_node *next;
};
struct fifo
{
    queue_node* Rear;
    queue_node* Front;
    int counter;

};
//creating queue node
queue_node* create_queue_node(int data){
    queue_node *node = malloc( sizeof(queue_node));
    node->data = data;
    node->pariority = 99;
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
void enqueue ( queue** queue_in ,int node_data){
    queue_node *node= create_queue_node(node_data);
    if( (*queue_in)->Front == NULL){
            printf("entered\n");
        (*queue_in)->Front = node;
        (*queue_in)->Rear = node;
        (*queue_in)->Front->next = (*queue_in)->Rear ;

    }
    else {
        printf("entered rear next\n");
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
        printf("queue is empty\n");
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
//printing queue
void print_queue_data(queue** queue_in){
    queue *temp= *queue_in;
    int count = temp->counter;
    int i,data;
    for (i=0;i<count;i++){
            data =dequeue(&temp);
            printf("%d",data);
            if(i< count-1){printf(" ,");}
    }
    printf("\n");
}



int main(){
    // create new_queue from function
    int number;
    int i,j;
    i=0;
    scanf("%d",&number);

    queue*** new_queue = malloc(number * sizeof(queue*));
    for(i=0;i<number;i++){
        new_queue [i] = malloc(number * sizeof(queue));
    }
    for(i=0;i<number;i++){
            for(j=0;j<number;j++){
                new_queue [i][j] = create_queue(&new_queue[i][0]);
            }
    }

    int data=0;
    int par;
    int *counter1= malloc (number * sizeof(int));
    for(i=0;i<number;i++){
        counter1[i]=0;
    }
    int element_numb=0;
    while (data != 25){
            printf("enter data of the queue\n");
            scanf("%d",&data);
            printf("enter par of the queue\n");
            scanf("%d",&par);
            if(par>= number){
                par= par;
            }
            else{
                enqueue(&new_queue[par][counter1[par]] , data);
                counter1[par]++;
                element_numb++;
            }

    }

    int count = element_numb;

    if (count != 0){
        for(i=0 ; i< count ;i++){
                j=0;
                while ( (new_queue[i][j])->Front  != NULL  ){
                    data = dequeue(&new_queue[i][j]);
                    printf("queue [%d] [%d]  = %d \n",i,j,data);
                    j++;
                }
        }
    }
    return 0;
}
