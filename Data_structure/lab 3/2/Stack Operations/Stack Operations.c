#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct lifo stack;

struct lifo
{
   unsigned long int value;
   struct lifo *next;
};
stack *top;

void create (stack **top)
{
   *top = NULL;
}

void push (stack **top, unsigned long int element)
{
    stack *new;
    new = (stack *)malloc (sizeof(stack));
    if (new == NULL)
    {
       //printf ("\n Stack is full");
       //return;
    }

    new->value = element;
    new->next = *top;
    *top = new;
}

unsigned long int pop (stack **top)
{
   unsigned long int t;
   stack *p;

   if (*top == NULL)
   {
      //printf ("\n Stack is empty");
      //return 0;
   }
   else
   {
      t = (*top)->value;
      p = *top;
      *top = (*top)->next;
      free (p);

   }
   return t;
}



void Delete_the_element (stack **top)
{
   stack *p;

   if (*top == NULL)
   {
      //printf ("\n Stack is empty");
      //exit(0);
   }
   else
   {
      p = *top;
      *top = (*top)->next;
      free (p);

   }
}

unsigned long int Print_the_minimum(stack **top,int in){

    unsigned long int temp,small_value;
    int i;
    stack *A, *B;
    create(&A);
    create(&B);

    if (*top == NULL)
   {
      //exit(0);
   }
   else{
    A = *top;
    temp=pop(&A);
    small_value=temp;
    push(&A,temp);
    for(i=0;i<in;i++){
        temp=pop(&A);
        if(temp<small_value ){
            small_value=temp;
            }
        push(&B,temp);
    }
    for(i=0;i<in;i++){
        push(&A,pop(&B));
        }
    }
   return small_value;
}


void print_all(stack **top,int out){
    int i;
    stack *C, *B;
    create(&C);
    create(&B);
     if (*top == NULL)
   {
      exit(0);
   }

    else{
       C = *top;
        if(out>0){
            for(i=0;i<out;i++){
                push(&B,pop(&C));
            }
            for(i=0;i<out;i++){
                printf("%ld\n",pop(&B));
            }
        }
    }
}


int main()
{
    stack *A, *C;
    create(&A);
    create(&C);

    unsigned long int value=1;
    unsigned long int operation,number_of_operations;
    unsigned long int small_value;

    int counter=0;
    int in=0;
    int out=0;

    scanf("%lu",&number_of_operations);
    if(number_of_operations<1 || number_of_operations>(1000000)){
        return 0;
    }
    else{

    while( counter<number_of_operations && value>=1 && value<=1000000000 ){
        scanf("%lu",&operation);
        if(operation == 1){
            scanf("%lu",&value);
            push(&A,value);
            in++;
        }
        else if(operation == 2){
            if(in == 0){
                printf("Empty\n");
                return 0;
            }
            else if(in > 0){
                Delete_the_element(&A);
                in--;
            }
        }
        else if(operation == 3){

                if(in == 0){
                    printf("Empty\n");
                    return 0;
                }
                else if(in > 0){
                    out++;

                    small_value=Print_the_minimum(&A,in);
                    printf("%lu\n",small_value);
                    push(&C,small_value);
                    }
                }
        else{
            return 0;
        }
        counter++;

    }

    //print_all(&C,out);
    }
    return 0;
}
