#include <stdio.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    
    // Traverse through all elements in the array
    for (i = 0; i < n-1; i++) {
        min_idx = i; // Assume the first element as the minimum
        
        // Find the minimum element in the remaining unsorted array
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update the minimum index
            }
        }
        
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        
        // Print the array after every pass
        printf("Pass %d: ", i+1);
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); // Input the number of elements
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Input the array elements
    }
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the original array
    }
    printf("\n");
    
    selectionSort(arr, n); // Call selectionSort function to sort the array
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the sorted array
    }
    printf("\n");
    
    return 0;
}
