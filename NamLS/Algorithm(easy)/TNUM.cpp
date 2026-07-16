#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

bool check(long long n) {
    long long sq = sqrtl(n);
    if(sq * sq != n) return false;

    return isPrime(sq);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("TNUM.INP", "r")) {
        freopen("TNUM.INP", "r", stdin);
        freopen("TNUM.OUT", "w", stdout);
    }
    
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        if(!check(n)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}