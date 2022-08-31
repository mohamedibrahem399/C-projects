signed long int **create_2d_array (int rows , int columns);
void print_array (signed long int **arr, int n , int l);
int count_elements (signed long int **arr, int n , int l);
signed long int **convert_array (signed long int **arr, int n , int l, int c1);




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
