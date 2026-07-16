#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 1e4 + 5;
vector<int> a, b;
int m, n;

void input() {
    cin >> m >> n;
    a.resize(m); b.resize(n);
    for(int i = 0; i < m; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
}

void solve() {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int res = 0;
    for(int i = 0; i < n; ++i)
        res += abs(a[i] - b[i]);
    
    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("DUTIEC.inp", "r")) {
        freopen("DUTIEC.inp", "r", stdin);
        freopen("DUTIEC.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
