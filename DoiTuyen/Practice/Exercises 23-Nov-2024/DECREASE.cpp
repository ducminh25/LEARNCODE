#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("DECREASE.inp", "r")) {
        freopen("DECREASE.inp", "r", stdin);
        freopen("DECREASE.out", "w", stdout);
    }

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int x = i; x > 0; x /= 10) {
            int digit = x % 10;
            if (digit != 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}