#include <stdio.h>
#include <stdlib.h>

// Structure to represent a symbol_3 (alphabet_3 and frequency_3)
struct SYMBOL
{
    char alphabet_3;
    int frequency_3;
};

// Structure to represent a node in the Huffman tree
struct Node
{
    struct SYMBOL symbol_3;
    struct Node *left_3;
    struct Node *right_3;
};

// Function to create a new node with a given symbol_3 and frequency_3
struct Node *createNode(struct SYMBOL symbol_3)
{
    struct Node *newNode_3 = (struct Node *)malloc(sizeof(struct Node));
    newNode_3->symbol_3 = symbol_3;
    newNode_3->left_3 = newNode_3->right_3 = NULL;
    return newNode_3;
}

// Min-Heap data structure (Priority Queue)
struct MinHeap
{
    int size_3;
    struct Node **array_3;
};

// Function to create a new Min-Heap node
struct Node *createMinHeapNode(struct SYMBOL symbol_3)
{
    struct Node *newNode_3 = createNode(symbol_3);
    return newNode_3;
}

// Function to create a new Min-Heap
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap_3 = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap_3->size_3 = 0;
    minHeap_3->array_3 = (struct Node *)malloc(capacity * sizeof(struct Node));
    return minHeap_3;
}

// Function to swap two Min-Heap nodes
void swapMinHeapNodes(struct Node **a, struct Node **b)
{
    struct Node *t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify the Min-Heap
void minHeapify(struct MinHeap *minHeap_3, int idx_3)
{
    int smallest_3 = idx_3;
    int left_3 = 2 * idx_3 + 1;
    int right_3 = 2 * idx_3 + 2;

    if (left_3 < minHeap_3->size_3 && minHeap_3->array_3[left_3]->symbol_3.frequency_3 < minHeap_3->array_3[smallest_3]->symbol_3.frequency_3)
        smallest_3 = left_3;

    if (right_3 < minHeap_3->size_3 && minHeap_3->array_3[right_3]->symbol_3.frequency_3 < minHeap_3->array_3[smallest_3]->symbol_3.frequency_3)
        smallest_3 = right_3;

    if (smallest_3 != idx_3)
    {
        swapMinHeapNodes(&minHeap_3->array_3[smallest_3], &minHeap_3->array_3[idx_3]);
        minHeapify(minHeap_3, smallest_3);
    }
}

// Function to check if Min-Heap has only one node left_3
int isSizeOne(struct MinHeap *minHeap_3)
{
    return (minHeap_3->size_3 == 1);
}

// Function to extract the minimum value node from the Min-Heap
struct Node *extractMin(struct MinHeap *minHeap_3)
{
    struct Node *temp = minHeap_3->array_3[0];
    minHeap_3->array_3[0] = minHeap_3->array_3[minHeap_3->size_3 - 1];
    --minHeap_3->size_3;
    minHeapify(minHeap_3, 0);
    return temp;
}

// Function to insert a node into the Min-Heap
void insertMinHeap(struct MinHeap *minHeap_3, struct Node *node)
{
    ++minHeap_3->size_3;
    int i = minHeap_3->size_3 - 1;
    while (i && node->symbol_3.frequency_3 < minHeap_3->array_3[(i - 1) / 2]->symbol_3.frequency_3)
    {
        minHeap_3->array_3[i] = minHeap_3->array_3[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap_3->array_3[i] = node;
}

// Function to build the Huffman tree
struct Node *buildHuffmanTree(struct SYMBOL symbol_3s[], int n)
{
    struct Node *left_3, *right_3, *top;
    struct MinHeap *minHeap_3 = createMinHeap(n);

    for (int i = 0; i < n; ++i)
        insertMinHeap(minHeap_3, createMinHeapNode(symbol_3s[i]));

    while (!isSizeOne(minHeap_3))
    {
        left_3 = extractMin(minHeap_3);
        right_3 = extractMin(minHeap_3);

        // Create a new internal node with frequency_3 equal to the sum of the two nodes' frequencies
        // The alphabet_3 for internal nodes can be any character since we won't use it
        struct SYMBOL temp_symbol_3;
        temp_symbol_3.alphabet_3 = '-';
        temp_symbol_3.frequency_3 = left_3->symbol_3.frequency_3 + right_3->symbol_3.frequency_3;
        top = createMinHeapNode(temp_symbol_3);

        top->left_3 = left_3;
        top->right_3 = right_3;
        insertMinHeap(minHeap_3, top);
    }

    return extractMin(minHeap_3);
}

// Function to perform in-order traversal of the Huffman tree and print the characters
void inorderTraversal(struct Node *root)
{
    if (root)
    {
        inorderTraversal(root->left_3);
        printf("%c ", root->symbol_3.alphabet_3);
        inorderTraversal(root->right_3);
    }
}

int main()
{
    int n;
    printf("Enter the number of distinct alphabet_3s: ");
    scanf("%d", &n);

    struct SYMBOL symbol_3s[n];

    printf("Enter the alphabet_3s: ");
    for (int i = 0; i < n; ++i)
        scanf(" %c", &symbol_3s[i].alphabet_3);

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &symbol_3s[i].frequency_3);

    struct Node *root = buildHuffmanTree(symbol_3s, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);

    printf("\n");

    return 0;
}