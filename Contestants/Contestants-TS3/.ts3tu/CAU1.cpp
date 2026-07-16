#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define pii pair<int, int>

using namespace std;

template <class T>
T gcd(T a, T b) {
    if (a == 0) return b;
    if (b == 0) return a;
    int shift = __builtin_ctzll((long long)(a | b));
    a >>= __builtin_ctzll((long long)a);
    do {
        b >>= __builtin_ctzll((long long)b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

const int lim = 500000;

bool nPrime[lim + 10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);

    nPrime[0] = nPrime[1] = 1;
    for (int i = 2; i * i <= lim; i++) if (nPrime[i] == 0) {
        for (int j = i * i; j <= lim; j += i) {
            nPrime[j] = 1;
        }
    }

    int l, r;
    cin >> l >> r;

    int Ans = 0;
    for (int i = l + 1; i <= r; i++) {
        long long x = 1ll * i * i - 1ll * (i - 1) * (i - 1);
        if (nPrime[x] == 0) {
            Ans++;
        }
    }

    cout << Ans;

    return 0;
}