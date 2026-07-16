#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int divisors[MAXN];
bool is_prime[1000005];
int ps[1000005];

void initDiv () {
    for (int i = 1; i < MAXN; ++i)
        for (int j = i; j < MAXN; j += i) 
            divisors[j]++;
}

void sieve(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    int sq = sqrt(MAXN);
    for (int i = 2; i <= sq; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = false;
        }
    }
}

void precom() {
    initDiv();
    sieve();
    ps[0] = 0;
    for(int i = 1; i < MAXN; ++i)
        ps[i] = ps[i - 1] + (is_prime[divisors[i]] ? 1 : 0);
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    if(fopen("cau22024.inp", "r")) {
        freopen("cau22024.inp", "r", stdin);
        freopen("cau22024.out", "w", stdout);
    }
    
    precom();
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << ps[b] - ps[a - 1] << "\n";
    }

    return 0;
}