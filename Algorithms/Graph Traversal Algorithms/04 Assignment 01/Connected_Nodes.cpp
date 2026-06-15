#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
set<int> nodes;
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        nodes.insert(a);
        nodes.insert(b);
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {

    int p;
    cin >> p;
    bool found = nodes.count(p);
    if (found)
    {
        sort(adj_list[p].begin(), adj_list[p].end());
        reverse(adj_list[p].begin(), adj_list[p].end());

        for (int x : adj_list[p])
        {
            cout << x << " ";
        }cout<<endl;
    }
    else
    {
        cout << -1 << endl;
    }

    }

    return 0;
}