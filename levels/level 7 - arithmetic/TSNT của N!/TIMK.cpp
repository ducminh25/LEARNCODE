#include <bits/stdc++.h>
using namespace std;
long long n, m;

long long cnt(long long i) {
    long long res = 0;
    long long exp = i;
    while (n / exp > 0) {
        res += n / exp;
        exp *= i;
    }
    return res;
}

void factor(long long m) {
    long long k = 1e9 + 5;
    long long i = 2;
    int sq = int(sqrt(m));
    
    while(i <= sq) {
        int t = 0;
        while (m % i == 0) {
            m /= i;
            t++;
        }
        if(t > 0) {
            long long x = cnt(i);
            k = min(k, x / t);
        }
    }
    cout << k << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    factor(m);

    return 0;
}