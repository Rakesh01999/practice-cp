#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
queue<int> q;

void bfs(int src)
{
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        // node ber koro
        int par = q.front();
        q.pop();

        // node niye kaj
        cout << par << " ";

        // children push

        for (int child : adj_list[par])
        {
            if (!vis[child])
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

    int src, dst;
    cin >> src >> dst;

    bfs(src);
    cout<<endl;

    if (vis[dst])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
