#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, k;
int a[maxn], b[maxn];
int dp[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("LKH.INP", "r")) {
        freopen ("LKH.INP", "r", stdin);
        freopen ("LKH.OUT", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = b[i];
        for (int j = 1; j < i; j++) {
            if (a[i] - a[j] > k) {
                dp[i] = max(dp[i], dp[j] + b[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;

    return 0;
}