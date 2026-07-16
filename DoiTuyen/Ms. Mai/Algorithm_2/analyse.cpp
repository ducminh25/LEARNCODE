#include <bits/stdc++.h>
using namespace std;

vector <int> sieve (int N) 
{
    vector <bool> nt (N + 1, true);
    vector <int> sont;
    nt[0] = nt [1] = false;
    for (int i = 2; i <= N; ++i) {
        if (nt[i]) {
            sont.push_back(i);
            for (int j = i * i; j <= N; j += i) {
                nt[j] = false;
            }
        }
    }
    return sont;
}

// count prime factor
vector<int> prime_factor_count (int N) {
    vector<int> primes = sieve(N);
    vector<int> count(primes.size(), 0);

    for (int i = 2; i <= N; ++i) {
        int num = i;
        for (size_t j = 0; j < primes.size(); ++j) {
            while (num % primes[j] == 0) {
                count[j]++;
                num /= primes[j];
            }
        }
    }
    return count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie (0); cout.tie (0);
    
    freopen ("analyse.inp", "r", stdin);
    freopen ("analyse.out", "w", stdout);

    long long N;
    while (cin >> N)
    {
        vector<int> counts = prime_factor_count(N);
        vector<int> prime = sieve(N);

        for (long long i = 0; i < prime.size(); ++i) {
            cout << counts [i] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int f[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i <= 1000; i++) f[i] = 0;

    for (int i = 2; i <= n; i++) {
        int i2 = i;
        for (int j = 2; j * j <= i2; j++) {
            while (i2 % j == 0) {
                f[j]++;
                i2 /= j;
            }
        }
        if (i2 > 1) {
            f[i2]++;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (f[i] > 0) {
            cout << f[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}
*/