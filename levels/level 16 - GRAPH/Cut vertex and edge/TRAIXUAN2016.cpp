#include <bits/stdc++.h>
using namespace std;
vector<int> a[20005];
int n, x, y, m, d = 0;
long long res;
long long f[20005], cnt;
int number[20005], low[20005], cha[20005];

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

void xuli() {
    dfs(1);
    long long sum = 0;
    for (int v = 1; v <= n; v++) {
        if (v != cha[v] && low[v] >= number[v]) //(u,v) la cau
        {
            int u = cha[v];
            sum = sum + f[v] * (n - f[v]);
        }
    }
    cout << sum;
}
int main() {
    // freopen("traixuan2016.inp", "r", stdin);
    // freopen("traixuan2016.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nhap();
    xuli();
}

/*
Cho đồ thị vô hướng liên thông. Với mỗi cặp đỉnh (A, B), đếm xem từ A đến B phải đi qua bao nhiêu cầu. Xuất tổng số cầu của tất cả các cặp.
*/