#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list [105];
bool vis [105];
int parent [105];
bool cycle;

void dfs(int src){
    vis[src] = true;
    for(int child :adj_list[src]){
        if(vis[child] && parent[src] != child){
            cycle = true;
        }
        if(!vis[child]){
            parent[child] = src;
            dfs(child);
        }
    }
}

int main(){
    int n, e;cin>>n>>e;
    while (e--)
    {
        int a, b;cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    dfs(0);
    cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<i<<"parent :"<<parent[i]<<endl;
    // }
    
    if(cycle)
        cout<<"Cycle Detected"<<endl;
    else 
        cout<<"No Cycle"<<endl;

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
// Cycle Detected


// Sample - 2:
// input :
// 7 5
// 0 1
// 0 2
// 1 3
// 4 5
// 5 6

// output :
// No Cycle
