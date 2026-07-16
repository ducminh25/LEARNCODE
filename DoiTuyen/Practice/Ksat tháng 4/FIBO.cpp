#include <bits/stdc++.h>
using namespace std;

bool scp(long long x) {
    long long s = sqrt(x);
    return s * s == x;
}

bool fibo(long long n) {
    return scp(5 * n * n + 4) || scp(5 * n * n - 4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen ("FIBO.INP", "r", stdin);
    freopen ("FIBO.OUT", "w", stdout);
    long long n, count = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long num;
        cin >> num;
        if (fibo(num)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}