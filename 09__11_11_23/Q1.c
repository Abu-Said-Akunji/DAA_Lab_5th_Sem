#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES_3 100

int main()
{
    int adjMatrix_3[MAX_VERTICES_3][MAX_VERTICES_3];
    int parent_3[MAX_VERTICES_3];
    int key_3[MAX_VERTICES_3];
    bool inMST_3[MAX_VERTICES_3];

    int numVertices_3, startVertex_3;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &numVertices_3);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex_3);

    // Read the adjacency matrix from the input file "inUnAdjMat.dat"
    FILE *infile1_3 = fopen("intputQ1.dat", "r");
    if (infile1_3 == NULL)
    {
        printf("Error opening the file.");
        return 1;
    }
    for (int i = 0; i < numVertices_3; i++)
    {
        for (int j = 0; j < numVertices_3; j++)
        {
            fscanf(infile1_3, "%d", &adjMatrix_3[i][j]);
        }
    }

    for (int i = 0; i < numVertices_3; i++)
    {
        key_3[i] = INT_MAX;
        inMST_3[i] = false;
    }

    key_3[startVertex_3 - 1] = 0;
    parent_3[startVertex_3 - 1] = -1;

    for (int count_3 = 0; count_3 < numVertices_3 - 1; count_3++)
    {
        int minKey_3 = INT_MAX;
        int minIndex_3;

        for (int v = 0; v < numVertices_3; v++)
        {
            if (!inMST_3[v] && key_3[v] < minKey_3)
            {
                minKey_3 = key_3[v];
                minIndex_3 = v;
            }
        }

        inMST_3[minIndex_3] = true;

        for (int v = 0; v < numVertices_3; v++)
        {
            if (adjMatrix_3[minIndex_3][v] && !inMST_3[v] && adjMatrix_3[minIndex_3][v] < key_3[v])
            {
                parent_3[v] = minIndex_3;
                key_3[v] = adjMatrix_3[minIndex_3][v];
            }
        }
    }

    printf("Cost adjacency matrix of the minimum spanning tree:\n");
    for (int i = 0; i < numVertices_3; i++)
    {
        for (int j = 0; j < numVertices_3; j++)
        {
            if (i == j)
            {
                printf("0\t");
            }
            else if (parent_3[j] == i || parent_3[i] == j)
            {
                printf("%d\t", adjMatrix_3[i][j]);
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }

    int totalWeight_3 = 0;
    for (int i = 0; i < numVertices_3; i++)
    {
        if (i != startVertex_3 - 1)
        {
            totalWeight_3 += adjMatrix_3[i][parent_3[i]];
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight_3);

    return 0;
}