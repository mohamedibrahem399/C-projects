#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

signed long int **create_2d_array (int rows , int columns);
void print_array (signed long int **arr, int n , int l);
signed long int **search (signed long int **arr1,int c1 , int n ,signed long int **arr2 , int c2 , int l2 );


int main()
{
    signed long int i;
    signed long int j;
    int n , l , n2 , l2;


    scanf("%d %d",&n,&l);

    signed long int **arr1= create_2d_array(3 , n*l);
    signed long int element;
    int c=0;
    int c2=0;

    for(i=0;i<n;i++){
        for(j=0;j<l;j++){
            scanf("%ld",&element);
            if(element != 0){
            arr1[0][c]=i;//rows
            arr1[1][c]=j;//collumns
            arr1[2][c]=element;//values
            c++;
            }
        }
    }
    arr1= realloc(arr1 , c);

    //printf("test= %d\n",test);
    scanf("%d %d",&n2,&l2);
    signed long int **arr2= create_2d_array(3, n2 * l2);
    for(i=0;i<n2;i++){
        for(j=0;j<l2;j++){
            scanf("%ld",&element);
            if(element != 0){
            arr2[0][c2]=i;//rows
            arr2[1][c2]=j;//collumns
            arr2[2][c2]=element;//values
            c2++;
            }
        }
    }
    arr2= realloc(arr2 , c2);

    //printf("test= %d\n",test);

signed long int **result;


    if( l == n2){
        result = create_2d_array(n,l2);
        result= search(arr1,c,n,arr2,c2,l2);
        print_array(result, n ,l2);
    }
    else
        printf("Not Valid");

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

signed long int **search (signed long int **arr1,int c1 , int n ,signed long int **arr2 , int c2 , int l2 ){
    int i,j,k;
    signed long int **result;
    result = create_2d_array(n,l2);
    for (i=0;i<l2;i++){//search in the row of columns values for value i
        for (j=0;j<c2;j++){// search every element in columns row for value i
                if (arr2[1][j]== i){// if i found number = i , i need to multiply it with every one in other matrix with the same column
                    for (k=0;k<c1;k++){
                        if(arr1[1][k]==arr2[0][j]){
                            result[arr1[0][k]][i]+= arr1[2][k]*arr2[2][j];
                            }
                    }
                }
            }
    }
return result;
}
