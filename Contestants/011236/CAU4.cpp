#include <bits/stdc++.h>
using namespace std;
int m, n, k;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU4.inp", "r")) {
        freopen("CAU4.inp", "r", stdin);
        freopen("CAU4.out", "w", stdout);
    }

    cin >> m >> n >> k;
    vector<vector<int>> height(m + 1, vector<int>(n + 1, 0));
    for (int p = 0; p < k; ++p) {
        int xp, yp, up, vp;
        cin >> xp >> yp >> up >> vp;
        height[xp][yp]++;
        if (up + 1 <= m) height[up + 1][yp]--;
        if (vp + 1 <= n) height[xp][vp + 1]--;
        if (up + 1 <= m && vp + 1 <= n) height[up + 1][vp + 1]++;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i > 1) height[i][j] += height[i - 1][j];
            if (j > 1) height[i][j] += height[i][j - 1];
            if (i > 1 && j > 1) height[i][j] -= height[i - 1][j - 1];
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxSize = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
            } 
            else if (height[i][j] == height[i - 1][j] && 
                        height[i][j] == height[i][j - 1] && 
                        height[i][j] == height[i - 1][j - 1]) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            } 
            else
                dp[i][j] = 1;
            maxSize = max(maxSize, dp[i][j]);
        }
    }
    cout << maxSize;

    return 0;
}