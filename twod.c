#include <stdio.h>

int main() {
    int a[10][10], rows, cols, i, j, r, c, val, ch = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d", &a[i][j]);
        }
    }

    while(ch != 4){
        printf("\nMenu\n1. Display\n2. Insertion\n3. Deletion\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        if(ch == 1){
            printf("Elements in 2D array:\n");
            for(i = 0; i < rows; i++){
                for(j = 0; j < cols; j++){
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
        }
        else if(ch == 2){
            printf("Enter row and column position to insert (0-based index): ");
            scanf("%d%d", &r, &c);
            if(r >= 0 && r < rows && c >= 0 && c < cols){
                printf("Enter value to insert: ");
                scanf("%d", &val);
                a[r][c] = val;
                printf("Value inserted successfully!\n");
            } else {
                printf("Invalid position!\n");
            }
        }
        else if(ch == 3){
            printf("Enter row and column position to delete (0-based index): ");
            scanf("%d%d", &r, &c);
            if(r >= 0 && r < rows && c >= 0 && c < cols){
                a[r][c] = 0;
                printf("Value deleted (set to 0) successfully!\n");
            } else {
                printf("Invalid position!\n");
            }
        }
        else if(ch == 4){
            printf("Exiting program...\n");
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

