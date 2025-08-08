#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, key, comparisons = 0;
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

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
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
