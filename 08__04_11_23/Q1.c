#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES_3 1000
#define MAX_EDGES_3 1000

int graph_3[MAX_NODES_3][MAX_NODES_3];
int visited_3[MAX_NODES_3];
int distance_3[MAX_NODES_3];

int queue_3[MAX_NODES_3];
int front_3 = -1, rear_3 = -1;

void enqueue(int node_3)
{
    if (rear_3 == MAX_NODES_3 - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front_3 == -1)
        {
            front_3 = 0;
        }
        rear_3 = rear_3 + 1;
        queue_3[rear_3] = node_3;
    }
}

int dequeue()
{
    int node_3;
    if (front_3 == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        node_3 = queue_3[front_3];
        front_3 = front_3 + 1;
        if (front_3 > rear_3)
        {
            front_3 = rear_3 = -1;
        }
        return node_3;
    }
}

void breadthFirstSearch(int start_3, int n)
{
    for (int i = 1; i <= n; i++)
    {
        visited_3[i] = 0;
        distance_3[i] = -1;
    }

    visited_3[start_3] = 1;
    distance_3[start_3] = 0;
    enqueue(start_3);

    while (front_3 != -1)
    {
        int current_3 = dequeue();
        for (int i = 1; i <= n; i++)
        {
            if (graph_3[current_3][i] == 1 && !visited_3[i])
            {
                visited_3[i] = 1;
                distance_3[i] = distance_3[current_3] + 2;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int n_3, m_3;
    scanf("%d %d", &n_3, &m_3);

    for (int i = 0; i < m_3; i++)
    {
        int u_3, v_3;
        scanf("%d %d", &u_3, &v_3);
        graph_3[u_3][v_3] = 1;
        graph_3[v_3][u_3] = 1;
    }

    int s_3;
    scanf("%d", &s_3);

    breadthFirstSearch(s_3, n_3);
    printf("BFS Traversal: %d ", s_3);
    for (int i = 0; i < m_3 - 1; i++)
    {
        printf("%d ", queue_3[i]);
    }
    printf("\nDistance: [");
    for (int i = 1; i <= n_3; i++)
    {
        printf("%d ", distance_3[i]);
    }
    printf("]\n");

    return 0;
}
