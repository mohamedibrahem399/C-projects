#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to swap elements
void swap(long int *a, long int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(long int arr[], long int arr2[] , int start, int end) {
  int pivot = arr[end];
  int p_index = (start - 1);
  int j;
  for ( j = start; j < end; j++) {
    if (arr[j] <= pivot) {
      p_index++;
      swap(&arr[p_index], &arr[j]);
      swap(&arr2[p_index], &arr2[j]);
    }
  }
  swap(&arr[p_index + 1], &arr[end]);
  swap(&arr2[p_index + 1], &arr2[end]);
  return (p_index + 1);
}

void quickSort(long int arr[] , long int arr2[] , int start, int end) {
  if (start < end) {
    int p_index = partition(arr, arr2 , start, end);
    quickSort(arr, arr2 , start, p_index - 1);
    quickSort(arr, arr2 , p_index + 1, end);
  }
}
// getting number of digits of each element
long int number_of_digits(long int numb){
    int digit_number = 0;
    int temp = numb;
    while (temp != 0 ){
        temp = temp/10;
        digit_number++;
    }
    return digit_number;
}
// zero bedding the small numbers
void bedding (long int arr[] , int n , long int max , long int bid ){
    int i;
    long int max_digit = number_of_digits( max );
    for(i=0;i<n;i++){
        long int x = number_of_digits(arr[i]);
            if( x < max_digit ){
                long int k = max_digit - x;
                int i3;
                long int p  = bid;
                long int p1 = 1;
                for(i3 = 0 ; i3< k ; i3++ ){
                    p = p + p * 10;
                    p1= p1 * 10;
                }
                p=p/10;
                arr[i]= arr[i] * p1 + p;
                //printf("k = %ld , x= %ld , max_digit = %ld , p = %ld , arr[%d] = %ld \n",k,x,max_digit,p,i,arr[i]);
            }
    }
}

//get max element of the array
long int get_max( long int arr[] , int n){
    long int max = arr[0];
    int i;
    for(i=0;i<n;i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
    return max;
}
//calculating number of zeros in the array
int number_of_zeros( long int arr[] , int n){
    int x = 0;
    int i;
    for (i=0; i<n ; i++){
            if(arr[i] == 0){
                x++;
            }
    }
    return x;
}
//print array
void print_arr(long int arr[] , int n){
    int i = 0;
    for(i=0 ; i<n ; i++){
        printf("%ld\n",arr[i]);
    }
}


int main()
{
    int elements_number; // 10 ^4

    scanf("%d",&elements_number);
    long int *arr = malloc (elements_number * sizeof(long int) ); // -10^9 to 10^9-1
    long int *arr2 = malloc (elements_number * sizeof(long int) ); // -10^9 to 10^9-1
    long int *arr3 = malloc (elements_number * sizeof(long int) ); // -10^9 to 10^9-1

    int i;
    for (i=0; i <elements_number ; i++){
        scanf("%ld",&arr[i]);
        arr2[i]=arr[i];
        arr3[i]=arr[i];
    }
    int start = 0;
    int end = elements_number - 1;

    //printf("max = %d \n",get_max(arr2 , elements_number ) );
    long int v1;
    long int full_number=0;
    long int arr_test [10];

    for (v1 = 0 ; v1 <= 9 ; v1++) {
            full_number=0;
            for(i=0 ; i<elements_number ; i++){
                arr2[i] = arr3[i];
                arr [i] = arr3[i];
                //printf("arr [%d] = %ld \n",i,arr[i]);
            }

            bedding (arr2, elements_number , get_max(arr2 , elements_number ) , v1 );
            quickSort( arr2 , arr , start , end);

            //printf("\n");
            //print_arr (arr2, elements_number);
            //print_arr (arr, elements_number);

            //calculating total digits we have as numbers in our array
            long int total_number_of_digits =0;
            for(i=0 ; i < elements_number ; i++ ){
                total_number_of_digits = total_number_of_digits + number_of_digits (arr[i]);
            }

            //printf("total_number_of_digits = %ld \n",total_number_of_digits);

            long int counter = total_number_of_digits;

            int j;

            //calculating the number of zeros in the array
            int zeros_number  = number_of_zeros (arr , elements_number);

            for( i = elements_number - 1 ; i >= 0 ; i-- ){

                long int x = number_of_digits(arr[i]);
                long int y = 1;
                counter = counter - x;
                for(j=0; j < counter ; j++){
                    y = y * 10;
                }
                long int z = arr[i] * y;
                full_number = full_number + z;
            }
            //adding the zeros in the number
            if( zeros_number > 0 ){
                int p = 1;
                for(i=0 ; i< zeros_number ; i++){
                    p= p*10;
                    }
                full_number = full_number * p;
            }
        //printf("%ld \n",full_number);
        arr_test [v1]= full_number;
        }

    full_number = get_max(arr_test , 10);

    printf("%ld \n",full_number);

    return 0;
}
