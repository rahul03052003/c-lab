#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, temp, comparisons = 0;
    clock_t start, end;
    double time_taken;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Seed random number generator
    srand(time(NULL));

    // Generate random array
    printf("Generated random array: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; // Random numbers between 1 and 100
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Start timing
    start = clock();

    // Bubble Sort with comparison count
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // End timing
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Display sorted array
    printf("The sorted elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Display time and comparisons
    printf("Time taken: %.6f seconds\n", time_taken);
    printf("Total comparisons: %d\n", comparisons);

    return 0;
}
