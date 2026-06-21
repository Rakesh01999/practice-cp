#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
queue<pair<int, int>>q;
vector<pair<int, int>>d={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int level[105][105];

bool valid(int ci, int cj){
    if(ci<0 || ci>=n || cj<0 || cj>=m)
        return false;
    return true;
}

void bfs(int si, int sj){
    q.push({si, sj});
    vis[si][sj]=true;
    level[si][sj]=0;
    while (!q.empty())
    {
        // node ber koro
        int pi=q.front().first;   
        int pj=q.front().second;   
        q.pop();
        
        // node niye kaj
        // cout<<pi<<" "<<pj<<endl;

        // child push
        for(int i=0;i<4;i++){
            int ci=pi+d[i].first;
            int cj=pj+d[i].second;

            if(valid(ci, cj) && !vis[ci][cj]){
                q.push({ci, cj});
                vis[ci][cj]=true;
                level[ci][cj]=level[pi][pj]+1;
            }
        }
    }
    
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    int si, sj, di, dj;
    cin>>si>>sj;
    cin>>di>>dj;
    bfs(si, sj);
    cout<<level[di][dj]<<endl;

    return 0;
}


// input :
// 3 4
// ....
// ....
// ....
// 1 2
// 2 0

// output:
// 1 2
// 0 2
// 0 1
// 1 1
// 2 1
// 2 0
// 1 0
// 0 0
// 2 2
// 2 3
// 1 3
// 0 3
