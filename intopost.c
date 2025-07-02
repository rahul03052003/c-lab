#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define stack_s 30

char infix[20],postfix[20];
char stack[stack_s];
int top = -1;
int sp(char sym)
{
    switch(sym){
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '^':
        case '$':return 5;
        case '(':return 0;
        case '#':return -1;
        default:return 8;
    }
}

int ip(char sym){
    switch(sym){
    case '+':
    case '-':return 1;
    case '*':
    case '/':return 3;
    case '^':
    case '$':return 6;
    case '(':return 9;
    case ')':return 0;
    default:return 7;
    }
}

void convertToPostfix() {
    int i = 0, j = 0;
    char sym, tos;

    stack[++top] = '#';
    while ((sym = infix[i++]) != '\0') {
        tos = stack[top];

        while (sp(tos) > ip(sym)) {
            postfix[j++] = stack[top--];
            tos = stack[top];
        }
        if (sp(tos) != ip(sym)) {
            stack[++top] = sym;
        } else {
            top--;
        }
    }
    while (stack[top] != '#') {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main() {
    printf("Enter a valid infix expression:\n");
    scanf("%s", infix);
    convertToPostfix();
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
