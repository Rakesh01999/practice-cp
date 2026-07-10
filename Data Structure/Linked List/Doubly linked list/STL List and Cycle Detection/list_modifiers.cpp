#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l = {10, 20, 30, 40, 50, 60, 70, 80};
    list<int> l2;
    list<int> l3 = {100, 200};
    vector<int> v = {1, 3, 5};
    // l2 = l;
    // list<int> l2(l);
    l2.assign(l.begin(), l.end());

    // l.push_back(40);
    // l.pop_back();
    // l.push_front(1);
    // l.pop_front();

    // cout<<*next(l.begin(), 2)<<endl;
    // l.insert(next(l.begin(), 2), 100);
    // l.insert(next(l.begin(),2), l3.begin(), l3.end());
    // l.insert(next(l.begin(),2), v.begin(), v.end());

    // l.erase(next(l.begin(), 2));
    // l.erase(next(l.begin(), 2), next(l.begin(), 5));

    replace(l.begin(), l.end(), 20, 100);
    auto it = find(l.begin(), l.end(), 2);
    if (it == l.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }


    for (int val : l)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
