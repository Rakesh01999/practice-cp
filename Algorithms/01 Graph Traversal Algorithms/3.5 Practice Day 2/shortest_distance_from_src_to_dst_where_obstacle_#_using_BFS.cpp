// shortest_distance_from_src_to_dst_where_obstacle_#_using_BFS

#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// bool valid(int ci, int cj){
//     if(ci < 0 || ci >= n || cj < 0 || cj >= m)
//         return false;
//     return true;
// }
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        // cout<<par_i<<" "<<par_j<<endl;
        for (int i=0;i<4;i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj]=='.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    dfs(si, sj);
    cout<<level[di][dj]<<endl;
    return 0;
}

// input :
// 3 4
// ....
// .#..
// .#..     // '#' obstacle during traverese we can't cross over '#'
// 1 2      // src idx(row, col)
// 2 0      // dst idx(row, col)

// output:
// 3

