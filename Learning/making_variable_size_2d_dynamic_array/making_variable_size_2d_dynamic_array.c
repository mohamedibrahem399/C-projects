#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,j, n , l;
    printf("enter the dimension of the first 2d array\n");
    scanf("%d %d",&n,&l);

    int **arr1= malloc(n * sizeof(int *));

    for (i=0; i<n ; i++){
        arr1[i] = malloc(l * sizeof(int));
    }


    for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){

            *(*(arr1+i)+j) = j;
        }

    }


    for(i=0; i<n ; i++){
        for(j=0; j<l ; j++){

            printf("arr1 of [%d] [%d] = %d \n",i,j, *(*(arr1+i)+j)  );
        }
    }

    return 0;
}
