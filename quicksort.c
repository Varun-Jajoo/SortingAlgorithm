#include <stdio.h>

// This is a function that sorts an array of numbers using the quicksort algorithm.
// It takes in an array of integers, the index of the first element, and the index of the last element.
void quicksort(int number[], int first, int last) {
    int i, j, pivot, temp;
    if (first < last) { // If the lower bound is less than the upper bound
        pivot = first; // Choose the first element as the pivot
        i = first;
        j = last;
        while (i < j) { // While the left index is less than the right index
            while (number[i] <= number[pivot] && i < last) { // Move the left index until a number greater than the pivot is found
                i++;
            }
            while (number[j] > number[pivot]) { // Move the right index until a number less than or equal to the pivot is found
                j--;
            }
            if (i < j) { // If the left index is still less than the right index
                temp = number[i]; // Swap the numbers at the left and right indices
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot]; // Swap the pivot element with the element at the right index
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1); // Recursively sort the left subarray
        quicksort(number, j + 1, last); // Recursively sort the right subarray
    }
}

int main() {
    int i, count, number[25];
    printf("How many elements do you want?\n");
    scanf("%d", &count); // Get the number of elements from the user
    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++) {
        scanf("%d", &number[i]); // Get each element from the user
    }
    quicksort(number, 0, count - 1); // Sort the array
    printf("Order of sorted elements: ");
    for (i = 0; i < count; i++) {
        printf("%d ", number[i]); // Print the sorted array
    }
    printf("\n");
    return 0;
}
