#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACK_SIZE 30
char infix[30],postfix[30];
int sp(char symbol)
{
switch(symbol){
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
int ip(char symbol){
switch(symbol){
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
void infix_to_postfix(){
int top,i,j;
char s[STACK_SIZE],symbol;
top=-1;
s[++top]='#';
j=0;
for(i=0;i<strlen(infix);i++){
symbol=infix[i];
while(sp(s[top])>ip(symbol)){
postfix[j]=s[top--];
j++;
}
if(sp(s[top])!=ip(symbol))
s[++top]=symbol;
else
top--;
}
while(s[top]!='#'){
postfix[j++]=s[top--];
}
postfix[j]='\0';


}
void main(){
printf("Enter a valid infix expression");
scanf("%s",infix);
infix_to_postfix(infix);
        printf("\n%s",postfix);
}
    
                         
