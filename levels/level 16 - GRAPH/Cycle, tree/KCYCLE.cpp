#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int vis[maxn], p[maxn], check[1000001];
int n, m, s, k, d = 0;
vector<int> a[maxn];

int res = 0;
void trace(int u) {
    // cout<<u<<endl;
    int v, j, dd[maxn];

    //  cout<<endl;
    while (u != n + 1) {
        d++;
        dd[d] = u;
        //    cout<<u<<" ";
        u = vis[u];
    }
    for (int i = 1; i <= d; i++) p[i] = dd[d + 1 - i];

    // cout<<endl;
}
void findCycle(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        //  cout<<a[u][i]<<" ";
        check[a[u][i]] = 1;
    }
    int j = 1;
    while (check[p[j]] == 0) j++;
    cout << (d - j + 1) << endl;
    for (int i = j; i <= d; i++)
        cout << p[i] << " ";
}

void dfs(int u) {
    if (d > 0) return;
    bool ok = false;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (vis[v] == 0) {
            vis[v] = u;
            ok = true;
            dfs(v);
        }
    }
    if (ok == false) {
        trace(u);
        findCycle(u);
    }
    // xoa[u]=1;
}
void input() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
void solve() {
    vis[1] = n + 1;
    dfs(1);
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("kcycle.inp", "r", stdin);
    // freopen("kcycle.out", "w", stdout);
    input();
    solve();
}

/*
Cho đồ thị vô hướng G gồm n đỉnh được đánh thứ tự 1..n và m cạnh. Mỗi đỉnh có cạnh kề với ít nhất k đỉnh khác trong đồ thị.
Yêu cầu: Tìm trong đồ thị này một chu trình đơn có độ dài ít nhất là k + 1.
Một chu trình đơn độ dài d (d > 1) trong đồ thị là dãy các đỉnh phân biệt v1, v2, …, vd với vd và v1 là 2 đỉnh kề nhau.

Input
Dòng đầu: gồm 3 số n, m, k(3 <= n, m <= 10^5, 2 <= k <= n − 1)
m dòng sau: mỗi dòng chứa 2 số ai,bi biểu diễn cạnh thứ i của đồ thị (1 <= ai, bi <= n, ai <> bi)

Output
Dòng đầu: chứa số nguyên r là độ dài chu trình tìm được (r >= k+ 1).
Dòng thứ hai: in r đỉnh v1, v2, …, vr(1 <= vi <= n) biểu diễn chu trình tìm được.

Dữ liệu đảm bảo luôn có đáp án. Nếu có nhiều đáp án thì xuất 1 đáp án bất kỳ.

Ví dụ:
INPUT:
4 6 3
4 3
1 2
1 3
1 4
2 3
2 4
--> OUTPUT: 4 \n 3 4 1 2

INPUT:
3 3 2
1 2
2 3
3 1
--> OUTPUT: 3 \n 1 2 3
*/