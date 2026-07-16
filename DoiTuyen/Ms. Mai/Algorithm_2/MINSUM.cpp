#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen ("MINSUM.inp", "r", stdin);
    freopen ("MINSUM.out", "w", stdout);

    int G, L;
    cin >> G >> L;

    if (L % G != 0) 
    {
        cout << -1 << endl;
        return 0;
    }

    int n = L / G;
    int sqrt_n = sqrt(n);

    int A = G, B = G * n;

    for (int i = sqrt_n; i >= 1; --i) {
        if (n % i == 0) {
            int j = n / i;
            if (abs(i - j) < abs(A / G - B / G)) {
                A = G * i;
                B = G * j;
            }
        }
    }

    cout << A + B << endl;

    return 0;
}
