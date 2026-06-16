#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m)
    {
        return false;
    }
    return true;
}

bool bfs(int ri, int rj, int di, int dj) {
    queue<pair<int, int>> q;
    q.push({ri, rj});
    vis[ri][rj] = true;
    parent[ri][rj] = {-1, -1};
    
    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        
        if (par_i==di && par_j==dj) {
            return true;
        }
        
        for (int i=0;i<4;i++) {
            int ci = par_i+d[i].first;
            int cj = par_j+d[i].second;
            
            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D')) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
    return false;
}

int main() {
    int di,dj,ri, rj;cin>>n>>m;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='D') {
                di=i,dj=j;
            }
            if(grid[i][j]=='R')  {
                ri=i,rj=j;
            }
        }
    }
     memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    
    if (bfs(ri,rj,di,dj)){
        int x=di, y=dj;
        while (parent[x][y].first != -1)  {
            int px = parent[x][y].first;
            int py = parent[x][y].second;

            if (px != ri || py != rj) {
                grid[px][py] = 'X';
            }
            x = px;
            y = py;
        }
    }
    
    for (int i= 0; i < n;i++){
        for (int j = 0; j < m; j++){
            cout << grid[i][j];
        }cout<<endl;
    }
    
    return 0;
}
