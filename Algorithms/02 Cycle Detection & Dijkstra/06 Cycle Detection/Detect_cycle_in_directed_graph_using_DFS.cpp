#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[105];
bool vis [105];
bool pathVis [105];
bool cycle ;

void dfs(int src){
    vis[src] = true;
    pathVis[src] = true;
    for(int child: adj_list[src]){
        if(vis[child] && pathVis[child]){
            cycle = true;
        }
        if(!vis[child]){
            dfs(child);
        }
    }
    // return 
    pathVis[src] = false;
}

int main(){
    int n, e;cin>>n>>e;
    while (e--)
    {
        int a, b;cin>>a>>b;
        adj_list[a].push_back(b);
    }
    
    dfs(0);
    
    if(cycle)
        cout<<"Cycle Detected"<<endl;
    else 
        cout<<"No Cycle"<<endl;

    return 0;
}


// Sample - 1:
// input:
// 7 6
// 0 1
// 0 2
// 1 3
// 3 2
// 4 5
// 5 6

// output:
// No Cycle


// Sample - 2:
// input:
// 7 6
// 0 1
// 2 0
// 1 3
// 3 2
// 4 5
// 5 6

// output:
// Cycle Detected
