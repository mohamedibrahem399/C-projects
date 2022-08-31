#include <stdio.h>
#include <stdlib.h>

signed long int **create_2d_array (int rows , int columns);
void print_array (signed long int **arr, int n , int l);
int count_elements (signed long int **arr, int n , int l);
signed long int **convert_array (signed long int **arr, int n , int l, int c1);

int main()
{
    int i,j,k;
    int c1=0;
    int c2=0;
    int n , l , n2 , l2;

    printf("enter the dimension of the first 2d array\n");
    scanf("%d %d",&n,&l);
    signed long int **arr1= create_2d_array(n,l);

    printf("enter the dimension of the second 2d array \n");
    scanf("%d %d",&n2,&l2);
    signed long int **arr2= create_2d_array(n2,l2);

    printf("enter the elements of the first 2d array\n");
    for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){
            scanf("%ld",&arr1[i][j]);
        }
    }

    printf("enter the elements of the second 2d array\n");
    for(i=0; i<n2 ; i++){
        for(j=0; j<l2 ; j++){
            scanf("%ld",&arr2[i][j]);
        }
    }


    //printf("\n");
    //c1 =count_elements(arr1,n,l);
    //signed long int **arr1_sparse= create_2d_array(3,c1);
    //arr1_sparse = convert_array(arr1,n,l,c1);
    //print_array(arr1_sparse,3,c1);

    //printf("\n");

    //c2 =count_elements(arr2,n2,l2);
    //signed long int **arr2_sparse= create_2d_array(3,c2);
    //arr2_sparse = convert_array(arr2,n2,l2,c2);
    //print_array(arr2_sparse,3,c2);


    signed long int **result;
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


// hacker rank code:
// link:
//https://www.hackerrank.com/contests/data-structures-lab-2-1635077002/challenges/sparse-matrix-6-1/problem
/*
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int **create_2d_array (int rows , int columns);
void print_array (int **arr, int n , int l);


int main()
{
    int i,j,k, n , l , n2 , l2;
    int test=1;

    scanf("%d %d",&n,&l);
    int **arr1= create_2d_array(n,l);

    for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){
            scanf("%d",&arr1[i][j]);
        }
    }

    scanf("%d %d",&n2,&l2);
    int **arr2= create_2d_array(n2,l2);

    for(i=0; i<n2 ; i++){
        for(j=0; j<l2 ; j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    for(i=0; i<n2 ; i++){
        for(j=0; j<l2 ; j++){
            if(arr2[i][j]<-2147483648 || arr2[i][j]>2147483647)
                test=0;
        }
    }
      for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){
            if(arr1[i][j]<-2147483648 || arr1[i][j]>2147483647)
                test=0;
        }
    }

    while(test != 0){
    int **result;
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

    test =0;
    }
    return 0;
}

int **create_2d_array (int rows , int columns){
    int i , j;
    int **arr= calloc(rows , sizeof(int *));
    for (i=0; i<rows ; i++){
        arr[i] = calloc(columns , sizeof(int));
    }
return arr;
}


void print_array (int **arr, int n , int l){
int i,j;
    for(i=0; i<n ; i++){
            for(j=0; j<l ; j++){
                printf("%d ",arr[i][j]);
            }
        printf("\n");
        }
return;
}
*/


