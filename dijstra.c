#include<stdio.h>
#include<stdlib.h>
#define max 10
#define  inf 9999
int n;

int cost[max][max];
void dij(int start){
int d[max],v[max],i,j,min,u;
for(i=0;i<n;i++){
d[i]=cost[start][i];
v[i]=0;
}
d[start];
v[start]=1;
for(i=1;i<n;i++){
min=inf;
u=-1;
for(j=0;j<n;j++){
if(!v[j] && d[j]<min){
min=d[j];
u=j;
}
}
if(u==-1)break;
v[u]=1;
for(j=0;j<n;j++){
if(!v[j] && d[u]+cost[u][j]<d[j]){
d[j]=d[u]+cost[u][j];
}
}
}
printf("Vertex Distance from source %d\n",start);

for(i=0;i<n;i++){
printf("Vertex %d: Distance =%d\n",i,d[i]);
}
}
int main()
{
int i,j,start;
printf("Number of vertices:\n");
scanf("%d",&n);
printf("Cost matrix:\n");

for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&cost[i][j]);
}
}

printf("Source vertex:(0 to %d)\n",n-1);
scanf("%d",&start);
dij(start);
return 0;
}

o/p
  Number of vertices:
4
Cost matrix:
0 5 9999 10
9999 0 3 9999
9999 9999 0 1
9999 9999 9999 0
Source vertex:(0 to 3)
0
Vertex Distance from source 0
Vertex 0: Distance =0
Vertex 1: Distance =5
Vertex 2: Distance =8
Vertex 3: Distance =9
