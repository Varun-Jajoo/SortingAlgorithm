#include <stdio.h>

// function to merge two sorted subarrays into a single sorted subarray
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    // compare elements from the left and right subarrays and merge them into a single sorted subarray
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // copy any remaining elements from the left subarray into the merged subarray
    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    // copy any remaining elements from the right subarray into the merged subarray
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

// function to perform the merge sort algorithm
void mergeSort(int arr[], int size) {
    if (size < 2) {  // if the size of the array is less than 2, it is already sorted
        return;
    }

    int mid = size / 2;

    int left[mid];  // create a new array to store the left subarray
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    int right[size - mid];  // create a new array to store the right subarray
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);  // recursively sort the left subarray
    mergeSort(right, size - mid);  // recursively sort the right subarray

    merge(arr, left, mid, right, size - mid);  // merge the sorted left and right subarrays into a single sorted subarray
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, size);  // sort the array using the merge sort algorithm

    printf("The sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
