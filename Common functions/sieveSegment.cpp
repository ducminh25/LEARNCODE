#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005; // 10^6
const int BLOCK = 1 << 16; // Kích thước đoạn

vector<int> primes;
bitset<MAXN> is_prime;
vector<bool> segment(BLOCK);

void sieve_small() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

void segment_sieve(long long L, long long R) {
    fill(segment.begin(), segment.end(), true);
    if (L == 1) segment[0] = false;

    for (long long p : primes) {
        if (p * p > R) break;
        long long start = max(p * p, (L + p - 1) / p * p) - L;
        for (long long j = start; j < R - L + 1; j += p) {
            segment[j] = false;
        }
    }
}

vector<long long> find_primes(long long L, long long R) {
    vector<long long> result;
    for (long long i = 0; i < R - L + 1; i += BLOCK) {
        long long low = L + i;
        long long high = min(L + i + BLOCK - 1, R);
        segment_sieve(low, high);
        for (long long j = 0; j < high - low + 1; j++) {
            if (segment[j]) {
                result.push_back(low + j);
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve_small();

    long long l, r;
    cin >> l >> r;

    vector<long long> primes_in_range = find_primes(l, r);

    // cout << "Số lượng số nguyên tố trong khoảng [" << l << ", " << r << "]: " 
    //      << primes_in_range.size() << "\n";
    // cout << "Các số nguyên tố là:\n";
    for (long long prime : primes_in_range) {
        cout << prime << ' ';
    }
    cout << '\n';

    return 0;
}
