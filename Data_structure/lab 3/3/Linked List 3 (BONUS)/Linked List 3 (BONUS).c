#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct lifo stack;
struct lifo{
   signed long int value;
   struct lifo *next;
};
stack *top;
void create (stack **top)
{ *top = NULL; }
void push (stack **top, signed long int element)
{
    stack *new;
    new = (stack *)malloc (sizeof(stack));
    if (new == NULL) {  return; }
    new->value = element;
    new->next = *top;
    *top = new;
}
signed long int pop (stack **top)
{
   signed long int t;
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

int main(){
    stack *A,*B,*C;
    create(&A);
    create(&B);
    create(&C);
    long int s; // long from 1 to  10^9
    int n;// int 1 to  10^4
    signed long int value;
    int counter=0;
    scanf("%ld %d",&s,&n);
    while (counter<s){
        scanf("%ld",&value);
        push(&A,value);
        counter++;
    }
    int i;
    int test=0;
    long int counter2=s;
    int reversed=0;
    for(i=0;i<s;i++)  {  push (&B,pop(&A));  } // reverse the stack
    while (test == 0){
        if (counter2>=n){
            for(i=0;i<n;i++)  {  push (&A,pop(&B));  } // put reversed values in a
            for(i=0;i<n;i++)  {  push(&C,pop(&A));   } // storing reversed values to be returned back to b later
            reversed++;
            counter2=counter2-n;
        }
        else  { test=1;  }
    }
    //printf("reversed = %d \n",reversed);
    if(reversed!=0){
        for (i=0; i< reversed*n ;i++)  {  push(&B,pop(&C));  }
    }
    for (i=0;i<s;i++)  { printf("%ld\n",pop(&B));  }
    return 0;
}
