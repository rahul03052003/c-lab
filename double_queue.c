#include<stdio.h>
#include<stdlib.h>
#define size 5

int q[size], f = 0, r = -1, item;

void insertF() {
    if (f == 0 && r == -1) {  // Empty queue
        q[++r] = item;
    }
    else if (f != 0) {  // Space available at front
        q[--f] = item;
    }
    else {
        printf("Insertion at front end is not possible\n");
    }
}

void insertR() {
    if (r == size - 1) {
        printf("Insertion at rear end is not possible\n");
    }
    else {
        q[++r] = item;
    }
}

void deleteR() {
    int del_item;
    if (r < 0 || f > r) {
        printf("Queue underflow");
        return;
    }
    else {
        del_item = q[r];
        printf("\n %d", del_item);
        r = r - 1;
    }
    if (f > r)  // Reset when queue becomes empty
        f = 0, r = -1;
}

void deleteF() {
    int del_item;
    if (f > r) {
        printf("Queue underflow\n");
        return;
    }
    del_item = q[f];
    printf("\n%d\n", del_item);
    f++;
    if (f > r)  
        f = 0, r = -1;
}

void display() {
    if (f > r) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = f; i <= r; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &item);
                insertF();
                break;
            case 2:
                printf("Enter item to insert at rear: ");
                scanf("%d", &item);
                insertR();
                break;
            case 3:
                deleteF();
                break;
            case 4:
                deleteR();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
