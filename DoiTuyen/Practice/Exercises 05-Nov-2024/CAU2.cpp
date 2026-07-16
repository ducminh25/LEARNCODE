#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU2.inp", "r")) {
        freopen("CAU2.inp", "r", stdin);
        freopen("CAU2.out", "w", stdout);
    }

    long long l, r, x;
    cin >> l >> r >> x;

    bool run = false;
    long long k = 1;
    while (k <= r) {
        if (k >= l) {
            cout << k << " ";
            run = true;
        }
        k *= x;
    }
    if (!run) {
        cout << -1;
    }
    return 0;
}