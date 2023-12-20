#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Structure to represent a vertex and its distance in the priority queue
struct Node {
    int vertex;
    int distance;
};

// Structure to represent a binary heap
struct BinaryHeap {
    int capacity;
    int size;
    struct Node* array;
};

// Function to create a new node
struct Node* createNode(int vertex, int distance) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->distance = distance;
    return newNode;
}

// Function to create a new binary heap
struct BinaryHeap* createHeap(int capacity) {
    struct BinaryHeap* heap = (struct BinaryHeap*)malloc(sizeof(struct BinaryHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (struct Node*)malloc(capacity * sizeof(struct Node));
    return heap;
}

// Function to swap two nodes in the heap
void swapNodes(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain heap property
void heapify(struct BinaryHeap* heap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->array[leftChild].distance < heap->array[smallest].distance)
        smallest = leftChild;

    if (rightChild < heap->size && heap->array[rightChild].distance < heap->array[smallest].distance)
        smallest = rightChild;

    if (smallest != index) {
        swapNodes(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

// Function to extract the minimum node from the heap
struct Node* extractMin(struct BinaryHeap* heap) {
    if (heap->size == 0)
        return NULL;

    struct Node* root = &heap->array[0];
    struct Node* lastNode = &heap->array[heap->size - 1];
    heap->array[0] = *lastNode;
    heap->size--;
    heapify(heap, 0);

    return root;
}

// Function to decrease the distance value of a vertex in the heap
void decreaseKey(struct BinaryHeap* heap, int vertex, int newDistance) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->array[i].vertex == vertex)
            break;
    }

    heap->array[i].distance = newDistance;

    // Fix the min heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2].distance > heap->array[i].distance) {
        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to check if a vertex is in the heap
int isInHeap(struct BinaryHeap* heap, int vertex) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->array[i].vertex == vertex)
            return 1; // Vertex found in the heap
    }
    return 0; // Vertex not found in the heap
}

// Dijkstra's algorithm to find the single source shortest paths
void dijkstra(int graph[V][V], int source) {
    // Create a binary heap with capacity V
    struct BinaryHeap* heap = createHeap(V);

    // Initialize distance values in the heap and set all vertices as not yet included in the shortest path tree
    for (int i = 0; i < V; i++) {
        heap->array[i] = *createNode(i, INT_MAX);
        heap->size++;
    }

    // Make the distance value of the source vertex 0
    heap->array[source].distance = 0;
    decreaseKey(heap, source, 0);

    // Dijkstra's algorithm
    while (heap->size != 0) {
        // Extract the vertex with the minimum distance value
        struct Node* current = extractMin(heap);
        int u = current->vertex;

        // Update distance values of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInHeap(heap, v) && current->distance != INT_MAX && current->distance + graph[u][v] < heap->array[v].distance) {
                heap->array[v].distance = current->distance + graph[u][v];
                decreaseKey(heap, v, heap->array[v].distance);
            }
        }
    }

    // Print the result
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, heap->array[i].distance);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Call Dijkstra's algorithm with the source vertex 0
    dijkstra(graph, 0);

    return 0;
}

