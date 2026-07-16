#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    //freopen("SEQDIV.INP", "r", stdin);
    //freopen("SEQDIV.OUT", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    vector<long long> dp(k+1, 1);
    vector<long long> sum(k+1, 0);  

    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= k; j += i) {
            sum[j] += dp[i];
            sum[j] %= MOD;
        }
    }

    for (int len = 2; len <= n; len++) 
    {
        for (int i = 1; i <= k; i++) {
            dp[i] = sum[i];
            sum[i] = 0;
        }
        for (int i = 1; i <= k; i++) {
            for (int j = i; j <= k; j += i) {
                sum[j] += dp[i];
                sum[j] %= MOD;
            }
        }
    }

    long long result = 0;
    for (int i = 1; i <= k; i++) {
        result += dp[i];
        result %= MOD;
    }

    cout << result << endl;
    return 0;
}