#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, min_idx, temp, comparisons = 0;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));

    printf("Generated random array: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    start = clock();

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The sorted elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %.6f seconds\n", time_taken);
    printf("Total comparisons: %d\n", comparisons);

    return 0;
}
