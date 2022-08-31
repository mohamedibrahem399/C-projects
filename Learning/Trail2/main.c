#include<stdio.h>
#include<stdlib.h>

int main(){
	int i=0;
    int positive_number,negative_number;
	float p_n_a,n_n_a;
	int numbers [5];

	printf("please enter any 5 normal numbers\n");

	for (i=0;i<5;i++){
		scanf("%d", &numbers[i]);
	}

	for (i=0;i<5;i++){
		printf("%d  ",numbers[i]);
	}


return 0;
}
