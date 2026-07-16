#include <bits/stdc++.h>
using namespace std;

const int M = 3e5+2;
int i, n, m;
int a[M];

bool check (int x) {
    int s = 0;
    for (int i = 1; i <= m; ++i) {
        s += a[i] / x;
        if (a[i] % x != 0) ++s;
    }
    return (s <= n);
}

void solve () {
    int res = 0;
    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check (mid)) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
}

int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie (0); cout.tie (0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a [i];
    solve ();

    return 0;
}
