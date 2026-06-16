#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edge_list; // vector of pair

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }
    
    cout<<"Output :"<<endl;
    for (pair<int, int> p : edge_list)
    {
        cout << p.first << " " << p.second<<endl;
    }

    return 0;
}