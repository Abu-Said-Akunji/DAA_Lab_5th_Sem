#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000
#define INF 999999

int graph[MAX_NODES][MAX_NODES];
int distances[MAX_NODES];
int queue[MAX_NODES];
bool visited[MAX_NODES];

int front = -1, rear = -1;

void enqueue(int node)
{
    if (rear == MAX_NODES - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = node;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int node = queue[front];
    front++;
    if (front > rear)
    {
        front = rear = -1;
    }
    return node;
}

void BFS(int start, int n)
{
    enqueue(start);
    visited[start] = true;
    distances[start] = 0;

    while (front != -1)
    {
        int current = dequeue();
        for (int i = 1; i <= n; i++)
        {
            if (graph[current][i] == 2 && !visited[i])
            {
                enqueue(i);
                visited[i] = true;
                distances[i] = distances[current] + 2;
            }
        }
    }
}

int main()
{
    int n, m, u, v, s;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 2;
        graph[v][u] = 2; // Undirected graph
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] != 2)
            {
                graph[i][j] = -1; // Initialize non-adjacent nodes with -1
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        distances[i] = INF; // Initialize distances to infinity
        visited[i] = false;
    }

    scanf("%d", &s);
    BFS(s, n);

    // for (int i = 1; i <= n; i++)
    // {
    //     if (visited[i])
    //     {
    //         printf("%d ", visited[i]);
    //     }
    // }
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
        {
            continue; // Skip the start node
        }
        if (distances[i] == INF)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", distances[i]);
        }
    }
    printf("\n");

    return 0;
}
