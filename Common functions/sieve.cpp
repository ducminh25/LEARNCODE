#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000000 + 5; //10^7 + 5, ~150ms
bool is_prime[maxn];

// Sàng nguyên tố Erastosthenes
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

int main () {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    sieve();
    cout << "Sieve is done." << endl;

    return 0;
}