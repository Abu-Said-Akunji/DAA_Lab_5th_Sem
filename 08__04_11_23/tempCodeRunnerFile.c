#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int distance[MAX_NODES];

int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int node)
{
    if (rear == MAX_NODES - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = node;
    }
}

int dequeue()
{
    int node;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        node = queue[front];
        front = front + 1;
        if (front > rear)
        {
            front = rear = -1;
        }
        return node;
    }
}

void breadthFirstSearch(int start, int n)
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        distance[i] = -1;
    }

    visited[start] = 1;
    distance[start] = 0;
    enqueue(start);

    while (front != -1)
    {
        int current = dequeue();
        for (int i = 1; i <= n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                distance[i] = distance[current] + 2;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int s;
    scanf("%d", &s);

    breadthFirstSearch(s, n);
    printf("BFS Traversal: %d ", s);
    for (int i = 0; i < m - 1; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\nDistance: [");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", distance[i]);
    }
    printf("]\n");

    return 0;
}
