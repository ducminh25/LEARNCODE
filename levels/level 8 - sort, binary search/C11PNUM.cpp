#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
bool is_prime[maxn];
vector<int> primes;
int t, k, d;
long long n;

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < maxn; ++i) {
        if (is_prime[i]) {
            for(int j = i * i; j < maxn; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i < maxn; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    d = primes.size();
}

bool check(int x) {
    if (x + k - 1 >= d) return false;
    long long s = 1;
    for(int i = x; i < x + k; ++i) {
        if (s > n / primes[i]) return false;
        s *= primes[i];
    }
    return s <= n;
}

int search(int l, int r) {
    int res = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) {
            res = mid; 
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

void solve() {
    long long s;
    int x;
    cin >> n >> k;
    x = search(0, primes.size() - k);
    // cout << "x = " << x << endl;
    if(x == -1) {
        cout << x << endl;
    }
    else {
        s = 1;
        for(int i = x; i <= x + k - 1; ++i) {
            s *= primes[i];
        }
        cout << s << endl;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
