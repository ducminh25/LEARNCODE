#include <bits/stdc++.h>
using namespace std;
int n;
int p[100002];
long long f[100002]{0};
int cha[100002]{0};
vector<int> a[100002];
int sum = 0;

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u) {
    f[u] = p[u];
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (cha[v] == 0) {
            cha[v] = u;
            dfs(v);
            f[u] = f[u] + f[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("TACHTINH.inp", "r", stdin);
    // freopen("TACHTINH.out", "w", stdout);
    read();
    cha[1] = -1;
    dfs(1);
    long long res = 1e9;
    for (int i = 1; i <= n; i++) {
        res = min(res, abs(2 * f[i] - sum));
    }
    cout << res;
}

/*
TACHTINH Tách tỉnh
Bài toán: Cho cây có n đỉnh, đỉnh k có trọng số ak. Hãy tách cây thành 2 phần sao cho:
1. Mỗi phần là liên thông.
2. Độ chênh lệch tổng trọng số giữa hai phần chênh lệch là ít nhất.

Độ thị trong ví dụ cắt thành 2 phần {1, 2, 3, 4, 5} và {6}.
*/