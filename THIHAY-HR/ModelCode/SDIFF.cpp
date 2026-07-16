#include <bits/stdc++.h>
using namespace std;

long long n, p, q, m, t, res = 1;
long long w[10000000];
void input() {
    cin >> n >> p >> q >> m >> t;
    for (int i = 1; i <= n; i++) w[i] = (p * i + q) % m;
}

void solve() {
    deque<int> qmin, qmax;
    int i = 1, imin, imax;
    qmin.push_back(1);
    qmax.push_back(1);

    for (int j = 2; j <= n; j++) {
        while (!qmin.empty() && w[qmin.back()] >= w[j]) qmin.pop_back();
        while (!qmax.empty() && w[qmax.back()] <= w[j]) qmax.pop_back();
        qmin.push_back(j);
        qmax.push_back(j);
        while (true) {
            imin = qmin.front();
            imax = qmax.front();
            if (w[imax] - w[imin] <= t) break;
            i++;
            if (imin < i) qmin.pop_front();
            if (imax < i) qmax.pop_front();
        }
        res = res + (j - i + 1);
    }
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("sdiff.inp", "r")) {
        freopen("sdiff.inp", "r", stdin);
        freopen("sdiff.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
