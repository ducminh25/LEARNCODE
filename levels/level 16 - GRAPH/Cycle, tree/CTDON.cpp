// A cycle is defined as a part of a graph that has p[start] = p[end].
// Một chu trình (chu kỳ) được định nghĩa là một phần của đồ thị mà p[start] = p[end].
#include <bits/stdc++.h>
using namespace std;

int vis[100005], del[100005];
int n, m, s;
vector<int> a[100005];
int k = 0;

void input() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        // a[v].push_back(u); Do đây là đồ thị có hướng nên không nhập vào 'hướng' ngược lại
    }
}

void trace(int f) {
    int q[100005];
    while (f != n + 1) {
        ++k;
        q[k] = f;
        f = vis[f];
    }

    cout << k << endl;
    for (int i = k; i >= 1; --i) cout << q[i] << ' ';
    cout << s << ' ';
}

void dfs(int u) {
    if (k > 0) return;
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (v == s && vis[u] != s) {
            if (k == 0) trace(u);
            return;
        }
        if (vis[v] == 0) {
            vis[v] = u;
            dfs(v);
        }
    }
}

void solve() {
    vis[s] = n + 1;
    dfs(s);
    if (k == 0) cout << 0 << endl;
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen("CTDON.INP", "r")) {
        freopen("CTDON.INP", "r", stdin);
        freopen("CTDON.OUT", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
CTDON Tìm chu trình đơn từ một đỉnh
Cho đồ thị G.
Đường đi P = (p0, p1, ..., Pk) đi qua k + 1 đỉnh p0, p1, ... , pk và k cạnh (p0, p1), (p1, p2), ... , (pk-1, pk) đi từ đỉnh p0 đến đỉnh pk.

Chu trình là đường đi có p0 = pk. Chu trình đơn là đường đi đơn có p0 = pk.
Bài toán: Cho đồ thị có hướng G = (V, E) và đỉnh s. Tìm một chu trình đơn bất kì trong G bắt đầu từ s và kết thúc ở s.

Input

· Dòng đầu ghi 3 số n, m, s là số đỉnh, số cạnh của đồ thị và đỉnh s (n, m <= 10^5; 1 <= s <= 10^5)
· m dòng tiếp theo, mỗi dòng có dạng hai số nguyên dương u, v, thể hiện có cung nối từ đỉnh u đến đỉnh v trong đồ thị.

Output
· Dòng 1: xuất số k là số lượng đỉnh thuộc chu trình. Nếu không có chu trình thỏa đề thì xuất k = 0.
· Nếu k != 0 xuất dòng 2 gồm k + 1 số thể hiện chu trình, bắt đầu từ s và kết thúc ở s. Nếu có nhiều chu trình thì xuất một chu trình bất kì.

Ví dụ:
INPUT:
8 8 1
1 2
2 3
2 4
3 1
3 5
4 6
6 1
7 8

OUTPUT:
4
1 2 4 6 1
*/