// optimal binary search tree in C++
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int obst(int n, float p[], float q[]) {
    float e[MAX][MAX]; //stores expected cost of searching a subtree that spans from node i to j
    float w[MAX][MAX]; // represents sum of probabilities of searching for each key in the subtree node i to j
    int root[MAX][MAX];
    // initializing the arrays
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    // filling the arrays
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            // j is the root of the subtree
            int j = i + l - 1;
            e[i][j] = 9999;
            w[i][j] = w[i][j - 1] + p[j] + q[j]; // sum of probabilities
            for (int r = i; r <= j; r++) {
                float t = e[i][r - 1] + e[r + 1][j] + w[i][j]; // cost
                if (t < e[i][j]) { // updating the arrays
                    e[i][j] = t; 
                    root[i][j] = r; // root of the subtree
                }
            }
        }
    }
    return e[1][n]; // cost of optimal binary search tree
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    float p[n + 1], q[n + 1];
    cout << "Enter the probability of successful search: ";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << "Enter the probability of unsuccessful search: ";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }
    cout << "The cost of optimal binary search tree is: " << obst(n, p, q) << endl;
    return 0;
}
