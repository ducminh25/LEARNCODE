#include <bits/stdc++.h>
using namespace std;
int cha[100001];
int n, m, s;
vector<int> a[100005];
// vector<int> a[100000+1];
int res = 0;

void dfs(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (cha[v] == 0) {
            cha[v] = u;
            dfs(v);
        }
    }
}
void nhap() {
    // a.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i].clear();
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void giai() {
    if (m != n - 1) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) cha[i] = 0;
    cha[1] = n + 1;
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (cha[i] == 0) {
            cout << 0 << endl;
            return;
        }
    cout << 1 << endl;
}
int main() {
    // freopen("kttree.inp", "r", stdin);
    // freopen("kttree.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        nhap();
        giai();
    }
}

/*
Cây (tree) là đồ thị vô hướng, liên thông, không có chu trình đơn.
Yêu cầu: Cho đồ thị vô hướng G = (V, E), cho biết đồ thị có phải là một cây không?

Input
Dòng đầu ghi số t là số lượng test (t <= 10). Các dòng sau ghi t bộ test, mỗi bộ test có cấu trúc như sau:

• Dòng đầu ghi 2 số nguyên dương n, m. (n <= 100; m <= 1000)

• M dòng sau, mỗi dòng ghi hai số u, v là một cạnh của đồ thị.

Output: với mỗi test, xuất 1 nếu đồ thị là cây, ngược lại xuất 0.

Ví dụ:
INPUT:
1
5 4
1 2
1 3
2 3
4 5
--> OUTPUT: 0
*/