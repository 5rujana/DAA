#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Class to represent an Edge in the graph
class Edge {
public:
    int src, dest, weight;
};

// Class to represent a Graph
class Graph {
public:
    int V, E;             // Number of vertices (V) and edges (E) in the graph
    vector<Edge> edges;   // Vector to store edges
};

// Class for Union-Find data structure
class UnionFind {
public:
    vector<int> parent, rank;

    // Constructor to initialize Union-Find data structure with 'n' elements
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;  // Each element is initially its own root
    }

    // Function to find the root of the set to which 'x' belongs
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression for optimization
        return parent[x];
    }

    // Function to perform union of two sets
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank for optimization
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY; // Make root of smaller rank tree point to root of larger rank tree
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX; // Make root of smaller rank tree point to root of larger rank tree
            else {
                parent[rootY] = rootX; // Make one root point to the other root
                rank[rootX]++;
            }
        }
    }
};

// Comparison function to sort edges based on weight
bool comp(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to perform Kruskal's algorithm to find Minimum Spanning Tree (MST)
void kruskalMST(Graph& graph) {
    sort(graph.edges.begin(), graph.edges.end(), comp);  // Sorting edges based on weight

    UnionFind uf(graph.V);  // Creating Union-Find data structure with 'V' elements

    cout << "Following are the edges in the constructed MST:" << endl;

    for (const Edge& edge : graph.edges) {
        int rootSrc = uf.find(edge.src); // Finding the root of the set to which 'src' belongs
        int rootDest = uf.find(edge.dest);// Finding the root of the set to which 'dest' belongs

        if (rootSrc != rootDest) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
            uf.unite(rootSrc, rootDest);  // Performing union of sets to merge connected components
        }
    }
}

int main() {
    Graph graph;
    cout << "Enter the number of vertices in the graph: ";
    cin >> graph.V;
    cout << "Enter the number of edges in the graph: ";
    cin >> graph.E;

    cout << "Enter the edges (source destination weight):" << endl;
    graph.edges.resize(graph.E);
    for (int i = 0; i < graph.E; ++i) {
        cin >> graph.edges[i].src >> graph.edges[i].dest >> graph.edges[i].weight;
    }

    kruskalMST(graph);

    return 0;
}
