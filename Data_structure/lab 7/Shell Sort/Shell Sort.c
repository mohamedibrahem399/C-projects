#include <stdio.h>
#include <stdlib.h>

void shell_sort( signed long int arr[] , int n){
    int i;
    int gap = n/2;
    //printf(" gap = %d \n",gap);
    for (gap = n/2 ; gap > 0 ; gap = gap/2){
            //printf("entered \n");
        for (i=gap ; i <n ; i++){
            //printf("entered2 \n");
            signed long int temp = arr[i];
            int j;
            for (j=i; j>= gap && arr[j- gap] > temp ; j = j- gap){
                arr[j] = arr[j- gap];
            }
            arr[j]= temp;
            //printf("temp = %d \n",temp);
        }
    }
}


int main()
{
    int elements_number; // 10 ^4
    int k;

    scanf("%d %d",&elements_number,&k);
    signed long int *arr = malloc (elements_number * sizeof(signed long int) ); // -10^9 to 10^9-1

    int i;

    // entering the data into the array

    for (i=0; i <elements_number ; i++){
        scanf("%ld",&arr[i]);
    }

    shell_sort( arr, elements_number);

    //printing the array
/*
    for (i=0; i <elements_number ; i++){
        printf("%d\n",arr[i]);
    }
*/

    printf("%ld\n",arr[elements_number-k]);

    return 0;
}
