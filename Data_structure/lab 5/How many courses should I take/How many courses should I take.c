#include <stdio.h>
#include <stdlib.h>

// front == head
// rear  == end

typedef struct fifo queue;
typedef struct queue_node queue_node;

struct queue_node {
    int data;
    int pariority;
    int dead_time;
    struct queue_node *next;
};
struct fifo
{
    queue_node* Rear;
    queue_node* Front;
    int counter;

};
//creating queue node
queue_node* create_queue_node(int data, int par, int dead_time){
    queue_node *node = malloc( sizeof(queue_node));
    node->data = data;
    node->pariority = par;
    node->dead_time = dead_time;
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

int main(){
    // create new_queue from function
    int number;
    int dead_time;
    int i;
    i=0;
    //printf("enter courses number please\n");
    scanf("%d",&number);

    queue*** new_queue = malloc(number * sizeof(queue*));
    for(i=0;i<number;i++){
        new_queue [i] = malloc(number * sizeof(queue));
    }
    for(i=0;i<number;i++){
            new_queue [i][0] = create_queue(&new_queue[i][0]);
    }

    int data=0;
    int par;

    int *counter1= malloc (number * sizeof(int));
    for(i=0;i<number;i++){
        counter1[i]=0;
    }

    int element_numb = 0;
    int counter=0;

    while (element_numb < number){
            //printf("enter data of the queue and it's dead_time\n");
            scanf("%d",&data);
            scanf("%d",&dead_time);

            if(element_numb == 0){
                par=0;
                enqueue(&new_queue[par][0] , data , par ,dead_time);
                element_numb++;
            }
            else if(element_numb > 0){
                counter = element_numb;//1
                //printf("counter = %d\n",counter);
                while (counter > 0){
                        //printf("entered while loop\n");
                    for(i=element_numb-1 ;i>=0 ;i--){//in 10 entered 15
                        //printf("entered for loop and i= %d\n",i);
                        //printf("data= %d and (new_queue[%d][0])->Front->data = %d \n",data,i,(new_queue[i][0])->Front->data);
                        if (data >= (new_queue[i][0])->Front->data){
                             enqueue(&new_queue[i+1][0] , data , i+1, dead_time);
                             //printf("entered new value > last value\n");
                             //printf("new_queue[%d][0] = %d \n",i+1,(new_queue[i+1][0])->Front->data);
                             counter =0;
                             break;
                        }
                        else if (data < (new_queue[i][0])->Front->data){
                              enqueue(&new_queue[i+1][0] , (new_queue[i][0])->Front->data , i+1 ,(new_queue[i][0])->Front->dead_time );
                             (new_queue[i][0])->Front->data = data;
                             (new_queue[i][0])->Front->dead_time = dead_time;
                             (new_queue[i][0])->Front->pariority = i;
                              //printf("data= %d and (new_queue[%d][0])->Front->data = %d \n",data,i+1,(new_queue[i+1][0])->Front->data);
                              //printf("data is lower than last data\n");

                             counter--;
                        }
                    }

                    break;
                }
                element_numb++;
            }



    }

    int count = element_numb;
    //printf("count = %d \n",count);
    int courses_taken=0;
    int temp=0;

    if (count != 0){
        //printf("entered count\n");
        for(i=0 ; i< count ;i++){
            //printf("entered for loop and i =%d\n",i);
            //printf("entered while loop and i =%d\n",i);
            data = (new_queue[i][0])->Front->data;
            dead_time = (new_queue[i][0])->Front->dead_time;
            //printf("queue [%d] [%d]  = %d and it's dead_time = %d \n",i,0,data,dead_time);

            temp = data + temp;
            if(temp <= dead_time){
                courses_taken++;
                //printf("we can take this course\n");
            }
            else if ( temp > dead_time){
                temp = temp - data;
            }
        }
    }

    printf("%d\n",courses_taken);
    return 0;
}
