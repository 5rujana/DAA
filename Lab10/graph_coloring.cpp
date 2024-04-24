#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to color a vertex with a given color
bool isSafe(const vector<vector<int>>& graph, const vector<int>& color, int v, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Function to recursively assign colors to vertices
bool graphColoringUtil(const vector<vector<int>>& graph, vector<int>& color, int v, int m) {
    if (v == graph.size()) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c; // Assign color c to vertex v
            if (graphColoringUtil(graph, color, v + 1, m)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }

    return false;
}

// Function to solve the graph coloring problem
void graphColoring(const vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0);

    if (graphColoringUtil(graph, color, 0, m)) {
        cout << "Graph can be colored using " << m << " colors:" << endl;
        for (int i = 0; i < graph.size(); ++i) {
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
        }
    } else {
        cout << "Graph cannot be colored using " << m << " colors." << endl;
    }
}

int main() {
    int v;
    cout<<"enter number of vertices"<<endl;
    cin>>v;
    vector<vector<int>> graph(v,vector<int>(v));
    cout<<"enter graph"<<endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v ; j++)
        {
            cin>>graph[i][j];
        }
        
    }
    
    int m = 3; 

    graphColoring(graph, m);

    return 0;
}
