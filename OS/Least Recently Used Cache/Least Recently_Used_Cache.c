#include <stdio.h>
#include <stdlib.h>

// front == head
// rear  == end

typedef struct fifo queue;
typedef struct queue_node queue_node;

struct queue_node {
    unsigned long int data;
    unsigned long int key;
    struct queue_node *next;
};
struct fifo
{
    queue_node* Rear;
    queue_node* Front;
    int counter;
    int cache;
};
//creating queue node
queue_node* create_queue_node(unsigned long int data, unsigned long int key){
    queue_node *node = malloc( sizeof(queue_node));
    node->data = data;
    node->key = key;
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
void enqueue ( queue** queue_in ,unsigned long int node_data , unsigned long int key ){
    queue_node *node= create_queue_node(node_data, key);
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
unsigned long int** dequeue (queue** queue_in){
    unsigned long int  **data_dequeued= malloc(2 * sizeof(unsigned long int *));
    int i;
    for (i=0; i<2 ; i++){
        data_dequeued[i] = malloc(2 * sizeof( unsigned long int ));
    }

    queue_node *temp;
    if( (*queue_in)->Front == NULL){
        //printf("queue is empty\n");
        return 0;
    }
    else{
        data_dequeued[0][0] = ((*queue_in)->Front->data);
        data_dequeued[0][1] = ((*queue_in)->Front->key);
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
    unsigned int *arr_data = malloc(temp->counter * sizeof(unsigned long int));
    unsigned int *arr_key = malloc(temp->counter * sizeof(unsigned long int));

    int count = temp->counter;
    int i;

    unsigned long int  **data= malloc(2 * sizeof(unsigned long int *));

    for (i=0; i<2 ; i++){
        data[i] = malloc(2 * sizeof( unsigned long int ));
    }

    for (i=0;i<count;i++){
            data = dequeue(&temp);
            arr_data[i]= data[0][0];
            arr_key[i]= data [0][1];
            printf("%ld",data[0][0]);
            printf(" %ld",data[0][1]);
            if(i< count-1){printf(",");}
    }

    for (i=0;i<count;i++){
        data[0][0] = arr_data[i];
        data[0][1] = arr_key [i];
        enqueue(&temp, data[0][0] , data[0][1]);
    }
}



queue_node * search_in_queue(queue** queue_in, unsigned long int key ){

    queue *temp= *queue_in;
    queue_node *wanted_node;

    unsigned int *arr_data = malloc(temp->counter * sizeof(unsigned long int));
    unsigned int *arr_key  = malloc(temp->counter * sizeof(unsigned long int));

    int count = temp->counter;
    int i;
    int happened=0;
    unsigned long int  **data= malloc(2 * sizeof(unsigned long int *));

    for (i=0; i<2 ; i++){
        data[i] = malloc(2 * sizeof( unsigned long int ));
    }

    for (i=0;i<count;i++){
            data = dequeue(&temp);
            arr_data[i]= data[0][0];
            arr_key[i]= data [0][1];
            //printf("%ld",data[0][0]);
            //printf(" %ld",data[0][1]);
            //if(i< count-1){printf(",");}
    }

    for (i=0;i<count;i++){
        data[0][0] = arr_data[i];
        data[0][1] = arr_key [i];
        enqueue(&temp, data[0][0] , data[0][1]);
        if(data[0][1] == key ){
                wanted_node = (temp->Rear);
                happened = 1;
            }
    }
    if ( happened == 1 )
        return wanted_node;
    else
        return NULL;
}

void delete_node(queue** queue_in , unsigned long int data_new ,unsigned long int key ){
    queue *temp= *queue_in;

    unsigned int *arr_data = malloc(temp->counter * sizeof(unsigned long int));
    unsigned int *arr_key  = malloc(temp->counter * sizeof(unsigned long int));

    int count = temp->counter;
    int i;
    int happened=0;
    unsigned long int  **data= malloc(2 * sizeof(unsigned long int *));

    for (i=0; i<2 ; i++){
        data[i] = malloc(2 * sizeof( unsigned long int ));
    }

    for (i=0;i<count;i++){
            data = dequeue(&temp);
            arr_data[i]= data[0][0];
            arr_key[i]= data [0][1];
    }

    for (i=0;i<count;i++){
        data[0][0] = arr_data[i];
        data[0][1] = arr_key [i];
        //printf(" data [0][1] = %ld \n", data[0][1]);
        //printf(" key = %ld \n", key);
        if(data[0][1] == key ){
                happened = 1;
                //printf("found %ld \n",key);
            }
        else{
            enqueue(&temp, data[0][0] , data[0][1]);
            }
    }
    if(happened == 1){
            //printf("happened \n");
            enqueue(&temp, data_new , key);
    }

}

int main(){

    //int cache;

    // create new_queue from function
    queue* new_queue= create_queue(&new_queue);

    unsigned int number_of_operations;
    unsigned int cache;

    int operation;
    unsigned long int data = 0;
    unsigned long int key  = 0;

    unsigned long int  **value= malloc(2 * sizeof(unsigned long int *));
    int i;
    for (i=0; i<2 ; i++){
        value[i] = malloc(2 * sizeof( unsigned long int ));
    }

    queue_node *temp;

    scanf("%d",&number_of_operations);
    scanf("%d",&cache);

    new_queue->cache = cache;

    if(number_of_operations == 0 || number_of_operations >1000000){
        return 0;
    }
    int count1 = number_of_operations;
    while (count1 > 0){
            scanf("%d",&operation);
            switch (operation){
                case 1: // enqueue
                    {
                        if(new_queue->cache == 0){
                            scanf("%ld",&key);
                            scanf("%ld",&data);
                            printf ("Error\n");
                        }
                        else if(new_queue->cache > new_queue->counter){
                            scanf("%ld",&key);
                            scanf("%ld",&data);
                            temp = search_in_queue(&new_queue , key);

                            if(temp != NULL ){
                                delete_node (&new_queue, data ,key);
                                //printf("counter0 = %d\n",new_queue->counter);
                            }
                            else
                                enqueue(&new_queue,data,key);
                            temp = NULL;
                            }
                        else if (new_queue->cache <= new_queue->counter){
                            scanf("%ld",&key);
                            scanf("%ld",&data);
                            temp = search_in_queue(&new_queue , key);
                            if(temp != NULL ){
                                delete_node (&new_queue, data , key);
                                //printf("counter1 = %d\n",new_queue->counter);
                            }
                            else {
                               value = dequeue(&new_queue);
                               enqueue(&new_queue,data,key);
                              //printf("counter2 = %d\n",new_queue->counter);
                            }
                            temp = NULL;
                        }
                        break;
                    }
                case 2: // dequeue
                    {

                        if (new_queue->counter == 0){
                            scanf("%ld",&key);
                            printf ("Not Found\n");
                        }
                        else if (new_queue->counter >= 1) {
                            scanf("%ld",&key);
                            temp = search_in_queue(&new_queue , key);
                            if(temp != NULL ){
                                printf("%ld\n",temp->data);
                                delete_node (&new_queue, temp->data , key);
                            }
                            else
                                printf ("Not Found\n");

                        }
                        temp = NULL;

                        break;
                    }
/*
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
*/
                default:
                    {
                        printf ("Error\n");
                        break;
                    }
            }
            count1--;
    }

    return 0;
}
