#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
int parent[105];
int n, e;
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << " ";
        for (int child : adj_list[par])
        {
            if(vis[child] && parent[par] != child){
                cycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }cout<<endl;
    if (cycle)
    {
        cout<<"Cycle Detected"<<endl;
    }
    else{
        cout<<"No Cycle"<<endl;
    }
    
    return 0;
}


// Sample - 1:
// input:
// 6 6
// 0 1
// 0 2
// 1 3
// 2 3
// 4 5
// 5 6

// output:
// 0 1 2 3 4 5 6 
// Cycle Detected


// Sample - 2:
// input :
// 7 5
// 0 1
// 0 2
// 1 3
// 4 5
// 5 6

// output:
// 0 1 2 3 4 5 6 
// No Cycle