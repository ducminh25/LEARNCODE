#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e7 + 5;
int a, b;
bool is_prime [maxn + 1];

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    int sq = sqrt(maxn);
    for (int i = 2; i <= sq; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxn; j += i)
                is_prime[j] = false;
        }
    }
}


int sumDigit(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

void sol() {
    for(int i = a; i <= b; ++i)
        if(is_prime[i] && is_prime[sumDigit(i)]) cout << i << " ";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("SNTDB.INP", "r")) {
        freopen("SNTDB.INP", "r", stdin);
        freopen("SNTDB.OUT", "w", stdout);
    }

    sieve();
    cin >> a >> b;
    sol();

    return 0;
}