
#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> adj_list[1005];
bool vis[1005];

void bfs(int src)
{
    q.push(src);
    vis[src] = true;
    while (!q.empty())                      // O(V)
    {
        // node ber koro
        int par = q.front();
        q.pop();

        // node niye kaj
        cout << par << " ";

        // children push
        for (int child : adj_list[par])     // not depends on outer loop instead of inner condition . O(E)
        {
            if (!vis[child])                // this condition
                q.push(child);
                vis[child] = true;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs(0);

    return 0;
}