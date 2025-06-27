#include<stdio.h>
#include<stdlib.h>
#define size 5

int q[size],f,r,item;
void insertF()
{

if(f==0 && r==-1)
q[++r]=item;
else if(f!=0)
q[--f]=item;
else
printf("Insertion at front end is not possible\n");
}
void insertR(){
if(r==size-1)
printf("Insertion at rear end is not possible\n");
else
q[++r]=item;
}


void deleteR(){
int del_item;
if(r<0 || f>r){
printf("Queue underflow");
return;
}
else{
del_item=q[r];
printf("\n %d",del_item);
r=r-1;
}
if(f>r)
f=0,r=-1;
}

void deleteF(){
int del_item;
if(f>r){
printf("Queue underflow\n");
return;
}
del_item=q[f];
printf("\n%d\n",del_item);
f++;
if(f>r)
f=0,r=-1;
}

void display()
{
  
default:exit(0);
}
}
}
