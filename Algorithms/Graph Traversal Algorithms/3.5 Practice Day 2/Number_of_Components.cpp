#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[105];
bool vis[105];

void dfs(int src){
    // cout<<src<<" ";
    vis[src] = true;
    for(int child: adj_list[src]){
        if(!vis[child])
            dfs(child);
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
    
    int count_component=0;
    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){
            dfs(i);
            count_component++;
        }
    }
    cout<<count_component<<endl;
        
    return 0;
}

// input:
// 8 6
// 0 5
// 5 4
// 6 7
// 1 2
// 1 3
// 2 3

// output:
// 3
