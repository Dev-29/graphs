// BFS - Traversing the adjacent nodes first

#include <bits/stdc++.h>
using namespace std;

void breadthFirstSearch(int V, vector<int> adj[]);

// Main
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

    breadthFirstSearch(n, adj);

    return 0;
}

void breadthFirstSearch(int V, vector<int> adj[])
{
    vector<int> bfs;           // bfs vector to store final values after bfs
    vector<int> vis(V + 1, 0); // Visited vector to keep track of all visited & unvisited nodes

    for (int i = 1; i <= V; i++)
    {
        if (!vis[i]) // For an unvisited node
        {
            queue<int> q;
            q.push(i);  // Push starting node in queue
            vis[i] = 1; // Mark it as visited

            while (q.empty())
            {
                int node = q.front(); // Start bfs for node for top most element in the queue
                q.pop();              // Remove from queue after performing bfs
                bfs.push_back(node);  // Push the node onto final bfs vector

                for (auto it : adj[node]) // Iterate throughout the adj list. Here 'it' is the iterator.
                {
                    if (!vis[it]) // If unvisited
                    {
                        q.push(it);  // Push unvisited nodes in queue
                        vis[it] = 1; // Then mark it as visited
                    }
                }
            }
        }
    }

    for (auto i : bfs)
    {
        cout << i << " ";
    }
}