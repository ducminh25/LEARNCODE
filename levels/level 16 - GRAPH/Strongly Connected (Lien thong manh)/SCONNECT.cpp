#include <bits/stdc++.h>
using namespace std;
int n, m, d = 0;
int number[200005], low[200005];
stack<int> st;
bool xoa[100005];
vector<int> a[200005];
void nhap() {
    // cin>>n>>m;
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++) {
        // cin>>u>>v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
    }
}

void benhanh(int u) {
    while (st.top() != u) {
        xoa[st.top()] = true;
        cout << st.top() << " "; // printf("%lld ",Stack[r]);
        st.pop();
    }
    cout << u;
    xoa[u] = true;
    st.pop();
    cout << endl;
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
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("sconnect.inp", "r", stdin);
    // freopen("sconnect.out", "w", stdout);
    nhap();
    xuli();
}
