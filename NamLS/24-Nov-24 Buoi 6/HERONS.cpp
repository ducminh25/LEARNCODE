#include <bits/stdc++.h>
using namespace std;
long long a, b;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("HERONS.inp", "r")) {
        freopen("HERONS.inp", "r", stdin);
        freopen("HERONS.out", "w", stdout);
    }

    cin >> a >> b;
    long long maxx = min(a, b);
    long long minn = (max(a, b) + 1) / 2;
    // long long minn = max(a, b) / 2 + max(a, b) % 2;
    cout << minn << " " << maxx;
    return 0;
}
