#include <stdio.h>

// function to swap two elements of the array
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// function to partition the array around a pivot element
int partition(int number[], int low, int high) {
    int pivot = number[high];  // set the pivot element to the last element of the array
    int i = low - 1;  // initialize the index of the smaller element
    for (int j = low; j < high; j++) {  // iterate over the array elements
        if (number[j] <= pivot) {  // if the current element is less than or equal to the pivot element
            i++;  // increment the index of the smaller element
            swap(&number[i], &number[j]);  // swap the current element with the smaller element
        }
    }
    swap(&number[i + 1], &number[high]);  // swap the pivot element with the element at the index of the smaller element
    return i + 1;  // return the index of the pivot element
}

// function to perform the quicksort algorithm
void quicksort(int number[], int low, int high) {
    if (low < high) {  // if there are more than one elements in the subarray
        int pi = partition(number, low, high);  // partition the subarray around a pivot element
        quicksort(number, low, pi - 1);  // recursively sort the left subarray
        quicksort(number, pi + 1, high);  // recursively sort the right subarray
    }
}

int main() {
    int count;
    printf("How many elements do you want to sort? ");
    scanf("%d", &count);

    int number[count];
    printf("Enter %d elements: ", count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &number[i]);
    }

    quicksort(number, 0, count - 1);  // sort the array using the quicksort algorithm

    printf("The sorted elements are: \n");
    for (int i = 0; i < count; i++) {
        printf("%d ", number[i]);
    }
    printf("\n");
    return 0;
}
