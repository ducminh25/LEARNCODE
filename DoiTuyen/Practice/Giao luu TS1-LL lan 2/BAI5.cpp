#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
vector<int> a;

void input() {
    cin >> n;
    a.resize(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

void solve() {
    sort(a.begin(), a.end());
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 != 0) res += a[i];
        else res -= a[i];
    }
    
    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI5.inp", "r")) {
        freopen("BAI5.inp", "r", stdin);
        freopen("BAI5.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
