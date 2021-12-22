#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs)
{
    storeDfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, storeDfs); // For every unvisited node, call dfs on it recursively
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) // DFS Function
{
    vector<int> storeDfs;
    vector<int> vis(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, storeDfs); // For every unvisited node call the recursive dfs function
        }
    }
    return storeDfs;
}

int main()
{
    int n, m;
    cin >> n >> m;          // Number of nodes, edges
    vector<int> adj[n + 1]; // Adjacency List

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res = dfsOfGraph(n, adj);
    for (auto i : res)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}