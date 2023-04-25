#include <stdio.h>

void insertionSort(int arr[], int size);

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, size);  // sort the array using the insertion sort algorithm

    printf("The sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// function to perform the insertion sort algorithm
void insertionSort(int arr[], int size) {
    int i, j, key;

    // loop through the array starting from the second element
    for (i = 1; i < size; i++) {
        key = arr[i];  // store the current element in a variable

        // move all elements greater than the current element one position to the right
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;  // insert the current element into the correct position
    }
}
