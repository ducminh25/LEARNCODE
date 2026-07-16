// Phân tích t số nguyên thành thừa số nguyên tố, cùng với số mũ.
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12 + 5; // Chương trình này có thể chạy được với số lên đến 10^12
const int MAXN = 1000005; // 1e6 + 5
bool is_prime[MAXN];
vector<int> primes;

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXN; ++i)
        if (is_prime[i])
            for (int j = i * i; j < MAXN; j += i)
                is_prime[j] = false;

    for (int i = 2; i < MAXN; ++i)
        if (is_prime[i]) primes.push_back(i);
}

vector<pair<long long, int>> factorize(long long n) {
    vector<pair<long long, int>> res;
    for (int p : primes) {
        if (1LL * p * p > n) break;
        int count = 0;
        while (n % p == 0) {
            ++count;
            n /= p;
        }
        if (count > 0) res.push_back({p, count});
    }
    if (n > 1) res.push_back({n, 1});
    
    return res;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    
    sieve();
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;

        auto factors = factorize(n);
        for (long long i = 0; i < factors.size(); ++i)  {
            if (i > 0) cout << " * ";
            cout << factors[i].first << "^" << factors[i].second;
        }
        
        cout << endl;
    }

    return 0;
}

// O(N log log N + T * (sqrt(MAXN) + log MAXN))