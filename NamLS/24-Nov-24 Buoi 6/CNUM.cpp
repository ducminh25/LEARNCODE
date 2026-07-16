#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
long long primes[maxn];
int N;
long long M;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    return b / gcd(a, b) * a;
}

long long cntdivisible(long long x) {
    return M / x;
}

long long solve(int i, long long curlcm, int sign) {
    if (i == N) {
        if (curlcm == 1) return 0;
        return sign * cntdivisible(curlcm);
    }

    long long res = solve(i + 1, curlcm, sign);
    if (curlcm <= M / primes[i]) {  // Check for overflow
        long long newlcm = lcm(curlcm, primes[i]);
        if (newlcm <= M)
            res += solve(i + 1, newlcm, -sign);
    }

    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    if (fopen("CNUM.inp", "r")) {
        freopen("CNUM.inp", "r", stdin);
        freopen("CNUM.out", "w", stdout);
    }

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> primes[i];
    }
    
    cout << solve(0, 1, -1) << "\n";
    
    return 0;
}