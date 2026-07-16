#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n;
int t[MAXN], p[MAXN];
long long dp[MAXN];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("WORK.inp", "r")) {
        freopen("WORK.inp", "r", stdin);
        freopen("WORK.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i < n; ++i)
        cin >> p[i];

    dp[0] = 0;
    dp[1] = t[1];
    for (int i = 2; i <= n; ++i)
        dp[i] = min(dp[i-1] + t[i], dp[i-2] + p[i-1]);

    cout << dp[n] << endl;

    return 0;
}
