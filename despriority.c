#include <stdio.h>
#define Q_size 5

int q[Q_size], f = 0, r = -1, item;

void denqueue() {
    if (r >= Q_size - 1) {
        printf("Queue overflow\n");
        return;
    }
    int j = r;
    while (j >= f && item > q[j]) {
        q[j + 1] = q[j];
        j--;
    }
    q[j + 1] = item;
    r++;
}

void display() {
    int i;
    if (f > r) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    for (i = f; i <= r; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n--- Descending Priority Queue ---\n");
        printf("1. Insert\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                denqueue();
                break;
            case 2:
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
