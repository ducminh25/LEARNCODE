#include <bits/stdc++.h>
using namespace std;
#define int long long

int reversenum(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("DOCNGUOC.inp", "r")) {
        freopen("DOCNGUOC.inp", "r", stdin);
        freopen("DOCNGUOC.out", "w", stdout);
    }

    int a, b;
    cin >> a >> b;
    
    int reversed_a = reversenum(a);
    int reversed_b = reversenum(b);
    cout << max(reversed_a, reversed_b) << endl;
    
    return 0;
}
