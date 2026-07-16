#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 2005;
int n, m, k;
int a[maxn][maxn];
long long ps[maxn][maxn], dia[maxn][maxn], trpz[maxn][maxn];
long long tz[maxn][maxn];

void input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            ps[i][j] = a[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }
}

// // Tổng đường chéo (c)
// long long sumDiagonal(int r, int c, int len) {
//     if (len == 0) return 0;
//     return a[r][c] + sumDiagonal(r + 1, c - 1, len - 1);
// }

// // Tổng hình thang
// long long sumTrapezoid(int r, int c) {
//     long long sum = 0;
//     for (int i = 0; i < k; ++i) {
//         sum += sumDiagonal(r + i, c, k - i);
//     }
//     return sum;
// }

void solve() {
    long long maxx = LLONG_MIN;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dia[i][j] = a[i][j] + dia[i - 1][j - 1];
            trpz[i][j] = trpz[i][j - 1] + dia[i][j];
        }
    }

    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            res = trpz[i][j] - trpz[i - k][j - k] - (ps[i][j - k] - ps[i - k][j - k]);
            maxx = max(maxx, res);
        }
    }

    cout << maxx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("TAMGIAC.inp", "r")) {
        freopen("TAMGIAC.inp", "r", stdin);
        freopen("TAMGIAC.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
