#include <stdio.h>
#include <stdlib.h>

struct Symbol {
    char alphabet;
    int frequency;
};

struct Node {
    struct Symbol symbol;
    struct Node* left;
    struct Node* right;
};

struct MinPriorityQueue {
    struct Node** array;
    int size;
    int capacity;
};

struct Node* newNode(struct Symbol symbol) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->symbol = symbol;
    node->left = node->right = NULL;
    return node;
}

struct MinPriorityQueue* createMinPriorityQueue(int capacity) {
    struct MinPriorityQueue* queue = (struct MinPriorityQueue*)malloc(sizeof(struct MinPriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (struct Node*)malloc(capacity * sizeof(struct Node));
    return queue;
}

void swapNodes(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinPriorityQueue* queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->array[left]->symbol.frequency < queue->array[smallest]->symbol.frequency)
        smallest = left;
    if (right < queue->size && queue->array[right]->symbol.frequency < queue->array[smallest]->symbol.frequency)
        smallest = right;

    if (smallest != index) {
        swapNodes(&queue->array[smallest], &queue->array[index]);
        minHeapify(queue, smallest);
    }
}

void insertMinPriorityQueue(struct MinPriorityQueue* queue, struct Node* node) {
    queue->size++;
    int i = queue->size - 1;
    while (i > 0 && node->symbol.frequency < queue->array[(i - 1) / 2]->symbol.frequency) {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}

struct Node* extractMin(struct MinPriorityQueue* queue) {
    if (queue->size <= 0)
        return NULL;
    if (queue->size == 1) {
        queue->size--;
        return queue->array[0];
    }

    struct Node* root = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    queue->size--;
    minHeapify(queue, 0);

    return root;
}

struct Node* buildHuffmanTree(struct Symbol symbols[], int n) {
    struct MinPriorityQueue* queue = createMinPriorityQueue(n);

    for (int i = 0; i < n; i++) {
        struct Node* node = newNode(symbols[i]);
        insertMinPriorityQueue(queue, node);
    }

    while (queue->size > 1) {
        struct Node* left = extractMin(queue);
        struct Node* right = extractMin(queue);

        struct Symbol internalSymbol;
        internalSymbol.alphabet = '#';
        internalSymbol.frequency = left->symbol.frequency + right->symbol.frequency;

        struct Node* internalNode = newNode(internalSymbol);
        internalNode->left = left;
        internalNode->right = right;

        insertMinPriorityQueue(queue, internalNode);
    }

    struct Node* huffmanRoot = extractMin(queue);
    return huffmanRoot;
}

void printHuffmanCodes(struct Node* root, int codes[], int top) {
    if (root->left) {
        codes[top] = 0;
        printHuffmanCodes(root->left, codes, top + 1);
    }

    if (root->right) {
        codes[top] = 1;
        printHuffmanCodes(root->right, codes, top + 1);
    }

    if (!root->left && !root->right) {
        printf("Symbol: %c, Frequency: %d, Huffman Code: ", root->symbol.alphabet, root->symbol.frequency);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of symbols: ");
    scanf("%d", &n);

    struct Symbol symbols[n];

    for (int i = 0; i < n; i++) {
        printf("Enter symbol %d: ", i + 1);
        scanf(" %c", &symbols[i].alphabet);
        printf("Enter frequency for symbol %c: ", symbols[i].alphabet);
        scanf("%d", &symbols[i].frequency);
    }

    struct Node* huffmanRoot = buildHuffmanTree(symbols, n);

    int codes[n];
    int top = 0;

    printf("Huffman Codes:\n");
    printHuffmanCodes(huffmanRoot, codes, top);

    return 0;
}
