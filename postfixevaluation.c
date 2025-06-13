#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 30

double compute(char symbol, double op1, double op2) {
    switch (symbol) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^':
        case '$': return pow(op1, op2); // Treating '$' as exponentiation
        default: printf("Invalid operator: %c\n", symbol); exit(1);
    }
}

int main() {
    double s[SIZE], res, op1, op2;
    int top = -1, i;
    char postfix[SIZE], sym;

    printf("Enter a valid postfix expression:\n");
    scanf("%s", postfix);

    for (i = 0; i < strlen(postfix); i++) {
        sym = postfix[i];

        if (isdigit(sym)) {
            s[++top] = sym - '0';
        } else {
            if (top < 1) {  // Validate correct operand count
                printf("Invalid postfix expression\n");
                return 1;
            }
            op2 = s[top--];
            op1 = s[top--];
            res = compute(sym, op1, op2);
            s[++top] = res;
        }
    }

    if (top != 0) {  // Ensure stack contains only one result
        printf("Error: Invalid postfix expression\n");
        return 1;
    }

    printf("The result = %f\n", s[top]);
    return 0;
}

