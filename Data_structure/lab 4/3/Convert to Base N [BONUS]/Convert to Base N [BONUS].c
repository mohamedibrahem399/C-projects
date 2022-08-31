#include <stdio.h>
#include <stdlib.h>

int convert(long int number, int base);
int i=0;
char s[1000];

int main()
{
    long int number;
    int base;
    scanf("%ld %d",&number,&base);
    if (base < 2 || base > 16){
        return 0;
    }
    int f_value;
    f_value=convert(number,base);
    int j;
    int temp;
    //reverse
    int i2 = i/2;

    if (i>1){
        i=i-1;
        for(j=0;j<i2;j++){
            temp= s[j];
            s[j]=s[i];
            s[i]=temp;
            i--;
        }
    }
    printf("%s",s);
    return 0;
}

int convert(long int number, int base){

    long int mod,value;
    value = number;
    int p;
    if(number >= base){
        mod= number%base;
        value = number/base;
        number = value;
        if(mod <= 9){
            p = mod + 48;
            s[i]= (char) p;
        }
        else if (mod > 9){
            p = mod +55;
            s[i]= (char) p;
        }

        i++;
    }
    if( value < base){
            if(value <= 9){
                p = value + 48;
                s[i]= (char) p;
            }
            else if (value > 9){
                p = value +55;
                s[i]= (char) p;
            }
            i++;
    }
    else if(value >= base){
         return convert(value ,base);
    }
    return 0;
}
