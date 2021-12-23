#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool checkForCycle(int startNode, int V, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> q;    // Queue which stores pairs of current node & its previous node

        visited[startNode] = 1;     // Mark start node as visited and push (startNode, -1) to queue
        q.push({startNode, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();    // Remove top element after processing its BFS

            for (auto it : adj[node]) // Iterate throughout the adjacency list
            {
                if (!visited[it])   
                {
                    visited[it] = 1;    
                    q.push({it, node}); // Push every unvisited node along with its previous node in queue
                }
                else if (par != it)     // IF THE NODE IS ALREADY VISITED,
                {                       // AND ITS NOT PAIRED IN QUEUE ALONG WITH ITS PREVIOUS PARENT NODE, THEN THERE IS A CYCLE PRESENT
                    return true;
                }
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))  // Check cycle presence for every unvisited node
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int tc; // Test Cases
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "Cycle Present\n";
        else
            cout << "No Cycle Present\n";
    }
    return 0;
} 