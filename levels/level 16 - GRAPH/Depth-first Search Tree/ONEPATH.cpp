#include <bits/stdc++.h>
using namespace std;
vector<int> a[100005];
int n, m, s, f, vis[100005], k = 0;

void dfs(int u) {
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (vis[v] == 0) {
            vis[v] = u;
            if (v == f) {
                k = 1;
                return;
            }
            else dfs(v);
        }
    }
}

void trace() {
    int d = 0, q[100005];
    while (f != -1) {
        ++d;
        q[d] = f; //vis [p];
        f = vis[f];
    }

    for (int i = d; i >= 1; --i) cout << q[i] << ' ';
}

void input() {
    int u, v;
    cin >> n >> m >> s >> f;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

int main() {
    if(fopen("ONEPATH.INP", "r")) {
        freopen("ONEPATH.INP", "r", stdin);
        freopen("ONEPATH.OUT", "w", stdout);
    }
    
    input();
    for (int i = 1; i <= n; ++i) {
        sort (a[i].begin(), a[i].end());
    }

    vis[s] = -1;
    dfs(s);
    if (vis[f] == -1) cout << -1;
    else trace();

    return 0;
}

/*
Cho đồ thị G = (V, E) và 2 đỉnh s, f. Tìm một đường đi từ s -> f (tìm một đường đi từ đỉnh s đến đỉnh f).
Output: Đường đi từ s -> f, nếu không có xuất −1. Nếu có nhiều thì xuất đường đi có thứ tự từ điển nhỏ nhất.

Ví dụ:
INPUT:
8 6 1 6
1 2
1 3
2 3
3 4
4 6
7 8
--> OUTPUT: 1 2 3 4 6
*/