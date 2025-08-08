#include <stdio.h>
#define MAX 100

int parent[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB)
        parent[rootB] = rootA;
}

void sortEdges(int edges[][3], int E) {
    int i, j;
    for (i = 0; i < E - 1; i++) {
        for (j = i + 1; j < E; j++) {
            if (edges[i][2] > edges[j][2]) {
                int temp0 = edges[i][0];
                int temp1 = edges[i][1];
                int temp2 = edges[i][2];

                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];

                edges[j][0] = temp0;
                edges[j][1] = temp1;
                edges[j][2] = temp2;
            }
        }
    }
}

int main() {
    int V, E;
    int edges[MAX][3];
    int mst[MAX][3];
    int total = 0;
    int i, count;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    for (i = 0; i < V; i++)
        parent[i] = i;

    sortEdges(edges, E);

    count = 0;
    for (i = 0; i < E && count < V - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (find(u) != find(v)) {
            unionSets(u, v);
            mst[count][0] = u;
            mst[count][1] = v;
            mst[count][2] = w;
            total += w;
            count++;
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < count; i++) {
        printf("%d -- %d == %d\n", mst[i][0], mst[i][1], mst[i][2]);
    }
    printf("Total weight: %d\n", total);

    return 0;
}


o/p


  Enter number of vertices and edges: 4 5
Enter edges (u v weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Minimum Spanning Tree:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Total weight: 19

