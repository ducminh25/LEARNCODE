#include <bits/stdc++.h>
using namespace std;

const uint64_t maxn = 100005;
bool isPrime[maxn];
int dp[maxn];

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    const long long sqmaxn = (long long) sqrt(maxn);
    for (long long i = 2; i <= sqmaxn; i++) 
        if (isPrime[i]) 
            for (long long j = i * i; j <= maxn; j += i) 
                isPrime[j] = false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("PSEQ.INP", "r")) {
        freopen("PSEQ.INP", "r", stdin);
        freopen("PSEQ.OUT", "w", stdout);
    }

    sieve();
    int t;
    cin >> t;
    // cout -1 if found no prime between a1 and a2
    while (t--) {
        uint64_t a1, a2;
        cin >> a1 >> a2;
        if (a1 == a2) {
            cout << 2 << endl;
        }
        else {
            dp[a1] = 1;
            for (uint64_t i = a1 + 1; i <= a2; i++) {
                if (isPrime[i] && isPrime[i - a1]) 
                    dp[i] = dp[i - 1] + 1;
                else dp[i] = dp[i - 1];
            }
            cout << dp[a2] << endl;
        }
    }
    return 0;
}