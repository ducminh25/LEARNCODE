#include <bits/stdc++.h>
using namespace std;
long long n, tmp;
long long s;
long long tinh_luy_thua(long long a, long long b) {
    long long hs = 20122007;
    if (b == 0) return 1;
    tmp = tinh_luy_thua(a, b / 2);
    tmp = tmp * tmp % hs;
    if (b % 2 == 0) {
        return tmp;
    } else {
        return (tmp * (a % hs)) % hs;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("MYSTERY.INP", "r")) {
        freopen("MYSTERY.INP", "r", stdin);
        freopen("MYSTERY.OUT", "w", stdout);
    }
    cin >> n;
    s = 1;
    for (int i = 1; i <= (int)(sqrt)(n); ++i) {
        if (n % i == 0) {
            s = (s * (tinh_luy_thua(3, i) - 1)) % 20122007;
            if (i != n / i) s = (s * (tinh_luy_thua(3, n / i) - 1)) % 20122007;
        }
    }
    cout << s;

    return 0;
}
