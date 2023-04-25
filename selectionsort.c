#include <stdio.h>

void selectionSort(int arr[], int size);

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, size);  // sort the array using the selection sort algorithm

    printf("The sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// function to perform the selection sort algorithm
void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;

    // loop through the array
    for (i = 0; i < size - 1; i++) {
        minIndex = i;  // assume the current element is the minimum

        // loop through the remaining elements to find the minimum
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // update the minimum index
            }
        }

        // swap the current element with the minimum element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
