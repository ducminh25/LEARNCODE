#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 9;

long long fastPower(long long a, long long n) {
    if (n == 0) return 1;
    if (n == 1) return a % MOD;

    long long temp = fastPower(a % MOD, n / 2);
    temp = (temp * temp) % MOD;

    if (n % 2 == 0)
        return temp;
    else
        return (temp * (a % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("POWER.inp", "r")) {
        freopen("POWER.inp", "r", stdin);
        freopen("POWER.out", "w", stdout);
    }

    int t;
    cin >> t;
    while(t--) {
        long long a, n;
        cin >> a >> n;
        cout << fastPower(a, n) << endl;
    }

    return 0;
}

//Code mau cua thay Vinh bi sai:
// #include <bits/stdc++.h>
// using namespace std;
// long long t, a, n, s, m = 1000000009;
// long long lt(long long a, long long n) {
//     if (n == 0) return 1;
//     long long t = lt(a, n / 2);
//     t = ((t % m) * (t % m)) % m;
//     if (n % 2 == 0) return t;
//     return ((t % m) * (a % m)) % m;
// }
// int main() {
//     // freopen("POWER.inp", "r", stdin);
//     // freopen("POWER.out", "w", stdout);
//     scanf("%lld", &t);
//     for (int i = 1; i <= t; i++) {
//         scanf("%1ld%lld", &a, &n);
//         s = lt(a, n);
//         printf("%lld\n", s);
//     }
// }