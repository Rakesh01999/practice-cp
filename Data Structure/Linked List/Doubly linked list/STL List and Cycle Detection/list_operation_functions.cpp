#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l = {10, 20, 20, 30, 10, 40, 50, 60, 70, 20, 80};
    // l.remove(20);
    l.sort();
    // l.sort(greater<int>());

    // l.unique(); // can work only in sorted list
    // l.reverse(); // can work only in sorted list
    
    for (int val : l)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
