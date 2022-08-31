#include <stdio.h>
#include <stdlib.h>

void combine_with_sort (signed long int main_arr[]  , signed long int larr[] , int l , signed long int rarr[] , int r ){
    //int m = sizeof (main_arr) / sizeof (main_arr[0]);
    //int l = sizeof (larr) / sizeof (larr[0]);
    //int r = sizeof (rarr) / sizeof (rarr[0]);
    //printf("l = %d , r= %d \n",l,r);
    int i=0;
    int j=0;
    int k=0;

    while (i<l && j<r ){
        if(larr[i] <= rarr[j]){
            main_arr[k] = larr[i];
            k++;
            i++;
        }
        else {
            main_arr[k] = rarr[j];
            j++;
            k++;
        }
    }
    while (i < l){
        main_arr [k] = larr[i];
        i++;
        k++;
    }
    while (j < r ){
        main_arr [k] = rarr[j];
        j++;
        k++;
    }

}


void merge_sort( signed long int arr[] , int m ){
    int i;

    //printf("m = %d\n",m);

    if( m < 2 ) {return;}

    int mid_of_arr = m/2;
    //printf("mid_of_arr = %d\n",mid_of_arr);

    signed long int *larr = malloc ( mid_of_arr * sizeof(signed long int) );
    signed long int *rarr = malloc ((m - mid_of_arr ) * sizeof(signed long int)) ;

    for (i= 0 ; i < mid_of_arr ; i++ ){
        larr[i] = arr[i];
        //printf("larr[%d] = %ld , arr[%d] = %ld \n",i,larr[i],i,arr[i]);
    }
    for (i = mid_of_arr ; i < m ;i++ ){
        rarr[i - mid_of_arr ] = arr[i];
        //printf("i- mid of arr = %d\n",i-mid_of_arr);
        //printf("rarr[%d] = %ld , arr[%d] = %ld \n",i - mid_of_arr , rarr[i] , i , arr[i]);
    }
/*
    // printing the  left and the right elements;
    for(i = 0 ; i< mid_of_arr  ; i++ ){
        printf("left arr [%d] = %ld \n",i,larr[i]);
    }
    for(i = 0 ; i< m - mid_of_arr   ; i++ ){
        printf("right arr [%d] = %ld \n",i,rarr[i]);
    }
*/
    merge_sort(larr , mid_of_arr  );
    merge_sort(rarr , m - mid_of_arr);
    combine_with_sort (arr , larr , mid_of_arr , rarr , m - mid_of_arr );

}


int main()
{
    int elements_number; // 10 ^4

    scanf("%d",&elements_number);
    signed long int *arr = malloc (elements_number * sizeof(signed long int) ); // -10^9 to 10^9-1

    int i;

    // entering the data into the array

    for (i=0; i <elements_number ; i++){
        scanf("%ld",&arr[i]);
    }

    merge_sort(arr , elements_number);

    //printing the array
    for (i=0; i <elements_number ; i++){
        printf("%ld\n",arr[i]);
    }


    return 0;
}
