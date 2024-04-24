#include <bits/stdc++.h>

using namespace std;

const int V = 4; // Number of vertices

// Function to solve TSP using dynamic programming
int tsp(vector<vector<int>>& graph, int s, vector<vector<int>>& dp, int mask) {
    if (mask == (1 << V) - 1) // If all cities have been visited
        return graph[s][0];   // Return to the starting city

    if (dp[s][mask] != -1) // If the result is already computed
        return dp[s][mask];

    int ans = INT_MAX;
    for (int v = 0; v < V; ++v) {
        if (!(mask & (1 << v))) { // If city v is not visited
            int cost = graph[s][v] + tsp(graph, v, dp, mask | (1 << v));
            ans = min(ans, cost);
        }
    }
    return dp[s][mask] = ans;
}

// Main function
int main() {
    vector<vector<int>> graph = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };

    // Initialize memoization table
    vector<vector<int>> dp(V, vector<int>(1 << V, -1));

    int source = 0; // Source vertex

    int minCost = tsp(graph, source, dp, 1 << source); // Start from source vertex

    cout << "Minimum cost for TSP: " << minCost << endl;

    return 0;
}

