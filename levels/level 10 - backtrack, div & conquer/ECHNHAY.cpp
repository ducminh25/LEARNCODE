#include <bits/stdc++.h>
using namespace std;
long long n, k;

long long solve(long long n, long long k) {
    if (k % n == 0) return n;
    else return solve(k % n, k % n + n);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("ECHNHAY.inp", "r")) {
        freopen("ECHNHAY.inp", "r", stdin);
        freopen("ECHNHAY.out", "w", stdout);
    }
    
    cin >> n >> k;
    if (n < k) cout << -1;
    cout << solve(n, k);

    return 0;
}