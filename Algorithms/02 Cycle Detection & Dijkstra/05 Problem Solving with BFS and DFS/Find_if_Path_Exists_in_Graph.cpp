/*
Intuition
This is a connectivity problem in a graph.

If we can reach destination starting from source by traversing edges, the answer is true.
Otherwise, false.
We can solve this using:

DFS / BFS → explore all reachable nodes from source.
Approach
Build an adjacency list from the given edges.

Use a visited array to avoid revisiting nodes.

Run DFS starting from source.

After DFS, check if destination is marked visited.

Return the result.

Complexity
Time complexity:
O(N+E)

Space complexity:
O(N+E)

Code
*/

class Solution {
public:
    vector<int> adj_list[200005];
    bool vis[200005];

    void dfs(int src)
    {
        vis[src] = true;
        for(int child : adj_list[src])
        {
            if(!vis[child])
                dfs(child);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        memset(vis,false,sizeof(vis));
        dfs(source);
        return vis[destination];
    }
};