#include<stdio.h>
#include<stdlib.h>
#define max 100
int visited[max],adj[max][max],n,stack[max],top=-1;

void push(int value){
stack[++top]=value;
}
int pop()
{
return stack[top--];
}
int isstackE()
{
return top==-1;
}

void initial(int vertices){
int i,j;
n=vertices;

for(i=0;i<max;i++){
visited[i]=0;
for(j=0;j<max;j++){
adj[i][j]=0;
}
}
}
void addE(int start,int end)
{
adj[start][end]=1;
adj[end][start]=1;
}

void dfss(int startv){
int i;
push(startv);
while(!isstackE()){
int current=pop();
if(!visited[current]){
printf("Visited %d\n",current);
visited[current]=1;
for(i=n-1;i>=0;i--){
if(adj[current][i]==1 && !visited[i]){
push(i);
}
}
}
}
}
int main(){
int vertices,edges,startv,start,end,i;

printf("Vertex and edgs:\n");
scanf("%d %d",&vertices,&edges);
initial(vertices);
printf("Edges:\n");
for(i=0;i<edges;i++){
scanf("%d %d",&start,&end);
addE(start,end);
}
printf("Starting for dfs:");
scanf("%d",&startv);
printf("Dfs from vertex %d",startv);
dfss(startv);
return 0;
}


o/p
  Vertex and edgs:
5 6
Edges:
0 1
0 2
1 3
1 4
2 4
3 4
Starting for dfs:0
Dfs from vertex 0Visited 0
Visited 1
Visited 3
Visited 4
Visited 2
