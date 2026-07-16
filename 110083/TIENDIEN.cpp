#include <bits/stdc++.h>
using namespace std;
long long x, res = 0;

void input() {
    cin >> x;
}

void solve() {
    if (x <= 100) res += 2000 * x;
    else {
        res += 100 * 2000;
        x -= 100;
        if (x <= 100) res += 3000 * x;
        else {
            res += 100 * 3000;
            x -= 100;
            if (x <= 100) res += 5000 * x;
            else {
                res += 100 * 5000;
                x -= 100;
                res += 10000 * x;
            }
        }
    }

    cout << res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("TIENDIEN.inp", "r")) {
        freopen("TIENDIEN.inp", "r", stdin);
        freopen("TIENDIEN.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}