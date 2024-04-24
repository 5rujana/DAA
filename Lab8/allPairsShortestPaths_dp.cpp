#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V]){
    cout << "The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][V])
{
    int dist[V][V];

    // Initialize distances with given graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update distances using all vertices as intermediate nodes
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from i to j, update distance
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V];
    cout << "Enter the adjacency matrix (Enter INF for no direct edge): " << endl;
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == -1) // Assuming -1 represents INF
                graph[i][j] = INF;
        }
    }
    floydWarshall(graph);
    return 0;
}

// Enter the adjacency matrix (Enter INF for no direct edge):
// 0 5 INF 10
// INF 0 3 INF
// INF INF 0 1
// INF INF INF 0
