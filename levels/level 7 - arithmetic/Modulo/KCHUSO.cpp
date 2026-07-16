#include <bits/stdc++.h>
using namespace std;

int digitcnt(long long n) {
    int cnt = 0;
    if (n == 0) return 1;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int luythua(int n) {
    int s = 1;
    for(int i = 1; i <= n; ++i)
        s *= 10;

    return s;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n, k;
    cin >> m >> n >> k;
    long long d = luythua(k);
    long long s = 1;
    for(int i = 1; i <= n; ++i) {
        s = (s * (m % d)) % d;
    }

    if(digitcnt(s) < k) 
        for(int i = 0; i < k - digitcnt(s); ++i)
            cout << '0';
    cout << s;

    return 0;
}