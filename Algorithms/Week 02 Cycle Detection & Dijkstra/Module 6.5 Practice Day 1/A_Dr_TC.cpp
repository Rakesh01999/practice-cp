#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;cin >> n;
        string s;cin >> s;
        int cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                cnt1++;
        }
        int ans = 0;
        // for (int i = 0; i < n; i++)
        for(char c:s)
        {
            if (c == '0')
                ans += cnt1 + 1;
            else
                ans += cnt1 - 1;
        }
        cout << ans << endl;
    }
    return 0;
}