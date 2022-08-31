#include<stdio.h>
#include<stdlib.h>

int main (){

int m1[3][3] ={ {0} } ;
int *p11[3] ;
/*
// we need to make this so we made this by using the same for loop instead of making it alone at first
p11[0] = &m1[0][0];
p11[1] = &m1[1][0];
p11[2] = &m1[2][0];
*/

int m2[3][3],result[3][3];
int *p12[3];
int i,j;

printf("write 1st matrix elements please : \n");

for(i=0;i<3;i++){
        p11[i] = &m1[i][0];
    for(j=0;j<3;j++){
        scanf("%d", (*(p11+i)+j) );
    }
  }

printf("write 2nd matrix elements please : \n");
for(i=0;i<3;i++){
        p12[i] = &m2[i][0];
    for(j=0;j<3;j++){
        scanf("%d", (*(p12+i)+j) );
    }
  }

for(i=0;i<3;i++){
        p12[i] = &m2[i][0];
    for(j=0;j<3;j++){
       *(*(result+i)+j) = *(*(p11+i)+j) + *(*(p12+i)+j) ;
    }
  }



printf("the 1st matrix elements are : \n");
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d  ", *(*(p11+i)+j) );
    }
    printf("\n");

  }

  printf("the 2nd matrix elements are : \n");
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d  ", *(*(p12+i)+j) );
    }
    printf("\n");

  }


  printf("the result matrix elements are : \n");
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d  ", *(*(result+i)+j) );
    }
    printf("\n");

  }

return 0;
}
