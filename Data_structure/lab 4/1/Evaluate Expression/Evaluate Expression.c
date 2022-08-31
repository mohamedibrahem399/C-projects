#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lifo stack;
struct lifo{
    signed int value;
    struct lifo *next;
};
stack *top;
void create (stack **top)
{ *top = NULL; }
void push (stack **top, signed int element)
{
    stack *new;
    new = (stack *)malloc (sizeof(stack));
    if (new == NULL) {  return; }
    new->value = element;
    new->next = *top;
    *top = new;
}
signed int pop (stack **top)
{
   signed int t;
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

int main()
{
    stack *A,*B,*C;
    create(&A);
    create(&B);
    create(&C);

    char s[10000];

    scanf("%s",s);
    //printf("%s\n",s);
    int i;
    int counter = strlen(s);

    for (i =0 ; i < counter ; i++)
    {
        //printf("%d\n",s[i]);
        if((int) s[i] >= 48 && (int) s[i] <= 57){
            int value = (int) s[i] -48;
            //printf("this is int and = %d \n",value);
            push(&A, value);
        }
        else{
            push(&A, (int) s[i]);
        }
    }
    for (i =0; i< counter; i++){ push(&B,pop(&A));}

    int in=0;
    for (i =0; i< counter; i++)
        {
             int value= pop(&B);
             if(value>=0 && value<=9 ){
                in++;
                push(&C,value);
                //printf("value entered = %d\n",value);
             }
             else if( value >=37 && value<= 47 ){
                switch (value){
                    case 42: {//*
                            signed int value2=pop(&C);
                            signed int value1=pop(&C);
                            in--;
                            push(&C , value1 * value2 );
                            break;}
                    case 43:{ // +
                            signed int value2=pop(&C);
                            signed int value1=pop(&C);
                            push(&C , value1 + value2 );
                            in--;
                            break;}
                    case 45: {// -
                            signed int value2=pop(&C);
                            signed int value1=pop(&C);
                            push(&C , value1 - value2 );
                            in--;
                            break;}
                    case 47:{ // /
                                int value2=pop(&C);
                                int value1=pop(&C);
                            if(value2 == 0 )
                            {
                                printf("Not Valid\n");
                                return 0;
                            }
                            else{

                                push(&C , value1 / value2 );
                                in--;
                            }

                            break;}
                     case 37:{ // %
                                int value2=pop(&C);
                                int value1=pop(&C);
                            if(value2 == 0 )
                            {
                                printf("Not Valid\n");
                                return 0;
                            }
                            else{

                                push(&C , value1 % value2 );
                                in--;
                            }

                            break;}
                    default:{
                            printf("Not Valid\n");
                            return 0;
                            break;}
                }
             }
             else{
                printf("Not Valid\n");
                return 0;
             }
        }
    if(in==1){
       printf("%d",pop(&C));
    }
    else{
        printf("Not Valid\n");
    return 0;
    }


    /*
    37 == %
    42 == *
    43 == +
    45 == -
    47 == /
    */

    return 0;
}
