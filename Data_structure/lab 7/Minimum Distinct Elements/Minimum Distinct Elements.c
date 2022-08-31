#include <stdio.h>
#include <stdlib.h>

void combine_with_sort ( long int main_arr[]  ,  long int larr[] , int l ,  long int rarr[] , int r ){
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


void merge_sort( long int arr[] , int m ){
    int i;

    //printf("m = %d\n",m);

    if( m < 2 ) {return;}

    int mid_of_arr = m/2;
    //printf("mid_of_arr = %d\n",mid_of_arr);

    long int *larr = malloc ( mid_of_arr * sizeof( long int) );
    long int *rarr = malloc ((m - mid_of_arr ) * sizeof( long int)) ;

    for (i= 0 ; i < mid_of_arr ; i++ ){
        larr[i] = arr[i];
        //printf("larr[%d] = %ld , arr[%d] = %ld \n",i,larr[i],i,arr[i]);
    }
    for (i = mid_of_arr ; i < m ;i++ ){
        rarr[i - mid_of_arr ] = arr[i];
        //printf("i- mid of arr = %d\n",i-mid_of_arr);
        //printf("rarr[%d] = %ld , arr[%d] = %ld \n",i - mid_of_arr , rarr[i] , i , arr[i]);
    }

    merge_sort(larr , mid_of_arr  );
    merge_sort(rarr , m - mid_of_arr);
    combine_with_sort (arr , larr , mid_of_arr , rarr , m - mid_of_arr );

}


int main()
{
    int elements_number; // 10 ^4
    int r;//removals number

    scanf("%d %d",&elements_number,&r);

    if(r == elements_number ) {
            printf("0\n");
            return 0;
    }
    else if(r == elements_number -1 ) {
            printf("1\n");
            return 0;
    }


    long int *arr = malloc (elements_number * sizeof( long int) ); // -10^9 to 10^9-1

    int i;
    // entering the data into the array
    for (i=0; i <elements_number ; i++){
        scanf("%ld",&arr[i]);
    }
    merge_sort(arr , elements_number);


    int j;
    long int arr2[elements_number][2];
    for (i=0; i<elements_number ; i++){
            arr2[i][0]=0;
            arr2[i][1]=0;
    }
    // putting arr elements into arr2
    for(i=0; i<elements_number ; i++){
            arr2[i][0]=arr[i];
            for (j=i;j<elements_number;j++){
                if(arr[j] == arr[i] ){
                     arr2[i][1]++;
                }
            }
    }
    //remove duplicated elements
    for(i=0; i<elements_number ; i++){
            for (j=i+1;j<elements_number;j++){
                if(arr2[j][0] == arr2[i][0] ){
                     arr2[j][0] = -1 ;
                }
            }
    }

    int co = elements_number;

    for(i=0; i<co ; i++){
        if(arr2[i][0] == -1){
            int k;
            arr2[i][1]=1;
            for (k=i; k <co ; k++){
                for (j=k+1;j<co;j++){
                    int temp1 = arr2[k][1];
                    arr2[k][1] = arr2[j][1];
                    arr2[j][1] = temp1;
                    int temp0 = arr2[k][0];
                    arr2[k][0] = arr2[j][0];
                    arr2[j][0] = temp0;
                }
            }
            co--;
        }
    }

    //putting most duplicated elements at first
    for(i=0; i<co ; i++){
            for (j=i;j<co;j++){
                if( arr2[j][1] > arr2[i][1] && arr2[j][0] != -1){
                    int temp1 = arr2[i][1];
                    arr2[i][1] = arr2[j][1];
                    arr2[j][1] = temp1;
                    int temp0 = arr2[i][0];
                    arr2[i][0] = arr2[j][0];
                    arr2[j][0] = temp0;
                }
            }
    }

    int k;
    for (i=0; i<co ; i++){
            if(arr2[i][0]== -1){
                    arr2[i][1]=1;
                    for(k= i ; k< co ; k++){
                        for (j=k+1;j<co;j++){
                            int temp1 = arr2[k][1];
                            arr2[k][1] = arr2[j][1];
                            arr2[j][1] = temp1;
                            int temp0 = arr2[k][0];
                            arr2[k][0] = arr2[j][0];
                            arr2[j][0] = temp0;
                            //printf("arr2[j=%d][1] = %ld , arr2[k=%d][1] = %ld \n",j,arr2[j][1],k,arr2[k][1]);
                        }
                    }
                co--;
            }
    }
/*
    for (i=0; i<co ; i++){
        printf("arr2[%d] = %ld  %ld \n",i,arr2[i][0],arr2[i][1]);

    }
*/

    for (i = 0 ; i< r ; i++){
        if(arr2[co-1][1]==1){
            co--;
        }
        else if(arr2[co-1][1]> 1){
            arr2[co-1][1]--;
        }

    }

    //printf("\n");
    /*for (i=0; i<co ; i++){
        printf("arr2[%d] = %ld  %ld \n",i,arr2[i][0],arr2[i][1]);

    }
    */
    int result=0;
    for (i=0; i<co ; i++) {
        if(arr2[i][0] == -1){
            result = result;
        }
        else if ( arr2[i][0]!= -1 && arr2[i][1] > 0 ){
            result++;
        }
        else{
            result = result;
        }
    }
    //print number of elements left after removal of least "r" duplicated elements
    printf("%d\n",result);


    return 0;
}
