// Cho đồ thị có hướng, tìm ít đỉnh nhất để từ các đỉnh này có thể đi đến tất cả các đỉnh còn lại.
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m, d = 0, k = 0;
int number[maxn], low[maxn], x[maxn], y[maxn], dai_dien[maxn], sc[maxn];
stack<int> st;
bool xoa[maxn];
vector<int> a[200005];

void nhap() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x[i], &y[i]);
        a[x[i]].push_back(y[i]);
    }
}

void benhanh(int u) {
    k++;
    while (st.top() != u) {
        xoa[st.top()] = true;
        sc[st.top()] = k;
        st.pop();
    }
    sc[u] = k;
    dai_dien[k] = u;
    xoa[u] = true;
    st.pop();
}
void dfs(int u) {
    d++;
    number[u] = d;
    low[u] = number[u];
    st.push(u);
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (xoa[v] == false) {
            if (number[v] > 0) // cung nguoc
            {
                low[u] = min(low[u], number[v]);
            } else {
                // cha[v]=u;
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (number[u] == low[u]) benhanh(u); // u la chot
}
void xuli() {
    for (int i = 1; i <= n; i++)
        if (xoa[i] == false) dfs(i);
    //  cout<<k<<endl;
    for (int i = 1; i <= m; i++) {
        if (sc[x[i]] != sc[y[i]]) dai_dien[sc[y[i]]] = 0;
    }
    int res = 0;
    for (int i = 1; i <= k; i++)
        if (dai_dien[i] > 0) res++;
    cout << res << endl;
    for (int i = 1; i <= k; i++)
        if (dai_dien[i] > 0)
            cout << dai_dien[i] << " ";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("message.inp", "r", stdin);
    // freopen("message.out", "w", stdout);
    nhap();
    xuli();
}
