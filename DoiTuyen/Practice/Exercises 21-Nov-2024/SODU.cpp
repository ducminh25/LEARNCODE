#include <bits/stdc++.h>
using namespace std;
int a, b, MOD;

long long fastPower(int a, int n, int MOD) {
    if (n == 0) return 1;
    if (n == 1) return a % MOD;
    
    long long temp = fastPower(a % MOD, n / 2, MOD);
    temp = (temp * temp) % MOD;
    
    if (n % 2 == 0)
        return temp;
    else
        return (temp * (a % MOD)) % MOD;
}

void input() {
    cin >> a >> b >> MOD;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("SODU.INP", "r")) {
        freopen("SODU.INP", "r", stdin);
        freopen("SODU.OUT", "w", stdout);
    }
    
    input();
    cout << fastPower(a, b, MOD) << endl;

    return 0;
}
