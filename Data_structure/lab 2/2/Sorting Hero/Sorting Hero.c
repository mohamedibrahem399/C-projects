#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int l);
void scan_arr (int *arr, int l);
//void print_arr(int *arr, int l);
int compare (int *arr1, int l1 , int *arr2 , int l2 );

int main()
{
    int l1,l2;
    int test1=1;
    int i=0;
    int result;
       scanf("%d %d",&l1,&l2);
    if(l1>=0 && l1<=40000 && l2>=0 && l2<=40000){

    int *arr1= (int*) calloc(l1 , sizeof( int));
    int *arr2= (int*) calloc(l2 , sizeof( int));

    //printf("enter array 1 and 2 sizes\n");

    //scanf("%d %d",&l1,&l2);

    //printf("enter array 1 elements \n");
    scan_arr(arr1,l1);

    //printf("enter array 2 elements \n");
    scan_arr(arr2,l2);

    for (i=0; i<l1;i++){
        if( arr1[i]<1 || arr1[i]> 2147483647 )
                test1=0;
    }
    for (i=0; i<l2;i++){
        if(arr2[i]<1 || arr2[i]> 2147483647){
            test1=0;
        }
    }
    while (test1 != 0){
    //print_arr(arr1,l1);
    //print_arr(arr2,l2);
    sort(arr1 , l1);
    sort (arr2 , l2);
    //print_arr(arr1,l1);
    //print_arr(arr2,l2);
    result=compare(arr1,l1,arr2,l2);
    printf("%d",result);
    test1=0;
        }
    }
    return 0;
}


void sort(int *arr, int l){
    int i,k,n,temp;
    n=1;
    for (i=0;i<l;i++){
        for(k=n;k<l;k++){
            if (arr[i] > arr[k] )
            {
                temp = arr[i];
                arr[i]= arr[k];
                arr[k]= temp;
            }
        }
        n++;
    }
return;
}

void scan_arr (int *arr, int l){
    int i;
    for (i=0; i<l;i++){
        scanf("%d",&arr[i]);
        //if( arr[i]<1 || arr[i]> 2147483647 )

    }
return;
}
/*
void print_arr(int *arr, int l){
    int i;
    for (i=0; i<l;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
return;
}*/

int compare (int *arr1, int l1 , int *arr2 , int l2 ){
    int count=0;
    int i;
    int n=0;
    int k;

    for (i=0;i<l1;i++){
        k=n;
        while(k<l2){
            if (arr1[i] >= arr2[k])
                {
                    n++;
                    count++;
                    k=l2;
                }
                else
                    k++;

            }
    }
return count;
}
