#include <stdio.h>
#include <stdlib.h>


typedef struct lifo stack;

struct lifo
{
   unsigned long int value;
   struct lifo *next;
};

void push (stack **top, unsigned long int element)
{
    stack *new;

    new = (stack *)malloc (sizeof(stack));
    if (*top == NULL)
    {
       //printf ("\n Stack is full");
       return;
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
      return 0;
   }
   else
   {
      t = (*top)->value;
      p = *top;
      *top = (*top)->next;
      free (p);
      return t;
   }
}



int main()
{
    stack *A, *B, *C;
    push(&A,1);
    push(&B,1);
    push(&C,1);

    unsigned long int value=1;
    unsigned long int operation,number_of_operations;
    unsigned long int temp,small_value;
    int counter=0;
    int in=0;
    int out=0;
    int i;

    scanf("%ld",&number_of_operations);
    if(number_of_operations<1 || number_of_operations>(1000000)){
        return 0;
    }

    while( counter<number_of_operations && value>=1 && value<1000000000 ){
        scanf("%ld",&operation);
        if(operation == 1){
            scanf("%ld",&value);

            push(&A,value);
            in++;
        }
        else if(operation == 2){
            if(in == 0){
                printf("Empty");
                return 0;
            }
            else if(in > 0){
                pop(&A);
                in--;
            }
        }
        else if(operation == 3){

                if(in == 0){
                    printf("Empty");
                    return 0;
                }
                else if(in > 0){
                    out++;
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
                push(&C,small_value);
                }
        else{
            return 0;
        }
        counter++;

    }

    if(out>0){
        for(i=0;i<out;i++){
            push(&B,pop(&C));
        }
        for(i=0;i<out;i++){
            printf("%ld",pop(&B));
        }

    }

    return 0;
}


