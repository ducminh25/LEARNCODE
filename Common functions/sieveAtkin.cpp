#include <bits/stdc++.h>
using namespace std;

// Sàng Atkin, tìm các số nguyên tố trong đoạn [L, R]
vector<bool> sieve_of_atkin(long long L, long long R) {
    vector<bool> sieve(R - L + 1, false);
    long long lim = sqrt(R);

    for (long long x = 1; x <= lim; x++) {
        for (long long y = 1; y <= lim; y++) {
            long long n = 4*x*x + y*y;
            if (n >= L && n <= R && (n % 12 == 1 || n % 12 == 5))
                sieve[n - L] = !sieve[n - L];

            n = 3*x*x + y*y;
            if (n >= L && n <= R && n % 12 == 7)
                sieve[n - L] = !sieve[n - L];

            n = 3*x*x - y*y;
            if (x > y && n >= L && n <= R && n % 12 == 11)
                sieve[n - L] = !sieve[n - L];
        }
    }

    for (long long n = max(5LL, L); n <= R; n++) {
        if (sieve[n - L]) {
            for (long long k = n * n; k <= R; k += n * n)
                sieve[k - L] = false;
        }
    }

    if (L <= 2 && 2 <= R) sieve[2 - L] = true;
    if (L <= 3 && 3 <= R) sieve[3 - L] = true;

    return sieve;
}

int main() {
    long long L, R;
    cin >> L >> R;
    vector<bool> is_prime = sieve_of_atkin(L, R);
    
    long long count = 0;
    for (long long i = L; i <= R; i++) {
        if (is_prime[i - L]) cout << i << ' ';
    }
    
    cout << '\n';
    return 0;
}

// Rmax = 1e7