// C++ program for implementation of Heap Sort
#include <stdio.h>
#include <stdlib.h>

//using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap

void swap (int *a1 ,int *a2 ){
signed long int temp = *a1;
*a1 = *a2 ;
*a2 = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    int i;
    // Build heap (rearrange array)
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf( "%d\n",arr[i]);

}

// Driver code
int main()
{
   /* int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
*/
    int i;
    int elements_number;
    scanf("%d",&elements_number);
    int data;
    int *arr = (int*) malloc(elements_number * sizeof(int));
    for(i=0;i<elements_number ; i++){
        scanf("%d",&data);
        arr[i] = data;
    }

    heapSort(arr, elements_number);

    printf ( "Sorted array is \n");
    printArray(arr, elements_number);
    return 0;
}
