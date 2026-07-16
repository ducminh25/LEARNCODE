#include <bits/stdc++.h>
using namespace std;
uint64_t n;
const int MOD = 2023;

void input() {
    cin >> n;
}

// T = 2 + 5 + 8 + ... + (3*n - 1)
// T = n * (2 + (3n - 1)) / 2 = n * (3n + 1) / 2
void solve() {
    uint64_t n_mod = n % MOD;
    uint64_t tmp1 = (3 * n_mod) % MOD;
    uint64_t tmp2 = (tmp1 + 1) % MOD;
    uint64_t tmp3 = (n_mod * tmp2) % MOD;

    uint64_t res;
    if (tmp3 % 2 == 0)
        res = tmp3 / 2;
    else
        res = (tmp3 + MOD) / 2;

    cout << res << '\n';
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("DONGDU.inp", "r")) {
        freopen("DONGDU.inp", "r", stdin);
        freopen("DONGDU.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

// Xác định số dư R = T mod 2023
