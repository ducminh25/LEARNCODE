#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
        dp[i] = dp[i - 1] + 1;
        } else {
        dp[i] = 1;
        }
        cout<<dp[i];
    }
/*    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[i]);
    }

    cout << res << endl;
*/
    return 0;
}
