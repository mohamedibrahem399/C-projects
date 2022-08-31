#include <stdio.h>
#include <stdlib.h>
signed long int **create_2d_array (int rows , int columns);
void print_array (signed long int **arr, int n , int l);


int main()
{
    int l2=3;
    int c2=3;
    int c1=2;
    signed long int arr1[3][2]=  {{1,2},
                                  {1,3},
                                  {5,8}};

    signed long int arr2[3][3]=  {{1,3,3},
                                  {1,1,3},
                                  {3,-1,1}};
    int i,j,k;
    signed long int **result;
    result = create_2d_array(2,3);

    for (i=1; i<l2+1 ;i++){//search in the row of columns values for value i
        for (j=0;j<c2;j++){// search every element in columns row for value i
            printf("i=%d before \n",i);
                if (arr2[1][j]== i){// if i found number = i , i need to multiply it with every one in other matrix with the same column
                    printf("i=%d  arr2[1][%d]=%ld \n",i,j,arr2[1][j]);
                    printf("arr2[0][%d]=%ld\n",j,arr2[0][j]);
                    for (k=0;k<c1+1;k++){
                        if(arr1[1][k]==arr2[0][j]){
                            printf("arr1[2][k=%d] =%ld arr1[2][j=%d]=%ld \n",k,arr1[2][k],j,arr2[2][j]);
                            result[arr1[0][k]-1][i-1]= arr1[2][k]*arr2[2][j];
                            printf("result[k=%d][i-1=%d] =%ld \n",k,i-1,result[k][i-1]);
                            }
                    }
                }
            }
    }
print_array(result, 2 ,3);
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
