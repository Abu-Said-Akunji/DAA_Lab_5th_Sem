#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Edge_3
{
    int src, dest, weight_3;
} Edge_3;

typedef struct Graph_3
{
    int V_3, E_3;
    Edge_3 *edge_3;
} Graph_3;

Graph_3 *createGraph_3(int V_3, int E_3)
{
    Graph_3 *graph_3 = (Graph_3 *)malloc(sizeof(Graph_3));
    graph_3->V_3 = V_3;
    graph_3->E_3 = E_3;
    graph_3->edge_3 = (Edge_3 *)malloc(E_3 * sizeof(Edge_3));
    return graph_3;
}

int find(int parent_3[], int i)
{
    if (parent_3[i] == i)
        return i;
    return find(parent_3, parent_3[i]);
}

void unionSets(int parent_3[], int x, int y)
{
    int xset_3 = find(parent_3, x);
    int yset_3 = find(parent_3, y);
    parent_3[xset_3] = yset_3;
}

int compareEdge_3s(const void *a, const void *b)
{
    return ((Edge_3 *)a)->weight_3 - ((Edge_3 *)b)->weight_3;
}

void kruskalMST(Graph_3 *graph_3)
{
    int V_3 = graph_3->V_3;
    Edge_3 result[V_3];
    int e = 0;
    int i = 0;

    qsort(graph_3->edge_3, graph_3->E_3, sizeof(graph_3->edge_3[0]), compareEdge_3s);

    int parent_3[V_3];
    for (int v = 0; v < V_3; v++)
        parent_3[v] = v;

    while (e < V_3 - 1 && i < graph_3->E_3)
    {
        Edge_3 next_edge_3 = graph_3->edge_3[i++];
        int x = find(parent_3, next_edge_3.src);
        int y = find(parent_3, next_edge_3.dest);

        if (x != y)
        {
            result[e++] = next_edge_3;
            unionSets(parent_3, x, y);
        }
    }

    printf("Edge_3\n");
    int totalWeight = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d--%d\n", result[i].src, result[i].dest);
        totalWeight += result[i].weight_3;
    }

    printf("Cost\n");
    for (i = 0; i < e; i++)
    {
        printf("%d ", result[i].weight_3);
    }
    for (; i < V_3 - 1; i++)
    {
        printf("+∞ ");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalWeight);
}

int main()
{
    int n, m;
    FILE *infile2 = fopen("intputQ2.dat", "r");
    fscanf(infile2, "%d %d", &n, &m);
    Graph_3 *graph_3 = createGraph_3(n, m);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        fscanf(infile2, "%d %d %d", &u, &v, &w);
        graph_3->edge_3[i].src = u;
        graph_3->edge_3[i].dest = v;
        graph_3->edge_3[i].weight_3 = w;
    }

    kruskalMST(graph_3);

    return 0;
}