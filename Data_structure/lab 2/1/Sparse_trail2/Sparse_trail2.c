#include <stdio.h>
#include <stdlib.h>
/*
signed long int **create_2d_array (int rows , int columns);
void print_array (signed long int **arr, int n , int l);
int count_elements (signed long int **arr, int n , int l);
signed long int **convert_array (signed long int **arr, int n , int l, int c1);
signed long int **search (signed long int **arr1,int c1 , int n ,signed long int **arr2 , int c2 , int l2 );


int main()
{
    int i,j;
    int c1=0;
    int c2=0;
    int n , l , n2 , l2;

    //printf("enter the dimension of the first 2d array\n");
    scanf("%d %d",&n,&l);
    signed long int **arr1= create_2d_array(n,l);


    //printf("enter the elements of the first 2d array\n");
    for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){
            scanf("%ld",&arr1[i][j]);
        }
    }
    //printf("enter the dimension of the second 2d array \n");
    scanf("%d %d",&n2,&l2);
    signed long int **arr2= create_2d_array(n2,l2);

    //printf("enter the elements of the second 2d array\n");
    for(i=0; i<n2 ; i++){
        for(j=0; j<l2 ; j++){
            scanf("%ld",&arr2[i][j]);
        }
    }


    //printf("\n");
    c1 =count_elements(arr1,n,l);
    signed long int **arr1_sparse= create_2d_array(3,c1);
    arr1_sparse = convert_array(arr1,n,l,c1);
    //print_array(arr1_sparse,3,c1);

    //printf("\n");

    c2 =count_elements(arr2,n2,l2);
    signed long int **arr2_sparse= create_2d_array(3,c2);
    arr2_sparse = convert_array(arr2,n2,l2,c2);
    //print_array(arr2_sparse,3,c2);
    //printf("\n");

    signed long int **result;


    if( l == n2){
        result = create_2d_array(n,l2);
        result= search(arr1_sparse,c1,n,arr2_sparse,c2,l2);
        print_array(result, n ,l2);
    }
    else
        printf("valid array");


    return 0;
}

signed long int **create_2d_array (int rows , int columns){
    int i ;
    signed long int **arr= calloc(rows , sizeof( int *));
    for (i=0; i<rows ; i++){
        arr[i] = calloc(columns , sizeof(signed long int));
    }
return arr;
}


void print_array (signed long int **arr, int n , int l){
int i,j;
    for(i=0; i<n ; i++){
            for(j=0; j<l ; j++){
                printf("%ld ",arr[i][j]);
            }
        printf("\n");
        }
return;
}

int count_elements (signed long int **arr, int n , int l){

int i,j;
int c1=0;
   for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){
            if(arr[i][j]!=0){
                    c1++;
            }
        }
    }
return c1;
}
signed long int **convert_array (signed long int **arr, int n , int l, int c1){
    signed long int **arr_sparse=create_2d_array(3,c1);
    int c=0;
    int i,j;
       for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){
            if(arr[i][j]!=0){
                    arr_sparse[0][c]= i+1;
                    arr_sparse[1][c]= j+1;
                    arr_sparse[2][c]= arr[i][j];
                    c++;
            }
        }
    }
    return arr_sparse;
}


signed long int **search (signed long int **arr1,int c1 , int n ,signed long int **arr2 , int c2 , int l2 ){
    int i,j,k;
    signed long int **result;
    result = create_2d_array(n,l2);

    for (i=1;i<l2+1;i++){//search in the row of columns values for value i
        for (j=0;j<c2;j++){// search every element in columns row for value i
                if (arr2[1][j]== i){// if i found number = i , i need to multiply it with every one in other matrix with the same column
                    for (k=0;k<c1;k++){
                        if(arr1[1][k]==arr2[0][j]){
                            result[arr1[0][k]-1][i-1]= arr1[2][k]*arr2[2][j];
                            }
                    }
                }
            }
    }
//print_array(result, n ,l2);
return result;
}
*/

/* ---------------------------------------------------------------------------------- */

/*
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long signed int **create_2d_array (int rows , int columns);
void print_array (long signed int **arr, int n , int l);


int main()
{
    int i,j,k, n , l , n2 , l2;

    scanf("%d %d",&n,&l);
    long signed int **arr1= create_2d_array(n,l);

    for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){
            scanf("%ld",&arr1[i][j]);
        }
    }

    scanf("%d %d",&n2,&l2);
    long signed int **arr2= create_2d_array(n2,l2);

    for(i=0; i<n2 ; i++){
        for(j=0; j<l2 ; j++){
            scanf("%ld",&arr2[i][j]);
        }
    }

    long signed int **result;
    if( l == n2){
        result = create_2d_array(n,l2);
        for(i=0; i<n ; i++){
            for(j=0; j<l2 ; j++){
                    for(k=0; k<l; k++){
                        result[i][j] =  arr1[i][k] * arr2[k][j] + result[i][j] ;
                    }
            }
        }
        print_array(result,n,l2);
    }
    else
        printf(" valid array sizes\n");


    return 0;
}

long signed int **create_2d_array (int rows , int columns){
    int i ;
    long signed int **arr= calloc(rows , sizeof(int *));
    for (i=0; i<rows ; i++){
        arr[i] = calloc(columns , sizeof(long signed int));
    }
return arr;
}


void print_array (long signed int **arr, int n , int l){
int i,j;
    for(i=0; i<n ; i++){
            for(j=0; j<l ; j++){
                printf("%ld ",arr[i][j]);
            }
        printf("\n");
        }
return;
}*/


