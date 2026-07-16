#include <bits/stdc++.h>
using namespace std;
long long i, j, k, n, m, x, y, z;
vector<int> a[1000005];
long long f[1000005];
void nhap() {
    // freopen("coldwat.inp", "r", stdin);
    // freopen("coldwat.out", "w", stdout);
    scanf("%lld %lld", &n, &k);
    for (i = 1; i <= k; i++) {
        scanf("%lld %lld %lld", &x, &y, &z);
        //  if(y>z) swap(y,z);
        a[x].push_back(y);
        a[x].push_back(z);
    }
}
void dfs(long long u) {
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == 0) {
            f[v] = f[u] + 1;
            dfs(v);
        }
    }
}
void xuli() {
    f[1] = 1;
    dfs(1);
    for (i = 1; i <= n; i++) {
        cout << f[i] << endl;
    }
}
int main() {
    nhap();
    xuli();
}

/*
COLDWATER 
Cho cây nhị phân gốc là đỉnh 1. Bậc của đỉnh u là số lượng đỉnh trên đường đi từ gốc đến đỉnh u. Tính bậc của từng nút.
*/