#include<stdio.h>
#include<stdlib.h>


int main(){
    int commission_base[9][3];
    int cond=0;
    int salary;
    // setting my main array with filling it's 3rd column with zeros;

    int i,temp,temp2,temp3;
    temp =200;
    for (i=0;i<9;i++)
    {
    commission_base[i][2] = 0;
    }
//
temp3=200;
    while (cond!=-1){
        printf("Enter Employee gross sale (-1 to end) : ");
        scanf("%d",&temp2);
        if(temp2==-1){
            cond=-1;
            break;
        }
        salary = 200 + (9 * temp2)/100;
        printf("Employee salary is %d\n", salary);
        for (i=0;i<9;i++){
            if( temp3+99 > salary &&  salary >= temp3){
                commission_base[i][2] =  commission_base[i][2] +1;
                printf("commission_base[%d][2]=%d\n",i,commission_base[i][2]);
                i=9;
            }
            else if (salary >= 1000 ){
                i=8;
                commission_base[i][2] =  commission_base[i][2] +1;
                printf("commission_base[%d][2]=%d\n",i,commission_base[i][2]);
            }

            temp3 = temp3+100;
        }
    temp3=200;
    }
    //setting the final shape and printing it;
    for (i=0;i<9;i++)
    {
        commission_base[i][0] = temp;
        temp = temp + 99;
        printf("%d",commission_base[i][0]);
        if(temp<1000)
            {
            commission_base[i][1] = temp;
            temp = temp + 1;
            printf("       %d  ",commission_base[i][1]);
            }
        else
            printf (" and more  ");
    printf(" %d \n",commission_base[i][2]);
    }

    return 0;
}
