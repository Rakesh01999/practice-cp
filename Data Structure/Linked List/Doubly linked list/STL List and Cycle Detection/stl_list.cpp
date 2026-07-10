#include <bits/stdc++.h>
using namespace std;
int main()
{
    // list<int>l(10,3);
    // for (auto it = l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // list<int> l = {1, 2, 3, 4, 5};
    // list<int> l2(l);

    // int a[]={10,20,30};
    // list<int>l3(a, a+3);

    vector<int> v = {45, 55, 65};
    list<int> l4(v.begin(), v.end());

    // l4.clear();
    // cout << "size :" << l4.size() << endl;
    // if (l4.empty())
    // {
    //     cout << "Empty" << endl;
    // }

    // l4.resize(2);
    // l4.resize(5);
    l4.resize(5, 37);

    for (int val : l4)
    {
        cout << val << " ";
    }
    return 0;
}
