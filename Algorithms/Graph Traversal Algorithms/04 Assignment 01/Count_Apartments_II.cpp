#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> apart;
int n, m;
int cnt;

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= m)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                apart.push_back(cnt);
            }
        }
    }

    if (apart.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    sort(apart.begin(), apart.end());

    // for (int i = 0; i < apart.size(); i++)
    // {
    //     cout << apart[i];
    //     if (i + 1 < apart.size())
    //         cout << " ";
    // }
    // cout << endl;
    for (int i = 0; i < apart.size(); i++)
    {
        cout << apart[i] << " ";
    }cout << endl;

    return 0;
}
