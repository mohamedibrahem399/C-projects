#include <stdio.h>
#include <stdlib.h>

// front == head
// rear  == end

typedef struct fifo queue;
typedef struct queue_node queue_node;


struct queue_node {
    int data;
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
    queue* new_queue= create_queue(&new_queue);

    // create new_queue manually
    //queue* new_queue= malloc(sizeof(queue));
    //new_queue->Front= NULL;
    //new_queue->Rear = NULL;
    //new_queue->counter=0;
    int data=0;
    int i;
    while (data != 25){
            printf("enter data of the queue\n");
            scanf("%d",&data);
            enqueue(&new_queue , data);
    }
    printf("counter = %d \n",new_queue->counter);


    int count = new_queue->counter;

    if (new_queue->counter != 0){
        for(i=0 ; i< count ;i++){
                data =dequeue(&new_queue);
                printf("queue [%d] = %d \n",i,data);
        }
    }
    printf("counter after dequeuing all elements = %d \n",new_queue->counter);
    return 0;
}
