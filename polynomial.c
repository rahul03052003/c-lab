#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node **head, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node *temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node *temp = head;
    do {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != head)
            printf(" + ");
    } while (temp != head);
    printf("\n");
}

struct Node* addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *p1 = poly1, *p2 = poly2;

    if (!p1) return p2;
    if (!p2) return p1;

    do {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    } while (p1 != poly1);

    do {

        struct Node *temp = result;
        int found = 0;
        do {
            if (temp->exp == p2->exp) {
                temp->coeff += p2->coeff;
                found = 1;
                break;
            }
            temp = temp->next;
        } while (temp != result);


        if (!found) {
            insertTerm(&result, p2->coeff, p2->exp);
        }

        p2 = p2->next;
    } while (p2 != poly2);

    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, exp, i;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }


    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }


    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);


    sum = addPolynomials(poly1, poly2);
    printf("Sum Polynomial: ");
    display(sum);

    return 0;
}
