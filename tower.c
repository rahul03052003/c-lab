#include<stdio.h>
void  tower(int n,char s,char t,char d)
{
if(n==1){
printf("Move %d from %c to %c\n",n,s,d);
return;
}
tower(n-1,s,d,t);
printf("Move disc %d from %c to %c\n",n,s,d);
tower(n-1,t,s,d);
}
void main()
{
int n;
printf("Enter the no of disc\n");
scanf("%d",&n);
tower(n,'S','T','D');
}
~
