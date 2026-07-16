#include <bits/stdc++.h>
// #define fi "dulich.inp"
// #define fo "dulich.out"
using namespace std;
const int maxn = 300000;
vector<int> a[maxn];
vector<int> b[maxn];
stack<int> st;
int x[maxn], y[maxn], d1[maxn], d2[maxn], num[maxn], low[maxn], sl[maxn], tp[maxn], cha[maxn];
int n, kq, m, canh, dem;
void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        a[x[i]].push_back(y[i]);
    }
}
void dfs(int u) {
    dem++;
    low[u] = dem;
    num[u] = dem;
    st.push(u);
    int v;
    for (int i = 0; i < a[u].size(); i++) {
        v = a[u][i];
        if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (tp[v] == 0)
            low[u] = min(low[u], num[v]);
    }
    if (low[u] != num[u]) return;
    tp[u] = u;
    sl[u] = 1;
    v = st.top();
    while (v != u) {
        sl[u]++;
        tp[v] = u;
        st.pop();
        v = st.top();
    }
    st.pop();
}
void them(int u, int v) {
    canh++;
    x[canh] = u;
    y[canh] = v;
}
void taolai() {
    for (int i = 1; i <= n; i++) a[i].clear();
    canh = 0;
    for (int i = 1; i <= m; i++)
        if (tp[x[i]] != tp[y[i]]) them(tp[x[i]], tp[y[i]]);
    m = canh;
    for (int i = 1; i <= m; i++) {
        a[x[i]].push_back(y[i]);
        b[x[i]].push_back(1);
        a[y[i]].push_back(x[i]);
        b[y[i]].push_back(2);
    }
}
void dfs1(int u) {
    for (int i = 0; i < a[u].size(); i++)
        if (b[u][i] == 1) {
            int v = a[u][i];
            if (cha[v] == 0) {
                cha[v] = u;
                dfs1(v);
            }
            if (d1[v] != 0) d1[u] = max(d1[u], d1[v] + sl[u]);
        }
}
void dfs2(int u) {
    for (int i = 0; i < a[u].size(); i++)
        if (b[u][i] == 2) {
            int v = a[u][i];
            if (cha[v] == 0) {
                cha[v] = u;
                dfs2(v);
            }
            if (d2[v] != 0) d2[u] = max(d2[u], d2[v] + sl[u]);
        }
}
void khoitao() {
    for (int i = 1; i <= n; i++) cha[i] = 0;
    d1[tp[1]] = sl[tp[1]];
    for (int i = 2; i <= n; i++)
        if (cha[tp[i]] == 0) {
            cha[tp[i]] == tp[i];
            dfs1(tp[i]);
        }

    for (int i = 2; i <= n; i++) cha[i] = 0;
    d2[tp[1]] = sl[tp[1]];
    for (int i = 2; i <= n; i++)
        if (cha[tp[i]] == 0) {
            cha[tp[i]] == tp[i];
            dfs2(tp[i]);
        }
}
void xuli() {
    kq = 0;
    for (int i = 1; i <= m; i++)
        if (d1[x[i]] != 0 && d2[y[i]] != 0)
            kq = max(kq, d1[x[i]] + d2[y[i]] - sl[1]);
    cout << kq;
}
int main() {
    // freopen(fi, "r", stdin);
    // freopen(fo, "w", stdout);
    nhap();
    for (int i = 1; i <= n; i++)
        if (tp[i] == 0) {
            dem = 0;
            dfs(i);
        }
    taolai();
    khoitao();
    xuli();
}

// DULICH Du lịch 2015