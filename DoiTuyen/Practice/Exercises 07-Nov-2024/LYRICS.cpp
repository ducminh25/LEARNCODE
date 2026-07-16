#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[1005];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("LYRICS.inp", "r")) {
        freopen("LYRICS.inp", "r", stdin);
        freopen("LYRICS.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    int k = 0, j;
    for (int i = 1; i <= n - m; ++i)
    {
        string s1 = s[i];
        string s2 = s[i + m];
        j = 0;
        while (j <= min(s1.length(), s2.length()) &&
               s1[s1.length() - j - 1] == s2[s2.length() - j - 1]) {
            j++;
        }
        // cout << k << " " << j << " ";
        k = max(k, j);
    }
    cout << k << endl;

    return 0;
}
