#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;
const long long INF = 1e18;
long long a[MAXN];
long long dp[MAXN];
int n, m;

long long cost(int l, int r) {
    return a[r] - a[l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CHIANHOM.INP", "r")) {
        freopen("CHIANHOM.INP", "r", stdin);
        freopen("CHIANHOM.OUT", "w", stdout);
    }
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        dp[i] = INF;
    }
    
    dp[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = n - 1; j >= i - 1; --j) {
            for (int k = i - 2; k < j; ++k) {
                dp[j] = min(dp[j], dp[k] + cost(k + 1, j));
            }
        }
    }
    cout << dp[n - 1] << "\n";
    
    return 0;
}
