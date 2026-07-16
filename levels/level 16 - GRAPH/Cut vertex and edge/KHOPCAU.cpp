#include <bits/stdc++.h>
using namespace std;
int n, m, d = 0;
int khop[200005], number[200005], low[200005], cha[100005], con[100005], chot[100005];
stack<int> st;
bool xoa[100005];

vector<int> a[200005], res_cau, res_khop;
void nhap() {
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u) {
    d++;
    number[u] = d;
    low[u] = number[u];
    st.push(u);
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
    for (int i = 1; i <= n; i++)
        if (khop[i] == 1) res_khop.push_back(i);
}
void tim_cau() {
    for (int v = 1; v <= n; v++)
        if (v != cha[v] && low[v] >= number[v])
            res_cau.push_back(v);
}
void xuli() {
    for (int i = 1; i <= n; i++)
        if (cha[i] == 0) {
            d = 0;
            cha[i] = i;
            dfs(i);
            // cout<<endl;
        }
    tim_khop();
    tim_cau();
    cout << res_khop.size() << " " << res_cau.size() << endl;
    for (int i = 0; i < res_khop.size(); i++) {
        cout << res_khop[i] << endl;
    }
    for (int i = 0; i < res_cau.size(); i++) {
        cout << res_cau[i] << " " << cha[res_cau[i]] << endl;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("khopcau.inp","r",stdin);
    // freopen("khopcau.out","w",stdout);
    nhap();
    xuli();
}

// Khớp và cầu