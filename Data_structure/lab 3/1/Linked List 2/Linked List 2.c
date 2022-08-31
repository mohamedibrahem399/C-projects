#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

typedef struct lifo stack;

void create (stack **top);
void push (stack **top, int element);
void push (stack **top, int element);
signed int pop (stack **top);
signed int isempty (stack *top);


struct lifo
{
   signed int value;
   struct lifo *next;
};

//stack *top;

void create (stack **top)
{
   *top = NULL;
}

void push (stack **top, signed int element)
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

signed int pop (stack **top)
{
   signed int t;
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


struct SinglyLinkedListNode {
    signed int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(signed int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list,signed int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}


int is_it_palindrome(SinglyLinkedListNode* head, signed int numbers_count,int minus) {
    if (minus == 1)
        numbers_count=numbers_count-1;

    stack *A, *B;
    create(&A);
    create(&B);
    push(&A,0);
    push(&B,0);
    struct SinglyLinkedListNode *current_state = head, *next_state = NULL, *temp_state = NULL;
    int counter=numbers_count;
    int j;
    signed int first_number,last_number;
    int test = 0;

    if(head == NULL) {
        return 0;
    }
    else {
        while(current_state != NULL){
            temp_state = current_state;
            next_state = current_state->next;

            // hena el mafrood ne7ot el 7agat de fe stack w ba3d keda na5od awel wa7ed.
            // ba3daha nesha2leb el el stack w na5od a5er wa7ed.
            // ba3d keda nekaren been awel wa7ed w a5er wa7ed.
            push(&A,temp_state->data);
            //printf("temp state data = %d\n",temp_state->data);
            while(next_state != NULL){
                //temp_state = next_state;
                next_state = next_state->next;
            }
            current_state = current_state->next;
        }
    }

    while(counter!=0 && counter!=1 && test == 0){
        //printf("counter before first_number is %d\n",counter);
        first_number=pop(&A);
        //printf("first_number is %d\n",first_number);

        counter--;
        //printf("counter after first_number is %d\n",counter);

            for(j=0;j<counter;j++){
               push(&B,pop(&A));
            }

        last_number=pop(&B);
        //printf("last number is %d\n",last_number);

        counter--;
        //printf("counter after last_number is %d\n",counter);
        //printf("last number is %d and first number is %d \n",last_number, first_number);
        if(first_number == last_number){
            test=0;
        }
        else if(first_number != last_number)
           test=1;
        //printf("test= %d \n",test);
        if(counter>1){
        for(j=0;j<counter;j++){
               push(&A,pop(&B));
            }
        }
    }
    //printf("test=%d\n",test);
    return test;
}



int main(){
    signed long int in;
    int minus=0;
    int test=0;
    int counter=1;
    scanf("%ld",&in);

    if(in<0){
        in=in*-1;
        minus=0;
    }


    signed int temp = in;
    int final_test;

    while (test==0){
        if(temp/10 !=0){
                temp=temp/10;
                counter++;
    }
    else
        test=1;
   }
        if(counter == 1 || counter == 0){
        printf("YES");
        return 0;
    }


    char *charValue =   malloc(counter*sizeof(char));
    sprintf(charValue, "%ld", in);

    //printf("number of digits in in = %d\n",counter);

    SinglyLinkedList* numbers = malloc(sizeof(SinglyLinkedList));
    numbers->head = NULL;
    numbers->tail = NULL;
    int i=0;

    int numbers_count = counter;
    if(counter == 0)
    {
        printf("YES");
        return 0;
    }

            for (i = 0; i < numbers_count; i++) {
                    signed int numbers_item = charValue[i]-48;
                    insert_node_into_singly_linked_list(&numbers, numbers_item);
                }



    final_test = is_it_palindrome(numbers->head,numbers_count,minus);

    if(final_test== 0)
        printf("YES");
    else
        printf("NO");
return 0;
}
