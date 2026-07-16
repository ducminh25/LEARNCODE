#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

bool prime[MAXN];
int prefixSum[MAXN];

void sieve() {
    fill (prime, prime + MAXN, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                prime[j] = false;
            }
        }
    }
    prefixSum[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        prefixSum[i] = prefixSum[i - 1] + prime[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("COUNTPRI.inp", "r", stdin);
    //freopen("COUNTPRI.out", "w", stdout);

    sieve();

    int M;
    cin >> M;

    while (M--) {
        int li, ri;
        cin >> li >> ri;
        cout << prefixSum[ri] - prefixSum[li - 1] << '\n';
    }

    return 0;
}
