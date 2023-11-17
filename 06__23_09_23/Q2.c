#include <stdio.h>
#include <stdlib.h>

// Structure to represent a symbol (alphabet and frequency)
struct SYMBOL
{
    char alphabet;
    int frequency;
};

// Structure to represent a node in the Huffman tree
struct Node
{
    struct SYMBOL symbol;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with a given symbol and frequency
struct Node *createNode(struct SYMBOL symbol)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Min-Heap data structure (Priority Queue)
struct MinHeap
{
    int size;
    struct Node **array;
};

// Function to create a new Min-Heap node
struct Node *createMinHeapNode(struct SYMBOL symbol)
{
    struct Node *newNode = createNode(symbol);
    return newNode;
}

// Function to create a new Min-Heap
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->array = (struct Node *)malloc(capacity * sizeof(struct Node));
    return minHeap;
}

// Function to swap two Min-Heap nodes
void swapMinHeapNodes(struct Node **a, struct Node **b)
{
    struct Node *t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify the Min-Heap
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->symbol.frequency < minHeap->array[smallest]->symbol.frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->symbol.frequency < minHeap->array[smallest]->symbol.frequency)
        smallest = right;

    if (smallest != idx)
    {
        swapMinHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if Min-Heap has only one node left
int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

// Function to extract the minimum value node from the Min-Heap
struct Node *extractMin(struct MinHeap *minHeap)
{
    struct Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a node into the Min-Heap
void insertMinHeap(struct MinHeap *minHeap, struct Node *node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->symbol.frequency < minHeap->array[(i - 1) / 2]->symbol.frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// Function to build the Huffman tree
struct Node *buildHuffmanTree(struct SYMBOL symbols[], int n)
{
    struct Node *left, *right, *top;
    struct MinHeap *minHeap = createMinHeap(n);

    for (int i = 0; i < n; ++i)
        insertMinHeap(minHeap, createMinHeapNode(symbols[i]));

    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        // The alphabet for internal nodes can be any character since we won't use it
        struct SYMBOL temp_symbol;
        temp_symbol.alphabet = '-';
        temp_symbol.frequency = left->symbol.frequency + right->symbol.frequency;
        top = createMinHeapNode(temp_symbol);

        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to perform in-order traversal of the Huffman tree and print the characters
void inorderTraversal(struct Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        printf("%c ", root->symbol.alphabet);
        inorderTraversal(root->right);
    }
}

int main()
{
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; ++i)
        scanf(" %c", &symbols[i].alphabet);

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &symbols[i].frequency);

    struct Node *root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);

    printf("\n");

    return 0;
}