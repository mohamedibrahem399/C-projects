#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct lifo stack;
struct lifo{
   unsigned int value;
   struct lifo *next;
};
stack *top;
void create (stack **top)
{ *top = NULL;  }
void push (stack **top, unsigned int element)
{
    stack *new;
    new = (stack *)malloc (sizeof(stack));
    if (new == NULL) {  return; }
    new->value = element;
    new->next = *top;
    *top = new;
}
unsigned long int pop (stack **top)
{
   unsigned int t;
   stack *p;
   if (*top == NULL) {  return 0;  }
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
   if (*top == NULL)  {  return ;  }
   else
   {
      p = *top;
      *top = (*top)->next;
      free (p);
   }
}

unsigned long int Print_the_minimum(stack **top,int in){
    unsigned int temp,small_value;
    int i;
    stack *A, *B;
    create(&A); create(&B);
    if (*top == NULL) {  return 0;  }
   else{
    A = *top;
    temp=pop(&A);
    small_value=temp;
    push(&A,temp);
    for(i=0;i<in;i++){
        temp=pop(&A);
        if(temp<small_value ){  small_value=temp; }
        push(&B,temp);
    }
    for(i=0;i<in;i++){
        push(&A,pop(&B));    }
    }
   return small_value;
}
int main(){
    stack *A; create(&A);
    unsigned int value=1;
    unsigned int operation,  number_of_operations,  small_value;
    int counter=0;      int in=0;       int out=0;
    scanf("%d",&number_of_operations);

    if(number_of_operations<1 || number_of_operations>(1000000)){return 0;}
    else{
    while( counter<number_of_operations /*&& value>=1 && value<=1000000000*/ ){
        scanf("%d",&operation);
        if(operation == 1){
            scanf("%d",&value);
            if(value<1 || value>(1000000000)){counter=counter;}
            else{
                    push(&A,value);
                in++;
            }
        }
        else if(operation == 2){
            if(in == 0){  counter = counter;}  //printf("Empty\n");   }
            else if(in > 0){
                Delete_the_element(&A);
                in--;
            }
        }
        else if(operation == 3){
                if(in == 0){   printf("Empty\n");   }
                else if(in > 0){
                    out++;
                    small_value=Print_the_minimum(&A,in);
                    printf("%d\n",small_value);
                    }
                }
        else{return 0;}
        counter++;
        }
    }
    return 0;
}
