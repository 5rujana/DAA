#include <iostream>
#include <climits>
using namespace std;

// Number of vertices in the graph
#define V 6

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    // Find the minimum distance vertex that is not yet included in the shortest path tree
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            //!sptSet[v] is true if vertex v is not yet included in the shortest path tree
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t " << dist[i] << endl;
}

// Function to implement Dijkstra's algorithm for a given graph
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array dist[i] holds the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest
                    // path tree or the shortest distance from src to i is finalized

    // Initialize distances and sptSet array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // Set initial distances to infinity
        sptSet[i] = false; // No vertex is included in the shortest path tree initially
    }

    dist[src] = 0; // Distance from the source vertex to itself is always 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);
        sptSet[u] = true; // Mark the picked vertex as processed

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not in the shortest path tree,
            // there is an edge from u to v, and the total weight of path from src to v
            // through u is smaller than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    // Input the graph from the user
    int graph[V][V];
    cout << "Enter the adjacency matrix of the graph (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Source vertex
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    cout << "Shortest paths from source vertex " << src << ":\n";
    dijkstra(graph, src);

    return 0;
}
