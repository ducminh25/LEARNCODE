#include <bits/stdc++.h>
using namespace std;
int t;
const int maxn = 1e5 + 5;
vector<int> primes;
bool is_prime[maxn];

void sieve() {
    fill(is_prime, is_prime + maxn, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < maxn; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < maxn; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

bool check(int n) {
    int count = 0;
    for (int p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            count++;
            while (n % p == 0) n /= p;
        }
        if (count >= 3) return true;
    }
    if (n > 1) count++;
    return count >= 3;
}

int find(int n) {
    int count = 0;
    for (int i = 30; ; ++i) {
        if (check(i)) {
            count++;
            if (count == n) return i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    if(fopen("TPRIMEFAC.inp", "r")) {
        freopen("TPRIMEFAC.inp", "r", stdin);
        freopen("TPRIMEFAC.out", "w", stdout);
    }

    sieve();
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << find(n) << '\n';
    }
    
    return 0;
}
