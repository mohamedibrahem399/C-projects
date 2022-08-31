#include<stdio.h>
#include<stdlib.h>
int count_positive(float number[5]);
int count_negative(float number[5]);

float average_of_positives (float number[5],int s);
float average_of_negatives (float number[5],int s);

int main(){
	int i,positive_number,negative_number;
	float p_n_a,n_n_a;
	float numbers [5];

	printf("please enter any 5 normal numbers\n");

	for (i=0;i<5;i++){
		scanf("%f", &numbers[i]);
	}

    positive_number = count_positive(&numbers[0]);
    negative_number = count_negative(&numbers[0]);

    printf("positive numbers are %d \n",positive_number);
    printf("negative numbers are %d \n",negative_number);

    p_n_a = average_of_positives(numbers,positive_number);

    printf("%f\n",p_n_a);

    n_n_a = average_of_negatives(numbers,negative_number);
    printf("%f\n",n_n_a);


	return 0;
}


int count_negative(float number[5]){
int negative_numbers =0;
int i;
    for (i=0; i<5;i++){
        if( number[i]<0 ){
            negative_numbers++;
        }
        else
        {
            negative_numbers=negative_numbers;
        }
    }
return negative_numbers;
}


int count_positive(float number[5]){
int positive_numbers =0;
int i;
    for (i=0; i<5;i++){
        if( number[i]>0 ){
            positive_numbers++;
        }
        else
        {
            positive_numbers=positive_numbers;
        }
    }
return positive_numbers;
}

float average_of_positives (float number[5],int s)
{
    int i;
    float p_a=0;

    for (i=0;i<5;i++){
        if (*(number+i)>0)
            p_a = p_a + number[i];
    }
    p_a = p_a / s;
    return p_a;
}


float average_of_negatives (float number[5],int s)
{
    int i;
    float n_a=0;

    for (i=0;i<5;i++){
        if (number[i]<0)
            n_a = n_a + number[i];
    }
    n_a = n_a / s;
    return n_a;
}


