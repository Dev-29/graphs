#include <bits/stdc++.h>
using namespace std;

bool checkBipartiteDFS(int sourceNode, vector<int> adj[], int color[])
{
    for (auto it : adj[sourceNode])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[sourceNode];
            if (!checkBipartiteDFS(it, adj, color))
            {
                return false;
            }
        }
        else if (color[it] == color[sourceNode])
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    int color[V];
    memset(color, -1, sizeof color);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!checkBipartiteDFS(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(n, adj))
    {
        cout << "Graph is Bipartite\n";
    }
    else
    {
        cout << "Graph is not Bipartite\n";
    }
    return 0;
}