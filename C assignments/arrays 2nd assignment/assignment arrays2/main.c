#include <stdio.h>
#include <stdlib.h>
//check_and_put(checked array , new array)

void fill_array(int *arr);
void check_and_put(int *arr1 , int *arr2);
void fill_p_with_arr(int *arr3 , int*p);
void print_array(int *arr6);

int main()
{
    int grid0 [8][8]={0,0};
    int grid1 [8][8]={0,0};
    int grid2 [8][8]={0,0};
    int grid3 [8][8]={0,0};
    fill_array(grid0);

    check_and_put(grid0,grid1);
    check_and_put(grid1,grid2);
    check_and_put(grid2,grid3);



    printf("   grid0 :\n");
    print_array(grid0);

    printf("\n   grid1 :\n");
    print_array(grid1);

    printf("\n   grid2 :\n");
    print_array(grid2);

    printf("\n   grid3 :\n");
    print_array(grid3);



    return 0;
}


void fill_array(int *arr)
{
    int help_arr[8][8]={0,0};
    int i=0;int j=0;int k=0;int h=0;
    printf("please enter the array elements value as 1 or 0\n");
     for (i=1;i<=6;i++)
    {
        for (j=1;j<=6;j++)
        {
            printf("now you should enter the value of element [%d][%d]=",i,j);
            scanf("%d",&help_arr[i][j]);
            if(help_arr[i][j]!=0 && help_arr[i][j]!=1)
            {
                while(i){
                    printf("please enter the element [%d][%d] again as a number of 1 or 0 =",i,j);
                    scanf("%d",&help_arr[i][j]);
                    if(help_arr[i][j]==0 || help_arr[i][j]==1) break;
                }
            }
        }

    }

    fill_p_with_arr(&help_arr[0][0],arr);

}


void fill_p_with_arr(int *arr3, int *p)
{
    int i=0;int j=0;int k=0;int h=0;

    for(i=1;i<=6;i++){
        k=8*i+1;
        for (j=k;j<=(k+5);j++)
        {
        h=j-k+1;
        arr3+=j;
        p+=j;
        *p=*arr3;
        arr3-=j;
        p-=j;

        }
    }
}

void check_and_put(int *arr1 , int *arr2)
{
    int help_arr1[8][8]={0,0};
    int help_arr2[8][8]={0,0};
    int i=0;int j=0;int k=0;int h=0;int counter=0;

    fill_p_with_arr(arr1,&help_arr1[0][0]);

    for(i=1;i<=6;i++){
        for (j=1;j<=6;j++)
        {
        counter=0;
        if(help_arr1[i][j]==1){
            if(help_arr1[i][j+1]==1)counter+=1;
            if(help_arr1[i][j-1]==1)counter+=1;

            if(help_arr1[i+1][j]==1)counter+=1;
            if(help_arr1[i+1][j+1]==1)counter+=1;
            if(help_arr1[i+1][j-1]==1)counter+=1;

            if(help_arr1[i-1][j]==1)counter+=1;
            if(help_arr1[i-1][j+1]==1)counter+=1;
            if(help_arr1[i-1][j-1]==1)counter+=1;

            if (counter==3 || counter ==2){help_arr2[i][j]=1;}
            }

        else if(help_arr1[i][j]==0){
            if(help_arr1[i][j+1]==1)counter+=1;
            if(help_arr1[i][j-1]==1)counter+=1;

            if(help_arr1[i+1][j]==1)counter+=1;
            if(help_arr1[i+1][j+1]==1)counter+=1;
            if(help_arr1[i+1][j-1]==1)counter+=1;

            if(help_arr1[i-1][j]==1)counter+=1;
            if(help_arr1[i-1][j+1]==1)counter+=1;
            if(help_arr1[i-1][j-1]==1)counter+=1;

            if (counter==3)help_arr2[i][j]=1;
            }
        counter=0;
        }
    }

    fill_p_with_arr(&help_arr2[0][0],arr2);
}


void print_array(int *arr6)
{
    int i=0;int j=0;
    int help_arr6 [8][8]={0,0};
    fill_p_with_arr(arr6,&help_arr6[0][0]);
    for (i=0;i<=7;i++)
    {
        for (j=0;j<=7;j++)
        {
            printf("[%d] ",help_arr6[i][j]);

        }
        printf("\n");

    }

}
