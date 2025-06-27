#include<stdio.h>
#include<stdlib.h>
#define size 4
int item,q[size],f,r,c;
void enqueue(){
if(c==size){
printf("Queue full\n");
return;
}
else{
r=(r+1)%size;
q[r]=item;
c=c+1;
}
}
void dequeue(){
int del_item;
if(c==0){
printf("Queue empty\n");
return;
}
else{
del_item=q[f];
printf("\n %d",del_item);
f=(f+1)%size;
c=c-1;
}
}
void display(){
int i,j;
if(c==0){
printf("Queue is empty\n");
return;
}
f=0;
printf("Queue:\t");
i=f;
for(j=1;j<=c;j++){
printf("%d\t",q[i]);
i=(i+1)%size;
}
}
void main()
{
int ch;
f=0;
r=-1;
c=0;
for(;;){
printf("\nCircular queue\n1.Enqueue\n2.Dequeue\n3.Display\n4Exit\nEnter the choice\n");
scanf("%d",&ch);
switch(ch){
case 1:
printf("Enter the item to be inserted\n");
scanf("%d",&item);
enqueue();
break;

case 2:dequeue();
break;

case 3:display();
break;

default:exit(0);
}
}
}


