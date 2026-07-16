#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 5;

bool isPrime [MAXN];
vector <int> primes;

void sieve() {
    fill (isPrime, isPrime + MAXN, true);
    isPrime [0] = isPrime [1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (isPrime [i]) {
            primes.push_back(i);
        }
    }
}

void phanTichSoNguyen(long long n, vector<pair<long long, long long>>& factors) {
    for (long long prime : primes) {
        if (prime * prime > n) break;
        int dem = 0;
        while (n % prime == 0) {
            dem++;
            n /= prime;
        }
        if (dem > 0) {
            factors.push_back({prime, dem});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
}

int main() 
{
/*    sieve ();
    long long n;
    cin >> n;
    vector <pair<long long, long long>> factors;
    phanTichSoNguyen(n, factors);
    //for (auto& factor : factors) {
    //    cout << factor.first << "^" << factor.second << " ";
    //}
    return 0;
*/
    sieve ();
    long long n;
    cin >> n;
    vector<pair<long long, long long>> factors;
    phanTichSoNguyen(n, factors);
    
    int demUocSo = 1;
    int demUocNguyenTo = 0;
    for (auto& factor : factors) {
        demUocSo *= (factor.second + 1);
        demUocNguyenTo++;
    }
    
    cout << demUocSo - demUocNguyenTo << endl;
    
    return 0;
}