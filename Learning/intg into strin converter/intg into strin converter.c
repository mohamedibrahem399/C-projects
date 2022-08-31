#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in,temp;
    int test=0;
    int counter=1;
    int i;

    scanf("%d",&in);
    temp=in;

    while (test==0){
        if(temp/10 !=0){
                temp=temp/10;
                counter++;
    }
    else
        test=1;
   }
    printf("number of digits in in = %d\n",counter);

    char *charValue =   calloc(counter,sizeof(char));
    itoa(in,charValue,10);

    for (i=0;i<counter;i++){
            printf("c[%d]= %c \n",i,charValue[i]);
    }


    if(  charValue[counter-1] ==  charValue [0]){
        printf("yes\n");
    }



    return 0;
}
