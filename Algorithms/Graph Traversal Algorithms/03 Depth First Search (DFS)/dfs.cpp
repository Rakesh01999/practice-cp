#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list [1005];
bool vis [1005];

void dfs(int src){
    cout<<src <<" ";
    vis[src] = true;
    for(int child: adj_list[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    int v, e;cin>>v>>e;
    while (e--)
    {
        int a, b;cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    dfs(0);
    
    return 0 ;
}

// Input:
// 7 7
// 0 1
// 0 2
// 0 3
// 1 4
// 4 5
// 5 2
// 3 6

// Output:
// 0 1 4 5 2 3 6
