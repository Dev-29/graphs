#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // Number of nodes
    int m; // Number of edges

    cout << "Input number of Nodes and Edges: ";
    cin >> n >> m;

    // Declare adjacency matrix
    int adj[n + 1][n + 1];

    // Take edges as input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Input u and v : \n";
        cin >> u >> v;
        adj[u][v] = 1; // Mark edge as 1. For example if (u, v) is (1, 2) we mark the edge in matrix
        adj[v][u] = 1; // Mark same (v, u) edge for undirected graphs
    }

    return 0;
}