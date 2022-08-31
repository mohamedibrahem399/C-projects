#include <stdio.h>
#include <stdlib.h>


typedef struct lifo stack;

void create (stack **top);
void push (stack **top, int element);
void push (stack **top, int element);
int pop (stack **top);
int isempty (stack *top);

struct lifo
{
   int value;
   struct lifo *next;
};

//stack *top;

void create (stack **top)
{
   *top = NULL;

   /* top points to NULL,
      indicating empty
      stack            */
}

void push (stack **top, int element)
{
    stack *new;

    new = (stack *)malloc (sizeof(stack));
    if (new == NULL)
    {
       printf ("\n Stack is full");
       exit(-1);
    }

    new->value = element;
    new->next = *top;
    *top = new;
}

int pop (stack **top)
{
   int t;
   stack *p;

   if (*top == NULL)
   {
      printf ("\n Stack is empty");
      exit(-1);
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

int isempty (stack *top)
{
   if (top == NULL)
        return (1);
    else
        return (0);
}

int main() {
    stack *A, *B;
    create(&A);
    create(&B);
    push(&A,10);
    push(&A,20);
    push(&A,30);

    push(&A,15);
    push(&A,25);

    push(&B,pop(&A));
    push(&B,pop(&A));


    printf ("A= %d , B= %d\n", pop(&A), pop(&B));
    printf ("A= %d , B= %d\n", pop(&A), pop(&B));
    printf ("A= %d\n", pop(&A));
    //printf ("A= %d\n", pop(&A));
    //push (&A, pop(&B));

    if (isempty(B))
        printf ("\n B is empty");
    if (isempty(A))
        printf ("\n A is empty");
    return 0;
}
