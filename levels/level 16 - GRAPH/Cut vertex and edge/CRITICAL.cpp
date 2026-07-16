#include <bits/stdc++.h>
using namespace std;
vector<int> a[20005];
int n, x, y, m, d = 0;
long long res;
bool khop[20005];
long long f[20005], cnt;
int number[20005], low[20005], cha[20005], con[20005];
int mlt[20005];
void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dfs(int u) {
    mlt[u] = res; // u thuoc mien lien thong nao
    f[u] = 1;
    cnt++; // f[u] = so dinh thuoc nhanh u
    d++;
    number[u] = d;
    low[u] = number[u];
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (number[v] > 0) // cung nguoc
        {
            if (cha[u] != v)
                low[u] = min(low[u], number[v]);
        } else {
            cha[v] = u;
            con[u]++;
            dfs(v);
            f[u] += f[v];
            low[u] = min(low[u], low[v]);
        }
    }
}
void tim_khop() {
    for (int v = 1; v <= n; v++) {
        if (v != cha[v]) {
            int u = cha[v];
            if (low[v] >= number[u]) {
                if (number[u] == 1 && con[u] < 2)
                    khop[u] = 0;
                else
                    khop[u] = 1;
            }
        }
    }
}
void xuli() {
    for (int i = 1; i <= n; i++)
        if (number[i] == 0) {
            d = 0;
            res = i;
            dfs(i);
            //  if (child==1) khop[i]=0;
        }
    tim_khop();

    long long sum = 0;
    for (int i = 1; i <= n; i++)
        if (khop[i]) {
            long long res = 0, d1 = 0;
            for (int v : a[i])
                if (cha[v] == i && low[v] >= number[i]) {
                    d1 = d1 + f[v];
                    res += f[v] * (f[mlt[i]] - f[v] - 1);
                }
            res += (f[mlt[i]] - d1 - 1) * (d1);
            res /= 2;
            sum += res;
        }
    printf("%0.2f", float(sum) / n);
}
int main() {
    // freopen("critical.inp","r",stdin);
    // freopen("critical.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nhap();
    xuli();
}
