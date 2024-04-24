//travelling sales man problem in cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int min(int a,int b){
    return (a<b)? a:b;
}

int tsp(vector<vector<int>> &graph, int n, int start, int pos, int count, int cost, int &ans, vector<bool> &visited)
{
    if (count == n && graph[pos][start] > 0)
    {
        ans = min(ans, cost + graph[pos][start]);
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[pos][i] > 0)
        {
            visited[i] = true;
            tsp(graph, n, start, i, count + 1, cost + graph[pos][i], ans, visited);
            visited[i] = false;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the cost matrix: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    int ans = INT_MAX;
    vector<bool> visited(n, false);
    visited[0] = true;
    cout << "The minimum cost is: " << tsp(graph, n, 0, 0, 1, 0, ans, visited);
    return 0;
}
