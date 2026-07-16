#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long res = 0, n, m;

void input() {
    cin >> n >> m;
    m--; // Tính cả ngày đầu
}

void solve() {
    long long weeks = m / 7;
    res += weeks * 2;
    long long remaining = m % 7;

    for (int i = n; i <= remaining + n; ++i) {
        if (i == 7 || i == 8 || i == 14 || i == 15) res++;
    }
    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("ANCHAY.inp", "r")) {
        freopen("ANCHAY.inp", "r", stdin);
        freopen("ANCHAY.out", "w", stdout);
    }
    
    input();
    solve();

    return 0;
}
