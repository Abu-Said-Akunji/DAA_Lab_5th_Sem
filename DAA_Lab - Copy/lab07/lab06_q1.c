#include <stdio.h>
#include <stdlib.h>

// Define a structure for a symbol
struct SYMBOL {
    char alphabet;
    int frequency;
};

// Define a structure for a node in the Huffman tree
struct Node {
    struct SYMBOL symbol;
    struct Node* left;
    struct Node* right;
};

// Define a structure for a Min-Priority Queue node
struct MinPriorityQueueNode {
    struct Node* data;
    struct MinPriorityQueueNode* next;
};

// Define a structure for Min-Priority Queue
struct MinPriorityQueue {
    struct MinPriorityQueueNode* front;
};

// Function to create a new node
struct Node* newNode(struct SYMBOL symbol) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->symbol = symbol;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new Min-Priority Queue node
struct MinPriorityQueueNode* newMinPriorityQueueNode(struct Node* data) {
    struct MinPriorityQueueNode* node = (struct MinPriorityQueueNode*)malloc(sizeof(struct MinPriorityQueueNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new Min-Priority Queue
struct MinPriorityQueue* createMinPriorityQueue() {
    struct MinPriorityQueue* minPriorityQueue = (struct MinPriorityQueue*)malloc(sizeof(struct MinPriorityQueue));
    minPriorityQueue->front = NULL;
    return minPriorityQueue;
}

// Function to insert a node into Min-Priority Queue
void insertMinPriorityQueue(struct MinPriorityQueue* minPriorityQueue, struct Node* data) {
    struct MinPriorityQueueNode* newNode = newMinPriorityQueueNode(data);

    if (minPriorityQueue->front == NULL || data->symbol.frequency < minPriorityQueue->front->data->symbol.frequency) {
        newNode->next = minPriorityQueue->front;
        minPriorityQueue->front = newNode;
    } else {
        struct MinPriorityQueueNode* current = minPriorityQueue->front;
        while (current->next != NULL && data->symbol.frequency >= current->next->data->symbol.frequency) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to extract the minimum node from Min-Priority Queue
struct Node* extractMin(struct MinPriorityQueue* minPriorityQueue) {
    if (minPriorityQueue->front == NULL) {
        return NULL;
    }

    struct MinPriorityQueueNode* temp = minPriorityQueue->front;
    minPriorityQueue->front = minPriorityQueue->front->next;
    struct Node* data = temp->data;
    free(temp);
    return data;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(struct SYMBOL symbols[], int n) {
    struct MinPriorityQueue* minPriorityQueue = createMinPriorityQueue();

    // Create a Min-Priority Queue of nodes
    for (int i = 0; i < n; i++) {
        struct Node* node = newNode(symbols[i]);
        insertMinPriorityQueue(minPriorityQueue, node);
    }

    while (minPriorityQueue->front->next != NULL) {
        struct Node* left = extractMin(minPriorityQueue);
        struct Node* right = extractMin(minPriorityQueue);
        struct SYMBOL symbol;
        symbol.alphabet = '*';
        symbol.frequency = left->symbol.frequency + right->symbol.frequency;
        struct Node* node = newNode(symbol);
        node->left = left;
        node->right = right;
        insertMinPriorityQueue(minPriorityQueue, node);
    }

    return extractMin(minPriorityQueue);
}

// Function to perform in-order traversal of the Huffman tree
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->symbol.alphabet);
        inOrderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    struct Node* root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}