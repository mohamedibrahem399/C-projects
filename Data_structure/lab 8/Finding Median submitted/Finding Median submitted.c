#include <stdio.h>
#include <stdlib.h>
void swap (signed long int *a1 ,signed long int *a2 ){
    signed long int temp = *a1;
    *a1 = *a2 ;
    *a2 = temp;
}

void sort_h(signed long int arr[], int size , int i)
{
    int largest_element =  i         ;
    int left_element    = (2 * i) + 1;
    int right_element   = (2 * i) + 2;

    if (left_element < size && arr[left_element] > arr[largest_element]){
        largest_element = left_element;
    }
    if (right_element < size && arr[right_element] > arr[largest_element]){
        largest_element = right_element;
    }

    if (largest_element != i) {
        swap(&arr[i], &arr[largest_element]);

        sort_h(arr, size, largest_element);
    }
}

void heap_sort(signed long int arr[], int size)
{
    int i;

    for (i = (size/2) - 1 ; i >= 0 ; i--){
        sort_h(arr, size, i);
        }

    for (i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        sort_h(arr, i, 0);
    }
}


int main()
{
    signed long int data;
    int i;
    int elements_number;
    scanf("%d",&elements_number);

    if(elements_number == 0 ){
        printf("Not Exist\n");
        return 0;
    }


    signed long int *arr = (signed long int*) malloc(elements_number * sizeof(signed long int));

    for(i=0;i<elements_number ; i++){
        scanf("%ld",&data);
        arr[i] = data;
    }
    heap_sort (arr,elements_number);

    float median;

    if(elements_number% 2 == 0){

       signed long int temp1 = arr[elements_number/2];
       signed long int temp2 = arr[(elements_number/2)-1];

       if ( ( temp1%2 == 1 && temp2%2==1) || (temp1%2 ==0 && temp2%2==0) ) {
            median = (temp1 + temp2)/2;
            printf("%d\n",(int) median);
       }
       else {
            median = (temp1 + temp2)/2.0;
            printf("%0.1f\n",median);
             }
      }
    else if(elements_number %2 == 1){
        median = arr[ (elements_number /2 ) ];
        printf("%d\n",(int) median);
    }
    return 0;
}
