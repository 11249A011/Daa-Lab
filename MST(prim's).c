Aim
To implement Prim’s Algorithm in C to find the Minimum Spanning Tree (MST) of a weighted graph using a greedy approach.
  #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Number of vertices and edges
#define V 5
#define E 6 

// Function to find the vertex with minimum key value
int minKey(int key[], int visited[])
{
    int min = INT_MAX, min_index;

    // Loop through all vertices
    for (int i = 0; i < V; i++)
    {
        // Select the unvisited vertex with smallest key value
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the MST and its total cost
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;

    // Start from vertex 1 (since 0 is root)
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]]; // Add edge weight
    }

    // Print total cost of MST
    printf("Total Cost = %d\n", total);
}

// Function to implement Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];  // Stores constructed MST
    int key[V];     // Key values used to pick minimum weight edge
    int visited[V]; // To track visited vertices

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from first vertex
    key[0] = 0;     // First vertex has 0 cost
    parent[0] = -1; // Root node has no parent

    // MST will have V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, visited);
        visited[u] = 1;

        // Update key and parent of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Update only if:
            // 1. There is an edge (graph[u][v] != 0)
            // 2. Vertex v is not yet visited
            // 3. Weight is smaller than current key[v]
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printPrimMST(parent, graph);
}

// Main function
int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    // Call Prim's algorithm
    primMST(graph);

    return 0;
}
