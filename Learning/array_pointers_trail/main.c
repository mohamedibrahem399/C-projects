#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[2][2];
    int *p[2];
    p[0]= &x[0][0];
    p[1]= &x[1][0];
    int i,j;


    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",(*(p+i)+j));
        }
    }

/*
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d ",*(*(p+i)+&j));
        }
        printf("\n");
    }

*/
    return 0;
}
