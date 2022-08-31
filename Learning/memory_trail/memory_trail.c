#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers_count;
    scanf("%d",&numbers_count);


  	int *temp= malloc(numbers_count *sizeof(int));
  	printf("%d\n",temp);

  	int i;
  	for(i=0;i<numbers_count;i++){
        scanf("%d",(temp+i));
  	}
  	for(i=0;i<numbers_count;i++){
        printf("  %d\n",*(temp+i) );
  	}

  	//int *temp= calloc(numbers_count,sizeof(int));

/*
  	int i=0;
  	int k,j,n=1;
  	int f=numbers_count;
  	for(i=0;i<numbers_count;i++){
        scanf("%d",&temp[i]);
  	}

  	for(i=0;i<f;i++){
        for(k=n;k<f;k++){
            if (temp[i]==temp[k]){
                for(j=k;j<f;j++){
                    if(j<f-1)
                        temp[j]=temp[j+1];

                }
                temp = realloc(temp,f*sizeof(int));
                printf( "size of temp = %d\n", sizeof(temp));
                f--;
            }
        }
        n++;
    }

    printf("after modulation\n");
    for(i=0;i<6;i++){
        printf("%d \n",temp[i]);
        }
    printf("\n");

*/
    return 0;
}
