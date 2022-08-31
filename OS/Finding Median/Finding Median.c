#include <stdio.h>
#include <stdlib.h>

void swap (signed long int *a1 , signed long int *a2 ){
signed long int temp = *a1;
*a1 = *a2 ;
*a2 = temp;
}

void make_max_heap ( signed long int arr [] , int n , signed long int value ){
    n=n+1;
    arr[n-1] = value;
    int i = n-1;
    while (i >= 1){
        int parent = (i /2);
        if( arr[parent] < arr[i] ){
           swap(&arr[parent], &arr[i]);
           i = parent;
        }
        else {
            return;
        }
    }
}

void sort_h (signed long int arr []  , int size ){

int i=0;

while(i < size-1 &&  2*i+1 < size-1 &&  2*i+1 <size-1 ){
    if ( arr[2*i+1] > arr[2*i +2] &&  arr[2*i+1] > arr[i] ){
        swap( &arr[i] , &arr[2*i+1] );
        i = 2*i+1;
    }
    else if ( arr[2*i+1] < arr[2*i +2] &&   arr[2*i +2] > arr[i] ){
        swap(&arr[i] , &arr[2*i +2]);
        i = 2*i+2;
        }
    else{
        return;
        }
    }
}


void heap_sort (signed long int arr []  , int size ){

if(size == 0 ){return;}

while (size > 1){
    swap( &arr[0] , &arr[size-1] );
    size--;
    sort_h(arr , size);
  }
}

int main()
{
    signed long int data;
    int i;
    int elements_number;
    scanf("%d",&elements_number);
    if(elements_number == 0  ){
        printf("Not Exist\n");
        return 0;
    }
    signed long int *arr = malloc( elements_number * sizeof(signed long int) );
    for(i=0;i<elements_number ; i++){
        scanf("%ld",&data);
        if(i == 0){
            arr[i] = data;
        }
        else{
            make_max_heap(arr , i , data);
        }
    }

    heap_sort (arr,elements_number);

    float median;

    if(elements_number% 2 == 0){

       signed long int temp1 = arr[elements_number/2];
       signed long int temp2 = arr[(elements_number/2)-1];

       if ( ( temp1%2 == 1 && temp2%2==1) || (temp1%2 ==0 && temp2%2==0) ) {
            median = (temp1 + temp2)/2;
            //printf("%d\n",(int) median);
       }
       else {
            median = (temp1 + temp2)/2.0;
            //printf("%0.1f\n",median);
             }
      }
    else if(elements_number %2 == 1){
        median = arr[ (elements_number /2 ) ];
       //printf("%d\n",(int) median);
    }

    if  (  (float) ( ((int)median) == median) ){
        printf("%d\n",(int) median);
    }
    else{
        printf("%0.1f\n",median);
    }



    return 0;
}
