#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the heap
struct HeapNode {
    int data;
};

// Function to swap two heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property at level l
void minHeapify(struct HeapNode* heap, int l, int n) {
    int smallest = l;
    int left = 2 * l + 1;
    int right = 2 * l + 2;

    if (left < n && heap[left].data < heap[smallest].data) {
        smallest = left;
    }

    if (right < n && heap[right].data < heap[smallest].data) {
        smallest = right;
    }

    if (smallest != l) {
        swap(&heap[l], &heap[smallest]);
        minHeapify(heap, smallest, n);
    }
}


void maxHeapify(struct HeapNode* heap, int l, int n) {
    int largest = l;
    int left = 2 * l + 1;
    int right = 2 * l + 2;

    if (left < n && heap[left].data > heap[largest].data) {
        largest = left;
    }

    if (right < n && heap[right].data > heap[largest].data) {
        largest = right;
    }

    if (largest != l) {
        swap(&heap[l], &heap[largest]);
        maxHeapify(heap, largest, n);
    }
}

void buildAlternateHeap(struct HeapNode* heap, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        if (i % 2 == 0) {

            minHeapify(heap, i, n);
        } else {

            maxHeapify(heap, i, n);
        }
    }
}


void printHeap(struct HeapNode* heap, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i].data);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    struct HeapNode* heap = (struct HeapNode*)malloc(sizeof(struct HeapNode) * n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heap[i].data);
    }

    buildAlternateHeap(heap, n);

    printf("Alternate Min-Max Heap: ");
    printHeap(heap, n);

    free(heap);
    return 0;
}

