#include <stdio.h>

int parent[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// merges the groups of a and b; returns 0 if already same group (cycle)
int unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return 0;
    parent[ra] = rb;
    return 1;
}

// edges[i][0] = u, edges[i][1] = v, edges[i][2] = weight
// sorts idx[] so that edges[idx[0]] has the smallest weight, and so on
void sortEdges(int edges[][3], int idx[], int E) {
    for (int i = 0; i < E - 1; i++) {
        int min = i;
        for (int j = i + 1; j < E; j++)
            if (edges[idx[j]][2] < edges[idx[min]][2])
                min = j;
        int t = idx[i]; idx[i] = idx[min]; idx[min] = t;
    }
}

void kruskal(int V, int E, int edges[][3]) {
    int idx[100];
    for (int i = 0; i < E; i++) idx[i] = i;     // build idx = 0,1,2,...

    sortEdges(edges, idx, E);                   // sort edge numbers by weight

    for (int i = 0; i < V; i++) parent[i] = i;  // DSU init

    int count = 0, total = 0;
    printf("\nEdge\tWeight\n");
    for (int i = 0; i < E && count < V - 1; i++) {
        int e = idx[i];
        if (unite(edges[e][0], edges[e][1])) {
            printf("%d - %d\t%d\n", edges[e][0], edges[e][1], edges[e][2]);
            total += edges[e][2];
            count++;
        }
    }

    if (count != V - 1)
        printf("\nGraph is disconnected. MST not possible.\n");
    else
        printf("\nTotal cost of MST = %d\n", total);
}

int main() {
    int V = 4;
    int edges[][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int E = sizeof(edges) / sizeof(edges[0]);   // number of edges

    kruskal(V, E, edges);
    return 0;
}
