#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char c;
    char s[100] ;

    char s1[100];
    scanf("%c",&c);

    scanf("%s",&s);
    scanf("\n");
    scanf("%[^\n]%*c",&s1);

    printf("%c\n",c);
    printf("%s\n",s);

    printf("%s\n",s1);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
