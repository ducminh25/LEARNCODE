#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    if (fopen ("ARIPOG.INP", "r")) {
        freopen ("ARIPOG.INP", "r", stdin);
        freopen ("ARIPOG.OUT", "w", stdout);
    }
    
    long long u1, d, x;
    cin >> u1 >> d >> x;

    if (d == 0) {
        if (u1 == x) cout << 1;
        else cout << -1;
    } 
    else {
        long long n = (x - u1) / d + 1;
        if (n > 0 && (x - u1) % d == 0)
            cout << n;
        else
            cout << -1;
    }

    return 0;
}