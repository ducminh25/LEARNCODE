// TPLT Liệt kê thành phần liên thông
#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, dem, dd, maxx, cha[100005], d[1000000];
vector<int> a[1000000];
void nhap() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
void dfs(int u) {
    dem++;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (cha[v] == 0) {
            cha[v] = u;
            dfs(v);
        }
    }
}
void xuli() {
    for (int i = 1; i <= n; i++) {
        if (cha[i] == 0) {
            dd++;
            cha[i] = -1;
            dem = 0;
            dfs(i);
            if (dem > maxx) maxx = dem;
        }
    }
    printf("%d %d", dd, maxx);
}
int main() {
    // freopen("tplt.inp", "r", stdin);
    // freopen("tplt.out", "w", stdout);
    nhap();
    xuli();
}
