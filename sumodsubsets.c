#include <stdio.h>

int sum_of_subset_calls = 0;

void sum_of_subset(int set[], int subset[], int n, int m, int sum, int current_index, int *found) {
    sum_of_subset_calls++;

    if (sum == m) {
        *found = 1;
        printf("Subset found: ");
        for (int i = 0; i < current_index; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }
    else if (sum > m || current_index == n) {
        return;
    }
    else {
        subset[current_index] = set[current_index];
        sum_of_subset(set, subset, n, m, sum + set[current_index], current_index + 1, found);

        subset[current_index] = 0;
        sum_of_subset(set, subset, n, m, sum, current_index + 1, found);
    }
}

int main() {
    int set[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(set) / sizeof(set[0]);
    int subset[n];
    int sum = 0;
    int m = 7;
    int found = 0;

    sum_of_subset(set, subset, n, m, sum, 0, &found);

    if (!found) {
        printf("No subset found with the given sum\n");
    }

    printf("Total number of calls to sum_of_subset procedure: %d\n", sum_of_subset_calls);

    return 0;
}
