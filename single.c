#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insertRear(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = front;

    front = newNode;
    if (rear == NULL) {
        rear = front;
    }
}

void deleteFront() {
    if (front == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }
}

void deleteRear() {
    if (rear == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    struct Node* temp = front;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    free(temp);

    if (prev == NULL) {
        front = rear = NULL;
    } else {
        prev->next = NULL;
        rear = prev;
    }
}

void deleteByValue(int value) {
    if (front == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }

    struct Node* temp = front;
    struct Node* prev = NULL;

    if (temp->data == value) {
        front = front->next;
        free(temp);
        if (front == NULL) rear = NULL;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    if (temp->next == NULL) rear = prev;
    free(temp);
}

void traverse() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Rear\n2. Insert at Front\n3. Delete from Front\n4. Delete from Rear\n5. Delete by Value\n6. Traverse\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 6:
                traverse();
                break;
            case 7:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}




o/p

  vi single.c
[imca34@mcafc15 ~]$ cc single.c
[imca34@mcafc15 ~]$ ./a.out

Menu:
1. Insert at Rear
2. Insert at Front
3. Delete from Front
4. Delete from Rear
5. Delete by Value
6. Traverse
7. Exit
Enter your choice: 1
Enter value to insert at rear: 10

Menu:
1. Insert at Rear
2. Insert at Front
3. Delete from Front
4. Delete from Rear
5. Delete by Value
6. Traverse
7. Exit
Enter your choice: 1
Enter value to insert at rear: 20

Menu:
1. Insert at Rear
2. Insert at Front
3. Delete from Front
4. Delete from Rear
5. Delete by Value
6. Traverse
7. Exit
Enter your choice: 5
Enter value to delete: 20

Menu:
1. Insert at Rear
2. Insert at Front
3. Delete from Front
4. Delete from Rear
5. Delete by Value
6. Traverse
7. Exit
Enter your choice: 6
10 -> NULL

Menu:
1. Insert at Rear
2. Insert at Front
3. Delete from Front
4. Delete from Rear
5. Delete by Value
6. Traverse
7. Exit
Enter your choice: 7
Exiting program...
[imca34@mcafc15 ~]$ vi single.c
[imca34@mcafc15 ~]$

