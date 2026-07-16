#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen ("MBRACKETS.inp", "r", stdin);
    freopen ("MBRACKETS.out", "w", stdout);

    int t, n;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> n >> s;
        int ans = 0, open = 0, close = 0;
        for(int i = 0; i < n; ++i)
        {
            if (s[i] == '(' && s[i+1] == ')')
            {
                i++;
                continue;
            }

            if (s[i] == '('){
                open++;
            }

            if (s[i] == ')')
            {
                close++;
                if (open < close)
                    ans++, close--; // I can't imagine this thing.
            }
        }
        cout << ans << endl;
    }
    return 0;
}