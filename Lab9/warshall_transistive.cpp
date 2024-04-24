// warshalls transistive closure algorithm

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void warshall(int n, int graph[MAX][MAX]) {
    int reach[MAX][MAX];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            reach[i][j] = graph[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    cout << "The transitive closure of the graph is: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int graph[MAX][MAX];
    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    warshall(n, graph);
    return 0;
}