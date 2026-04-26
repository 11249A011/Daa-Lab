Aim
To implement Dijkstra’s Algorithm in C to find the shortest path from a source vertex to all other vertices in a weighted graph using a greedy approach.
#include <stdio.h>

#define V 5        // Number of vertices
#define INF 999999 // Representation of infinity

// Function to find the vertex with minimum distance among unvisited vertices
int extractMin(int dist[], int visited[])
{
    int min = INF, min_index = -1;

    // Traverse all vertices
    for (int v = 0; v < V; v++)
    {
        // Select the unvisited vertex with minimum distance
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V])
{
    int dist[V];    // Array to store shortest distances
    int visited[V]; // Tracks processed vertices

    // Initialize distances as infinity and visited as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0; // 0 means not visited
    }

    // Source vertex is 0
    dist[0] = 0;

    // Loop to find shortest paths for all vertices
    for (int count = 0; count < V; count++)
    {
        // Extract vertex with minimum distance
        int u = extractMin(dist, visited);

        if (u == -1)
            break;

        // Mark vertex as visited
        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int j = 0; j < V; j++)
        {
            // Check:
            // 1. Edge exists (graph[u][j] > 0)
            // 2. Vertex not visited
            if (graph[u][j] > 0 && !visited[j])
            {
                // Relaxation condition
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Print shortest distances from source
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
        printf("%d --> %d\n", i, dist[i]);
}

// Main function
int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    // Call Dijkstra's algorithm
    dijkstra(graph);

    return 0;
}
