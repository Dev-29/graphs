#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // Input no. of nodes, edges

    vector<pair<int, int>> adj[n + 1]; // Pair STL to input edge weights

    for (int i = 0; i < m; i++)
    {
        int u, v, weight; // u - Node1, v - Node2, weight b/w u, v
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    return 0;
}