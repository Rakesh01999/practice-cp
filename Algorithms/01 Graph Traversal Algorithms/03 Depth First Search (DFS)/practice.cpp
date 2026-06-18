#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        // cout<<ci<<" "<<cj<<endl;
        if (valid(ci, cj) && !vis[ci][cj])
            dfs(ci, cj);
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
    cout << "output:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    // memset(vis, false, sizeof(vis));
    // int si, sj;
    // cin >> si >> sj;
    // dfs(si, sj);

    return 0;
}

// input :
// 3 4
// ....
// ....
// ....
// 1 2

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
