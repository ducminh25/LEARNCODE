#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define Unique(v) \
    sort(all(v)); \
    (v).erase(unique(all(v)), (v).end());
ll n, cnt;

bool isPrime(ll n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

bool check(ll n) {
    ll s = 0;
    for (int i = 1; i * i < n; i++)
        if (n % i == 0) s += i + n / i;
    ll k = sqrt(n);
    if (k * k == n) s += k;
    return isPrime(s);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define task "SPRIME"
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }

    cin >> n;
    cnt = (n >= 2);
    for (int i = 2; i * i <= n; i++) {
        if (check(i * i)) cnt++;
    }
    cout << cnt;
}

/*
Cho số nguyên dương n (n <= 10^8). Yêu cầu đếm trong đoạn từ 1 đến n xem có bao nhiêu số có tổng các ước dương là một số nguyên tố.
sumDiv prime
*/