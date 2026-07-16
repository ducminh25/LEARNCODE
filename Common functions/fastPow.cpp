#include <bits/stdc++.h>
using namespace std;
int n, a, m;

// a ^ n
long long fastPower(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    
    long long temp = fastPower(a, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else
        return temp * temp * a;
}

const int MOD = 1e9 + 7;
// a ^ n MOD m
long long modPow(long long a, long long n, int m) {
    // m = MOD;
    a %= m;
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL); cout.tie (NULL);
    
    cin >> n >> a >> m;
    cout << fastPower(a, n) << endl;
    // cout << modPow(a, n, m);

    return 0;
}
