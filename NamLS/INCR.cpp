#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxd = 1e9 + 5;
long long n, a[maxn], d;

void input() {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

void solve() {
    long long steps = 0;
    long long prev = a[0];

    for (int i = 1; i < n; ++i) {
        if (a[i] <= prev) {
            long long diff = prev - a[i] + 1;
            long long incr = (diff + d - 1) / d;
            steps += incr;
            a[i] += incr * d;
        }
        prev = a[i];
    }
    cout << steps << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("INCR.inp", "r")) {
        freopen("INCR.inp", "r", stdin);
        freopen("INCR.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
