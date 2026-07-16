#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXSUM = 1e7 + 5;
int n, a[MAXN];
bool isPrime[MAXSUM];

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAXSUM; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXSUM; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("DAYCON.INP", "r")) {
        freopen("DAYCON.INP", "r", stdin);
        freopen("DAYCON.OUT", "w", stdout);
    }
    sieve();

    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    int count = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j];
            if (isPrime[sum]) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}