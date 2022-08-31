#include <stdio.h>
#include <stdlib.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int arr[], int start, int end) {
  int pivot = arr[end];
  int p_index = (start - 1);
  int j;
  for ( j = start; j < end; j++) {
    if (arr[j] <= pivot) {
      p_index++;
      swap(&arr[p_index], &arr[j]);
    }
  }
  swap(&arr[p_index + 1], &arr[end]);
  return (p_index + 1);
}

void quickSort(int arr[], int start, int end) {
  if (start < end) {
    int p_index = partition(arr, start, end);
    quickSort(arr, start, p_index - 1);
    quickSort(arr, p_index + 1, end);
  }
}

int main()
{
    int elements_number; // 10 ^4

    scanf("%d",&elements_number);
    int *arr = malloc (elements_number * sizeof(int) ); // -10^9 to 10^9-1

    int i;
    for (i=0; i <elements_number ; i++){
        scanf("%d",&arr[i]);
    }
    int start = 0;
    int end = elements_number - 1;

    quickSort(arr , start , end);

    printf("\n");

    for (i=0; i <elements_number ; i++){
        printf("%d\n",arr[i]);
    }


    return 0;
}
