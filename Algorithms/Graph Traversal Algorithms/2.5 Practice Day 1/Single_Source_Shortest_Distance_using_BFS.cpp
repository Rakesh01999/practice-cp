#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int level[1005];
queue<int> q;

void bfs(int src)
{
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        // node ber koro
        int par = q.front();
        q.pop();

        // node niye kaj
        // cout << par << " ";

        // children push

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
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
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    int src, dst;
    cin >> src >> dst;

    bfs(src);
    cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> " << level[i] << endl;
    // }
    cout<<level[dst]<<endl;
    return 0;
}
