#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, k;
vector<int> a[maxn]; // danh sách các đỉnh kề nhau
bool vis[maxn];      // biến để cho biết đã thăm qua đỉnh u
int cnt, res = 0;

void input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

// Hàm thực hiện việc đi thăm u và các đỉnh kế cận
void dfs(int u) {
    // Đánh dấu là u đã được thăm
    vis[u] = true;
    cnt++;
    // Duyệt qua các đỉnh kề với u
    for (int v : a[u]) {
        // Nếu v chưa được thăm --> đi thăm v và các đỉnh kế cận của v
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    dfs(k);
    res = cnt;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cnt = 0;
            dfs(i);
            res = max(res, cnt);
        }
    }
    cout << res + 1 << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("BAI5.inp", "r")) {
        freopen("BAI5.inp", "r", stdin);
        freopen("BAI5.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
