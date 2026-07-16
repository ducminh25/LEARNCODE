#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void solve() {
    sort (a, a + n);
    long long minn = a[0] * a[1];
    long long maxx = a[n - 1] * a[n - 2];
    cout << max(minn, maxx) << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
