#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

int main()
{
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool inMST[MAX_VERTICES];

    int numVertices, startVertex;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);

    // Read the adjacency matrix from the input file "inUnAdjMat.dat"
    FILE *infile1 = fopen("intputQ1.dat", "r");
    if (infile1 == NULL)
    {
        printf("Error opening the file.");
        return 1;
    }
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            fscanf(infile1, "%d", &adjMatrix[i][j]);
        }
    }

    for (int i = 0; i < numVertices; i++)
    {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    key[startVertex - 1] = 0;
    parent[startVertex - 1] = -1;

    for (int count = 0; count < numVertices - 1; count++)
    {
        int minKey = INT_MAX;
        int minIndex;

        for (int v = 0; v < numVertices; v++)
        {
            if (!inMST[v] && key[v] < minKey)
            {
                minKey = key[v];
                minIndex = v;
            }
        }

        inMST[minIndex] = true;

        for (int v = 0; v < numVertices; v++)
        {
            if (adjMatrix[minIndex][v] && !inMST[v] && adjMatrix[minIndex][v] < key[v])
            {
                parent[v] = minIndex;
                key[v] = adjMatrix[minIndex][v];
            }
        }
    }

    printf("Cost adjacency matrix of the minimum spanning tree:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (i == j)
            {
                printf("0\t");
            }
            else if (parent[j] == i || parent[i] == j)
            {
                printf("%d\t", adjMatrix[i][j]);
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }

    int totalWeight = 0;
    for (int i = 0; i < numVertices; i++)
    {
        if (i != startVertex - 1)
        {
            totalWeight += adjMatrix[i][parent[i]];
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);

    return 0;
}