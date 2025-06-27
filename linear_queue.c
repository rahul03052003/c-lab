#include<stdio.h>
#include<stdlib.h>
#define size 4
int item,q[size],f,r;
void enqueue(){
if(r==size){
printf("Queue full\n");
return;
}else{
r=r+1;
q[r]=item;
}
}
void dequeue(){
int del_item;
if(f>r){
printf("Queue undeflow\n");
return;
}else{
del_item=q[f];
printf("\n%d",del_item);
f=f+1;
}
if(f>r){
f=0;
r=-1;
}
}
void display(){
int i;
if(f>r){
printf("Queue is undeflow\n");
return;
}
for(i=f;i<=r;i++){
printf("Queue[%d]=%d\n",i,q[i]);
}
}
void main(){
int ch;
f=0;
r=-1;
for(;;){
printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter the choice\n");
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

default:
exit(0);
}
}
}


