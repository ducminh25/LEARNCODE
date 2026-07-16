#include <bits/stdc++.h>
using namespace std;

vector<long long> findDivisors(long long n) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("DIVISOR.INP", "r")) {
        freopen("DIVISOR.INP", "r", stdin);
        freopen("DIVISOR.OUT", "w", stdout);
    }

    long long n, k;
    cin >> n >> k;

    vector<long long> divisors = findDivisors(n);
    if (k > divisors.size()) {
        cout << -1 << endl;
    } else {
        cout << divisors[k-1] << endl;
    }

    return 0;
}