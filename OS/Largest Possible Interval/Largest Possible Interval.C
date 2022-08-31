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
        //printf("value = %d , parent = %d , i = %d , n = %d \n",value, parent , i , n);
        //printf("arr[parent-1] = %d , arr[parent] = %d , arr[i] = %d  \n",arr[parent-1], arr[parent] , arr[i]);
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

while(i < size &&  2*i+1 < size-1 &&  2*i+1 <size ){
    if ( arr[2*i+1] > arr[2*i +2] &&  arr[2*i+1] > arr[i] ){
        swap( &arr[i] , &arr[2*i+1] );
        //printf("arr[i-1]=%ld , arr[2*i]=%ld , i=%d \n",arr[i-1],arr[2*i],i);
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
    //printf("arr[0]=%ld , arr[size-1]=%ld , size=%d \n",arr[0],arr[size-1],size);
    swap( &arr[0] , &arr[size-1] );
    size--;
    sort_h(arr , size);
/*
    printf("trail with size = %d \n",size);
    for(i=0;i<size ; i++){
        printf("arr[%d] = %ld\n",i,arr[i]);
    }
*/
}
swap(&arr[0], &arr[1]);

}

int main()
{
    signed long int data;
    int i;
    int elements_number;
    scanf("%d",&elements_number);
    if(elements_number == 0 || elements_number == 1){
        printf("Not Exist\n");
        return 0;
    }


    signed long int *arr = (signed long int*) malloc(elements_number * sizeof(signed long int));

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
/*
        printf("before heap sort\n");
        for(i=0;i<elements_number ; i++){
        printf("arr[%d] = %ld\n",i,arr[i]);
        }
*/



    signed long int arr2[elements_number-1];

    for(i=0;i<elements_number-1;i++){
        data =  arr[i] - arr[i+1];
        //printf("arr[i] = %ld  , arr[i+1] = %ld , i = %d , data= %ld \n",arr[i],arr[i+1],i,data);
        if(i == 0){
            if(data < 0 ){
            arr2[i] = -1 * data;
                }
            else if( arr[i] - arr[i+1] > 0 ){
                arr2[i] = data;
                }
        }
        else if(data < 0 ){
            make_max_heap(arr2 , i , data * -1 );
        }
        else if( data > 0 ){
            make_max_heap(arr2 , i , data );
        }

    }

    heap_sort (arr2,elements_number-1);


/*
    printf("\n");
   for(i=0;i<elements_number-1; i++){
        printf("arr2[%d] = %ld\n",i,arr2[i]);
    }
*/
  printf("%ld\n",arr2[elements_number-2]);

    return 0;
}
