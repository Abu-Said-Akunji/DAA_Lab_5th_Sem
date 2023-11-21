#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an edge
struct Edge {
    int source;
    int destination;
};

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent an adjacency list
struct List {
    struct Node* head;
};

// Function to add an edge to the graph
void addEdge(struct List* adjacencyList, int source, int destination) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = adjacencyList[source].head;
    adjacencyList[source].head = newNode;

    // Since the graph is undirected, we add an edge from destination to source as well
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = source;
    newNode->next = adjacencyList[destination].head;
    adjacencyList[destination].head = newNode;
}

// Function to perform breadth-first search
void BFS(struct List* adjacencyList, int start, int n, int distances[]) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distances[i] = -1; // Initialize distances to -1 (unreachable)
    }

    visited[start] = true;
    distances[start] = 0;

    int queue[n];
    int front = 0, rear = 0;
    queue[rear] = start;
    rear++;

    while (front < rear) {
        int current = queue[front];
        front++;

        struct Node* temp = adjacencyList[current].head;
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distances[neighbor] = distances[current] + 2;
                queue[rear] = neighbor;
                rear++;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n; // Number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct List adjacencyList[n];
    for (int i = 0; i < n; i++) {
        adjacencyList[i].head = NULL;
    }

    int m; // Number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (source and destination): \n");
    for (int i = 0; i < m; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(adjacencyList, source, destination);
    }

    int start; // Starting node
    printf("Enter the starting node: ");
    scanf("%d", &start);

    int distances[n];
    BFS(adjacencyList, start, n, distances);

    printf("Breadth-First Search traversal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", distances[i]);
    }
    printf("\n");

    return 0;
}

