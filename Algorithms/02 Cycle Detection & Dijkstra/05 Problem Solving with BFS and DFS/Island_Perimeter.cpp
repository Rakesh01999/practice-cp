#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt;
    bool vis[105][105];
    vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
    int n,m;

    bool valid(int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }

    void dfs(int si,int sj,vector<vector<int>>& grid)
    {
        vis[si][sj] = true;
        for(int i=0;i<4;i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci,cj)==false)
                cnt++;
            else if(valid(ci,cj)==true && grid[ci][cj]==0)
                cnt++;
            else if(valid(ci,cj)==true && !vis[ci][cj] && grid[ci][cj]==1)
                dfs(ci,cj,grid);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        cnt = 0;
        n = grid.size();
        m = grid[0].size();
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j] && grid[i][j]==1)
                    dfs(i,j,grid);
        return cnt;
    }
};



// Intuition
// Think of each land cell as a square of side length 1.

// Initially, a cell has 4 sides.

// Each neighboring land cell removes 1 side from the perimeter.

// Using DFS:

// Traverse all land cells of the island.

// For each land cell, look in 4 directions.

// If it’s out of bounds → +1 to perimeter.

// If it’s water → +1 to perimeter.

// If it’s unvisited land → DFS deeper.

// Sum up all contributions.

// Approach
// Use a visited matrix to avoid recounting the same cell.

// Start DFS from the first land cell found.

// Keep a global counter cnt that adds perimeter contributions.

// Finally, return cnt.

// Complexity
// Time complexity:
// O(N*M)

// Space complexity:
// O(N*M)