#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[105];
bool vis[105];
queue<int>q;

void bfs(int src){
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        // node ber koro
        int par=q.front();
        q.pop();
        
        // node niye kaj
        cout<<par<<" ";

        // child push
        for(int child:adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
            }
        }
    }
}

int main(){
    int n, e;cin >> n >> e;
    while(e--){
        int a, b;cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    cout<<"output : "<<endl;
    bfs(0);
    
    return 0;
}




// input:
// 5 5
// 0 1
// 1 2
// 0 3 
// 1 3
// 2 4

// output : 
// 0 1 2 4 3 
