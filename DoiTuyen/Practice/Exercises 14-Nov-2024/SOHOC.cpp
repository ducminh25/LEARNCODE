#include <bits/stdc++.h>
using namespace std;

vector<long long> getFactors(long long n) {
    vector<long long> factors;
    for (long long i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    long long sq = sqrt(n);
    for (long long i = 5; i <= sq; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("SOHOC.inp", "r")) {
        freopen("SOHOC.inp", "r", stdin);
        freopen("SOHOC.out", "w", stdout);
    }
    
    long long n;
    cin >> n;

    auto factors = getFactors(n);
    cout << factors.size() << endl;

    long long maxfactor = 1;
    for (long long p : factors) {
        if (isPrime(p) && p > maxfactor) {
            maxfactor = p;
        }
    }
    cout << maxfactor << endl;

    return 0;
}