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

const int maxn = 1e5 + 10;
const int MOD1 = 1e9 + 696969;
const int MOD2 = 1455847363;


long long pw1[maxn], hs1[maxn];
long long pw2[maxn], hs2[maxn];
int getHash1(const int &l, const int &r) {
    return ((hs1[r] - hs1[l - 1] * pw1[r - l + 1]) % MOD1 + MOD1) % MOD1;
}
int getHash2(const int &l, const int &r) {
    return ((hs2[r] - hs2[l - 1] * pw2[r - l + 1]) % MOD2 + MOD2) % MOD2;
}

int n, k;
string s;


bool check(const int &len) {
    map<pii, int> cnt;
    int lim = n - len + 1;
    for (int i = 1; i <= lim; i++) {
        cnt[{getHash1(i, i + len - 1), getHash2(i, i + len - 1)}]++;
    }
    for (const pair<pii, int> x : cnt) {
        if (x.second >= k) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("CAU4.INP", "r", stdin);
    freopen("CAU4.OUT", "w", stdout);

    cin >> n >> k;
    cin >> s;

    s = ' ' + s;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        hs1[i] = ((hs1[i - 1] << 8ll) + s[i]) % MOD1;
        pw1[i] = (pw1[i - 1] << 8ll) % MOD1;

        hs2[i] = ((hs2[i - 1] * 31ll) + (s[i] - 'A')) % MOD2;
        pw2[i] = (pw2[i - 1] * 31ll) % MOD2;
    }

    int l = 1, r = n, Ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            Ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << Ans;

    return 0;
}