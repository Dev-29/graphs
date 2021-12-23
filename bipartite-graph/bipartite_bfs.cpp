// We use graph coloring to check if a graph is bipartite or not.
// If we are able to color every adjacent node in opposite colors then it is Bipartite.

#include <bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int sourceNode, vector<int> adj[], int color[])   // BFS Algorithm to check Biparticity
{
    queue<int> q;
    q.push(sourceNode); // Push source node into queue
    color[sourceNode] = 1; // Then color the source node as '1'

    while (!q.empty())
    {
        int node = q.front(); // Select a node
        q.pop(); // and pop

        for (auto it : adj[node]) // Iterate throughout Adjacency List. Here, 'it' is an iterator.
        {
            if (color[it] == -1)    // If vertex is uncolored
            {
                color[it] = 1 - color[node]; // If vertex is uncolored, color it opposite to the previous vertex which is node.
                q.push(it);     // Push to queue after coloring.
            }
            else if (color[it] == color[node])  // IF previous vertex and current node have the same color, THEN Biparticity fails.
            {
                return false;   
            }
        }
    }
    return true;    // If we are successfully able to complete BFS (the queue becomes empty) return TRUE
}

bool checkBipartite(vector<int> adj[], int n)
{
    int color[n];     // Color vector of size 'n' to mark each vertex
    memset(color, -1, sizeof color);    // Initializes all vertex colors to -1
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBFS(i, adj, color))
            {
                return false;   // If the vertex is uncolored and is NOT bipartite, return false
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;  // 'n' is the number of vertices, 'm' is the number of edges
    vector<int> adj[n]; // Adjacency list of size 'n'

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}