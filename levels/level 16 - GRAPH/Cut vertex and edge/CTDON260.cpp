#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> a[maxn], b[maxn];
int n, x, y, m, d = 0, sd;
long long res;
long long f[maxn], cnt;
int number[maxn], low[maxn], cha[maxn], cau[20005];
void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dfs(int u) {
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
            dfs(v);
            f[u] += f[v];
            low[u] = min(low[u], low[v]);
        }
    }
}
void dfs1(int u) {
    // cout<<u<<" ";
    sd++;
    for (int i = 0; i < b[u].size(); i++) {
        int v = b[u][i];
        if (cha[v] == 0) {
            cha[v] = u;
            dfs1(v);
        }
    }
}

void xuli() {
    for (int i = 1; i <= n; i++) {
        if (number[i] == 0) {
            d = 0;
            dfs(i);
        }
    }

    long long sum = 0;
    for (int v = 1; v <= n; v++) {
        if (number[v] > 1 && low[v] >= number[v]) //(u,v) la cau
        {
            int u = cha[v];
            //  cout<<u<<" "<<v<<endl;
            b[u].push_back(v);
            b[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) cha[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (cha[i] == 0) {
            sd = 0;
            cha[i] = i;
            dfs1(i);
            // cout<<endl<<sd<<endl;
            sum = sum + (sd * (sd - 1) / 2 - (sd - 1));
            // cout<<i<<" "<<sd<<" "<<sum<<endl;
        }
    }

    // cout<<endl;
    cout << sum;
}
int main() {
    // freopen("ctdon260.inp", "r", stdin);
    // freopen("ctdon260.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nhap();
    xuli();
}
