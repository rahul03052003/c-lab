#include <stdio.h>
#include <stdlib.h>
#define max 100

int visited[max], adj[max][max], n;
int queue[max], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == max - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

void initial(int vertices) {
    int i, j;
    n = vertices;
    for (i = 0; i < max; i++) {
        visited[i] = 0;
        for (j = 0; j < max; j++) {
            adj[i][j] = 0;
        }
    }
}

void addE(int start, int end) {
    adj[start][end] = 1;
    adj[end][start] = 1;
}

void bfs(int startv) {
    int i;
    enqueue(startv);
    visited[startv] = 1;
    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("Visited %d\n", current);
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges, startv, start, end, i;

    printf("Vertex and edges:\n");
    scanf("%d %d", &vertices, &edges);
    initial(vertices);

    printf("Edges:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        addE(start, end);
    }

    printf("Starting for BFS: ");
    scanf("%d", &startv);
    printf("BFS from vertex %d\n", startv);
    bfs(startv);

    return 0;
}




o/p

  
Vertex and edges:
5 6
Edges:
0 1
0 2
1 3
1 4
2 4
3 4
Starting for BFS: 0
BFS from vertex 0
Visited 0
Visited 1
Visited 2
Visited 3
Visited 4
[imca34@mcaf
