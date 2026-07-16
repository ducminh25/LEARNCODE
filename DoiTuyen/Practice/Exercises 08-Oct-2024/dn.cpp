#include <bits/stdc++.h>
using namespace std;

long long count_on_lights(long long p, long long q, long long n) {
    long long count = 0;
    for (long long i = (long long)sqrt(p); i <= (long long)sqrt(q); i++) {
        if (i * i >= p && i * i <= q) {
            count += 1;
        }
    }
    return count;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    
    if (fopen("dp.inp", "r")) {
        freopen ("dp.inp", "r", stdin);
        freopen ("dp.out", "w", stdout);
    }
    
    long long p, q, n;
    cin >> p >> q >> n;
    cout << count_on_lights(p, q, n) << endl;
    return 0;
}