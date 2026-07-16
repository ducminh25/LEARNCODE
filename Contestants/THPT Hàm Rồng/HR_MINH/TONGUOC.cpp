#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const long long MAXM = 1e9 + 5;
const int BLOCK = 1 << 20;

long long sumdiv[MAXN];
vector<long long> primes;
bitset<MAXN> is_prime_small;
vector<bool> segment(BLOCK);

void sieve_small() {
    is_prime_small.set();
    is_prime_small[0] = is_prime_small[1] = 0;
    for (int i = 2; i * i < MAXN; i++) {
        if (is_prime_small[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                is_prime_small[j] = 0;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (is_prime_small[i]) primes.push_back(i);
    }
}

void sievediv() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            sumdiv[j] += i;
        }
    }
}

void segment_sieve(long long L, long long R) {
    fill(segment.begin(), segment.end(), true);
    for (long long i = 0; i < R - L; i++) {
        if (L + i < 2) segment[i] = false;
    }
    for (long long p : primes) {
        if ((long long)p * p > R) break;
        long long start = max(p * p, (L + p - 1) / p * p) - L;
        for (long long j = start; j < R - L; j += p) {
            segment[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    if(fopen("TONGUOC.INP", "r")) {
        freopen("TONGUOC.INP", "r", stdin);
        freopen("TONGUOC.OUT", "w", stdout);
    }
    
    sieve_small();
    sievediv();

    int n;
    cin >> n;

    long long prev = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x < MAXN) {
            cout << sumdiv[x] << ' ';
        } else {
            if (i == 0 || x != prev + 1) {
                segment_sieve(x, min(x + BLOCK, MAXM));
            }
            if (segment[x - (x / BLOCK * BLOCK)]) {
                cout << (x + 1) << ' ';
            } else {
                long long sum = x + 1;  // 1 and x are always divisors
                for (long long i = 2; i * i <= x; i++) {
                    if (x % i == 0) {
                        sum += i;
                        if (i * i != x) sum += x / i;
                    }
                }
                cout << sum << ' ';
            }
        }
        prev = x;
    }
    
    return 0;
}
