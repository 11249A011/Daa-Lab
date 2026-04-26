Aim
To implement the Travelling Salesman Problem (TSP) using Dynamic Programming (Bitmasking + Recursion) in C to find the minimum travelling cost.
#include <stdio.h>
#include <limits.h>

#define MAXN 15           // Maximum number of cities
#define INF INT_MAX       // Infinity value

int n;                   // Number of cities
int d[MAXN][MAXN];       // Cost matrix
int dp[MAXN][1 << MAXN]; // DP table (memoization)

// Function to calculate minimum cost
// i = current city
// s = set of remaining cities (bitmask)
int g(int i, int s)
{
    // Base case: if no cities left, return cost to go back to start (city 0)
    if (s == 0)
        return d[i][0];

    // If already computed, return stored result
    if (dp[i][s] != -1)
        return dp[i][s];

    int mincost = INF;

    // Try visiting all remaining cities
    for (int k = 0; k < n; k++)
    {
        // Check if city k is in set s
        if (s & (1 << k))
        {
            // Cost = distance to k + cost of remaining path
            int cost = d[i][k] + g(k, s & ~(1 << k));

            // Update minimum cost
            if (cost < mincost)
            {
                mincost = cost;
            }
        }
    }

    // Store result in DP table
    return dp[i][s] = mincost;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    // Input cost matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    // Initialize DP table with -1 (uncomputed)
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][mask] = -1;

    // Create initial set of cities (excluding starting city 0)
    int S = 0;
    for (int i = 1; i < n; i++)
        S |= (1 << i);

    // Start from city 0
    int result = g(0, S);

    // Print cost matrix
    printf("Given Cost Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %d ", d[i][j]);
        printf("|\n");
    }

    // Output minimum travelling cost
    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
