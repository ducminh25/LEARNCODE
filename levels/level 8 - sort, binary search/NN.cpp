#include <bits/stdc++.h>
using namespace std;
const int maxn = 30005;
int n, a[maxn];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve() {
    sort(a + 1, a + n + 1);
    bool ok = false;
    int res = 0;
    int i = 1;
    if (a[1] > 0) {
        cout << 0 << endl;
        return;
    }
    for (; i < n; ++i) {
        if (a[i + 1] - a[i] > 1) {
            res = a[i] + 1;
            ok = true;
            break;
        }
    }
    if (!ok) {res = a[i] + 1; cout << res << endl; return;}
    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
