#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
vector<bool> isPrime(maxn, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < maxn; i++) {
        if(isPrime[i])
            for(int j = i * i; j < maxn; j += i)
                isPrime[j] = false;
    }
    for(int i = 2; i < maxn; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
}

long long combine(long long a, long long b) {
    long long tmp = b;
    while(tmp > 0) {
        a *= 10;
        tmp /= 10;
    }
    return a + b;
}

bool primeL(long long a) {
    if(a < maxn) return isPrime[a];
    if (a == 2 || a == 3) return true;
    if (a % 2 == 0 || a % 3 == 0) return false;
    long long sqrta = sqrt(a);
    for (long long j = 5; j <= sqrta; j += 6) {
        if (a % j == 0 || a % (j + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("mprime.inp", "r")) {
        freopen("mprime.inp", "r", stdin);
        freopen("mprime.out", "w", stdout);
    }
    
    sieve();
    int k;
    cin >> k;
    
    int count = 0;
    int i = 0;
    while(count < k && i < primes.size() - 1) {
        long long cb = combine(primes[i], primes[i + 1]);
        // cout << cb << " ";
        if(primeL(cb)) {
            count++;
            if(count == k) {
                cout << cb << endl;
                break;
            }
        }
        i += 2;
    }
    
    return 0;
}