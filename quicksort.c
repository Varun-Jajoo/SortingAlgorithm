#include <stdio.h>

int num_calls = 0;

void quicksort(int number[], int first, int last)
{
    int i, j, pivot, temp;
    num_calls++; // Incrementing number of calls
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
            {
                i++;
            }
            while (number[j] > number[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main()
{
    int i, count, number[25];
    printf("How many elements do you want? ");
    scanf("%d", &count);
    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++)
    {
        scanf("%d", &number[i]);
    }
    quicksort(number, 0, count - 1);
    printf("Order of sorted elements is:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", number[i]);
    }
    printf("\nNumber of calls to quicksort procedure: %d\n", num_calls);
    return 0;
}
