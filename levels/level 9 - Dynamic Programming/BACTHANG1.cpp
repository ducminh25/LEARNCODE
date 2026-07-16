#include <bits/stdc++.h>
using namespace std;
long long n;
long long f[55];

void solve () {
    f [2] = 1; f [3] = 2;
    for (int i = 4; i <= n; ++i) {
        f [i] = f [i - 1] + f [i - 2];
    }
    cout << f[n];
}

int main () {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> n;
    solve();
    return 0;
}
