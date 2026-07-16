#include <bits/stdc++.h>
using namespace std;

long long res(long long n, long long k) {
    long long cnt = 0;

    if (k > 1 && k <= 2 * n) {
        long long l = max(1LL, k - n);
        long long r = min(n, k - 1);
        cnt = r - l + 1;
    }

    return cnt / 2;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("TONGBANGK.inp", "r")) {
        freopen("TONGBANGK.inp", "r", stdin);
        freopen("TONGBANGK.out", "w", stdout);
    }

    long long a, b;
    cin >> a >> b;
    cout << res(a, b);

    return 0;
}

/*
Đếm số cặp (a, b) trong dãy số đã cho sao cho a + b = K. Cặp (a, b) và (b, a) được coi là một cặp.
*/