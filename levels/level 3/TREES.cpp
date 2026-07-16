#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn];

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

void solve() {
    int minn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (a[i] < minn) minn = a[i];
    }

    long long diff = 0;
    for (int i = 0; i < n; ++i) {
        diff += a[i] - minn;
    }
    cout << diff << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
