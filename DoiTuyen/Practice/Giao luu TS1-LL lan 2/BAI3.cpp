#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k, a[maxn];
bool ok[maxn];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
}

void solve() {
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        if (ok[i]) continue;
        int j = i;
        vector<int> vals;
        while (!ok[j]) {
            vals.push_back(a[j]);
            ok[j] = true;
            j = (j + k - 1) % n + 1;
        }

        sort(vals.begin(), vals.end());
        int med = vals[vals.size() / 2];
        for (int l = 0; l < vals.size(); l++)
            res += abs(vals[l] - med);
    }

    cout << res << endl;
}

signed main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("BAI3.INP", "r")) {
        freopen("BAI3.INP", "r", stdin);
        freopen("BAI3.OUT", "w", stdout);
    }

    input();
    solve();

    return 0;
}
