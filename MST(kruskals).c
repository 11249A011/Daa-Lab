Aim
To implement Kruskal’s Algorithm in C to find the Minimum Spanning Tree (MST) of a weighted graph using the greedy approach and Union-Find (Disjoint Set) technique.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Number of vertices and edges
#define V 5
#define E 6 

// Structure to represent an edge
struct Edge
{
    int src, dest, weight; // source, destination, and weight of edge
};

// Array for Union-Find (Disjoint Set)
int parentUF[V];

// Function to find the root of a set (Find operation)
int find(int i)
{
    // If element is its own parent, return it
    if (parentUF[i] == i)
        return i;

    // Recursively find the root
    return find(parentUF[i]);
}

// Function to perform union of two sets (Union operation)
void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);

    // Merge the sets by assigning parent
    parentUF[rootU] = rootV;
}

// Comparator function for qsort to sort edges by weight
int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to implement Kruskal's MST algorithm
void kruskalMST(struct Edge edges[])
{
    printf("\nKruskal's MST:\n");
    printf("Edge \tWeight\n");

    // Step 1: Sort edges in ascending order of weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Step 2: Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
        parentUF[i] = i;

    int count = 0; // Number of edges included in MST
    int total = 0; // Total weight of MST

    // Step 3: Pick edges one by one
    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        // Step 4: Check if adding this edge forms a cycle
        if (find(u) != find(v))
        {
            // Include the edge in MST
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            total += edges[i].weight;

            // Union of the sets
            unionSet(u, v);
            count++;
        }
    }

    // Print total cost of MST
    printf("Total Cost = %d\n", total);
}

// Main function
int main()
{
    // Define graph edges (src, dest, weight)
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 5},
        {1, 3, 3},
        {2, 4, 4},
        {3, 4, 2}
    };

    // Call Kruskal's algorithm
    kruskalMST(edges);

    return 0;
}
