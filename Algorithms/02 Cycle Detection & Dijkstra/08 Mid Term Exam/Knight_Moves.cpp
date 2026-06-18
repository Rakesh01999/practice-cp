#include<bits/stdc++.h>
using namespace std;

int n, m;
bool vis[105][105];
vector<pair<int, int>> d = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};

bool valid(int ci, int cj) {
    if(ci < 0 || ci >= n || cj < 0 || cj >= m){
        return false;
    }return true;
}

int knightMoves(int kx,int ky,int qx,int qy) {
    if (kx == qx && ky == qy) {
        return 0;
    }
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{kx, ky}, 0});
    vis[kx][ky] = true;
    
    while (!q.empty()){
        pair<pair<int,int>,int>current = q.front();
        q.pop();
        
        int x = current.first.first;
        int y = current.first.second;
        int steps = current.second;
        
        for (int i= 0; i<8; i++) {
            int nx = x + d[i].first;
            int ny = y + d[i].second;
            
            if(valid(nx, ny) && !vis[nx][ny]){
                if (nx == qx && ny == qy){
                    return steps + 1;
                }
                
                vis[nx][ny]=true;
                q.push({{nx,ny},steps+1});
            }
        }
    }
    return -1;
}

int main(){
    int t;cin>>t;
    
    while(t--){
        cin>>n>>m;
        
        memset(vis, false, sizeof(vis));
    
        int kx, ky, qx, qy;
        cin >> kx >> ky;
        cin >> qx >> qy;
        
        int result = knightMoves(kx, ky, qx, qy);
        cout << result << endl;
    }
    
    return 0;
}
