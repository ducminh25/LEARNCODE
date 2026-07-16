#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005;
int n, h[maxn];

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
}

void solve() {
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            res += h[i] * h[j];
        }
    }

    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU2.inp", "r")) {
        freopen("CAU2.inp", "r", stdin);
        freopen("CAU2.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
