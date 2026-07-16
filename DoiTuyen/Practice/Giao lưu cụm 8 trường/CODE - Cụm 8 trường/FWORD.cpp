#include <bits/stdc++.h>
using namespace std;
const long long md = 505;

long long n, m, k, x, cnt = 1;
long long f[md];
string s, can[md], ans[md];

void findChar(long long p) {
    if (p == m - 1) {
        ans[p] = can[p][x - cnt];
        return ;
    }
    for(long long j = 0; j < k; j++) {
        if (cnt + f[m - p - 1] > x) {
            ans[p] = can[p][j];
            findChar(p + 1);
            break;
        } else cnt += f[m - p - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    cout.tie(0);
    freopen("FWORD.inp", "r", stdin);
    freopen("FWORD.out", "w", stdout);

    cin >> n >> m >> k >> x;
    cin >> s;
    for(long long i = 0; i < m; i++) {
        cin >> can[i];
        sort(can[i].begin(), can[i].end());
    }
    f[1] = k;
    for(int i = 2; i <= m; i++) {
        f[i] = min(x, f[i - 1] * k);
    }
    findChar(0);
    long long pos = 0;
    for(long long i = 0; i < n; i++) {
        if (s[i] == '#') {
            cout << ans[pos++];
        } else cout << s[i];
    }
    return 0;
}
