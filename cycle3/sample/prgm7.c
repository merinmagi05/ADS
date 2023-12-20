#include<stdio.h>
#include<stdlib.h>

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};
// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function prototypes
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compare(const void* a, const void* b);
void KruskalMST(struct Edge edges[], int V, int E);

int main()
{
    // Example graph represented as an array of edges
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Call Kruskal's algorithm to find the minimum spanning tree
    KruskalMST(edges, V, E);

    return 0;
}

// A utility function to find the set of an element i
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A utility function to perform union of two sets x and y
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach the smaller rank tree under the root of the high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        // If ranks are the same, make one as the root and increment its rank
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort to sort edges based on weight
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the minimum spanning tree
void KruskalMST(struct Edge edges[], int V, int E) {
    // Allocate memory for the subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize the result
    struct Edge result[V];
    int i = 0; // Index used to pick edges from the sorted edges array

    // Number of edges to be taken is equal to V-1
    while (i < V - 1 && E > 0) {
        // Pick the smallest edge, and increment the index for the next iteration
        struct Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause a cycle, add it to the result and increment the count of added edges
        if (x != y) {
            result[E - 1] = next_edge;
            Union(subsets, x, y);
            E--;
        }
    }

    // Print the result
    printf("Edges in the minimum spanning tree:\n");
    for (int j = 0; j < V - 1; j++)
        printf("(%d, %d) -> %d\n", result[j].src, result[j].dest, result[j].weight);

    // Free allocated memory
    free(subsets);
}

