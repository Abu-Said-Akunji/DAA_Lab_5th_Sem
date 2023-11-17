#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent a symbol with its alphabet and frequency
struct SYMBOL
{
    char alphabet;
    int frequency;
};

// Define a structure to represent a Huffman tree node
struct Node
{
    SYMBOL symbol;
    Node *left;
    Node *right;

    Node(SYMBOL s) : symbol(s), left(nullptr), right(nullptr) {}
};

// Custom comparator for the priority queue
struct CompareSymbols
{
    bool operator()(const Node *a, const Node *b) const
    {
        return a->symbol.frequency > b->symbol.frequency;
    }
};

// Function to build the Huffman tree
Node *buildHuffmanTree(vector<SYMBOL> &symbols)
{
    priority_queue<Node *, vector<Node *>, CompareSymbols> minHeap;

    // Create a leaf node for each symbol and add them to the minHeap
    for (SYMBOL &symbol : symbols)
    {
        Node *leafNode = new Node(symbol);
        minHeap.push(leafNode);
    }

    // Build the Huffman tree
    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        Node *internalNode = new Node({0, left->symbol.frequency + right->symbol.frequency});
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

// Function to perform in-order traversal of the Huffman tree
void inorderTraversal(Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->symbol.alphabet << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    int numAlphabets;
    cout << "Enter the number of distinct alphabets: ";
    cin >> numAlphabets;

    vector<SYMBOL> symbols(numAlphabets);

    cout << "Enter the alphabets: ";
    for (int i = 0; i < numAlphabets; i++)
    {
        cin >> symbols[i].alphabet;
    }

    cout << "Enter their frequencies: ";
    for (int i = 0; i < numAlphabets; i++)
    {
        cin >> symbols[i].frequency;
    }

    Node *root = buildHuffmanTree(symbols);

    cout << "In-order traversal of the tree (Huffman): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
