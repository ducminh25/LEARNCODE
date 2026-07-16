#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    if (!(cin >> n >> k >> q)) return;

    vector<int> is_min(n + 1, 0);
    vector<int> is_mex(n + 1, 0);

    for (int i = 0; i < q; ++i) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) { 
            for (int j = l; j <= r; ++j) is_min[j] = 1;
        } else { 
            for (int j = l; j <= r; ++j) is_mex[j] = 1;
        }
    }

    vector<int> a(n + 1);
    int mex_cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (is_min[i] && is_mex[i]) {
            a[i] = k + 1;
        } 
        else if (is_min[i]) {
            a[i] = k;
        } 
        else if (is_mex[i]) {
            a[i] = mex_cnt % k;
            mex_cnt++;
        } 
        else {
            a[i] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("mexarray.inp", "r")) {
        freopen("mexarray.inp", "r", stdin);
        freopen("mexarray.out", "w", stdout);
    }
    int t;
    if (cin >> t)
        while (t--) solve();
        
    return 0;
}