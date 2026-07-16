#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 5;
bool is_prime[maxn];

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

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();
    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        while (a <= b) {
            if (is_prime[a] && sumDigit(a) % 5 == 0) {
                cnt++;
            }
            a++;
        }
        cout << cnt << endl;
    }
    return 0;
}