#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& u : a) cin >> u;

    vector<vector<int>> vh(n + 2);
    for (int i = 0; i < n; i++) vh[a[i]].pb(i);
    vector<pair<int, int>> dp;
    dp.pb({-1, 0});

    for (int val = n; val >= 0; val--) {
        if (vh[val].empty()) {
            int mindp = 1e9;
            for (auto [p, v] : dp) 
                mindp = min(mindp, v);
            dp = {{-1, mindp}};

        } 
        else {
            vector<int> lps = {-1};
            for (int u : vh[val]) lps.pb(u);

            vector<pair<int, int>> newdp;
            int id = 0, min_ers = 1e9;
            for (int j = 0; j < sz(lps); j++) {
                int ers = sz(vh[val]) - j;
                while (id < sz(dp) && dp[id].first <= lps[j]) {
                    min_ers = min(min_ers, dp[id].second + max(0, j - 1));
                    id++;
                }
                newdp.pb({lps[j], ers + min_ers});
            }

            int mindp = 1e9;
            for (auto [p, v] : dp) mindp = min(mindp, v);
            newdp[0].second = mindp + sz(vh[val]);
            swap(dp, newdp);
        }
    }
    cout << dp[0].second << '\n';
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("LOCKOUT.inp", "r")) {
        freopen("LOCKOUT.inp", "r", stdin);
        freopen("LOCKOUT.out", "w", stdout);
    }

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}