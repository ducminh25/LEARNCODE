#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int m = 1000000007;
int n, k;
int a[maxn];

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void solve() {
    vector<vector<int>> dp(maxn, vector<int>(k, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i][(j + a[i] % k + k) % k] = (dp[i][(j + a[i] % k + k) % k] + dp[i-1][j]) % m;
            dp[i][(j - a[i] % k + k) % k] = (dp[i][(j - a[i] % k + k) % k] + dp[i-1][j]) % m;
        }
    }

    cout << dp[n][0] << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("SEQSIGN.inp", "r")) {
        freopen("SEQSIGN.inp", "r", stdin);
        freopen("SEQSIGN.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
