#include <bits/stdc++.h>
using namespace std;
int freq[260];
int n, a[100005];
int res;

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
}

void solve() {
    int maxx = 0;
    for (int i = 1; i <= 250; ++i) {
        maxx = max(maxx, freq[i]);
    }

    res = INT_MIN;
    for (int i = 1; i <= 250; ++i) {
        if (freq[i] == maxx) {
            res = max(res, i);
        }
    }
    cout << res << " " << maxx << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("DOIHINH.inp", "r")) {
        freopen("DOIHINH.inp", "r", stdin);
        freopen("DOIHINH.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
