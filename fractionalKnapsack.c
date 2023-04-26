#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;

    double ratio1 = (double)item1->value / item1->weight;
    double ratio2 = (double)item2->value / item2->weight;

    if (ratio1 < ratio2) {
        return 1;
    }
    else if (ratio1 > ratio2) {
        return -1;
    }
    else {
        return 0;
    }
}

void fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    int current_weight = 0;
    double total_profit = 0.0;
    int selected_items[n]; // to keep track of the selected items
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            total_profit += items[i].value;
            selected_items[index++] = i;
        }
        else {
            int remaining_capacity = capacity - current_weight;
            total_profit += items[i].value * ((double)remaining_capacity / items[i].weight);
            selected_items[index++] = i;
            break;
        }
    }

    printf("Selected items: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", selected_items[i]);
    }
    printf("\nTotal profit: %f\n", total_profit);
}

int main() {
    struct Item items[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    fractionalKnapsack(items, n, capacity);

    return 0;
}



