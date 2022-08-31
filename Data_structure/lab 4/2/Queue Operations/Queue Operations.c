#include <stdio.h>
#include <stdlib.h>

// front == head
// rear  == end

typedef struct fifo queue;
typedef struct queue_node queue_node;

struct queue_node {
    unsigned long int data;
    struct queue_node *next;
};
struct fifo
{
    queue_node* Rear;
    queue_node* Front;
    int counter;
};
//creating queue node
queue_node* create_queue_node(unsigned long int data){
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
void enqueue ( queue** queue_in ,unsigned long int node_data){
    queue_node *node= create_queue_node(node_data);
    if( (*queue_in)->Front == NULL){
        (*queue_in)->Front = node;
        (*queue_in)->Rear = node;
        (*queue_in)->Front->next = (*queue_in)->Rear ;

    }
    else {
        (*queue_in)->Rear->next = node;
    }
    (*queue_in)->Rear = node;
    (*queue_in)->counter++;
}
//extract_node_from_queue
unsigned long int dequeue (queue** queue_in){
    unsigned long int data_dequeued;
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
//print hall queue
void print_queue_data(queue** queue_in){
    queue *temp= *queue_in;
    unsigned int *arr = malloc(temp->counter * sizeof(unsigned long int));
    int count = temp->counter;
    int i;
    unsigned long int data;
    for (i=0;i<count;i++){
            data =dequeue(&temp);
            arr[i]=data;
            printf("%ld",data);
            if(i< count-1){printf(",");}
    }

    for (i=0;i<count;i++){
        data = arr[i];
        enqueue(&temp,data);
    }
}


int main(){
    // create new_queue from function
    queue* new_queue= create_queue(&new_queue);
    unsigned int number_of_operations;
    int operation;
    unsigned long int data=0;
    int value;
    //int i;
    scanf("%d",&number_of_operations);
    if(number_of_operations == 0 || number_of_operations >1000000){
        return 0;
    }
    int count1=number_of_operations;
    while (count1 > 0){
            scanf("%d",&operation);
            switch (operation){
                case 1: // enqueue
                    {
                        scanf("%ld",&data);
                        enqueue(&new_queue,data);
                        break;
                    }
                case 2: // dequeue
                    {
                        if (new_queue->counter == 0){
                            value = value;
                        }
                        else{
                            value =dequeue(&new_queue);
                        }

                        break;
                    }
                case 3: // print all queue data
                    {
                        if(new_queue->counter==0){
                            printf("Empty\n");
                        }
                        else{
                            print_queue_data(&new_queue);
                            printf("\n");
                        }
                        break;
                    }
                default:
                    {
                        print_queue_data(&new_queue);
                        break;
                    }



            }
            count1--;
    }

    return 0;
}
