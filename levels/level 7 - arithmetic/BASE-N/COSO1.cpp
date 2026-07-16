#include <bits/stdc++.h>
using namespace std;

int r;
string s;

void solve ()
{
    long long p [20], res = 0;
    int x;
    int n = s.size ();
    p [0] = 1;
    for (int i = 1; i <= n; ++i) p [i] = p [i - 1] * r;
    for (int i = 0; i < n; ++i)
    {
        if ('0' <= s [i] && s [i] <= '9') x = int (s[i]) - 48;
        else x = int (s[i]) - 55;
        res = res + p [n - 1 - i] * x;
    }
    cout << res << "\n";
}

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> s;
        cin >> r;
        solve ();
    }
    return 0;
}