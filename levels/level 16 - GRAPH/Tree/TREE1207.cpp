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
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void giai() {
    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (cha[i] == 0) {
            x++;
            cha[i] = n + 1;
            dfs(i);
        }
    }
    cout << m + (x - 1) - (n - 1) << ' ' << (x - 1) << endl;
}
int main() {
    // freopen("tree1207.inp", "r", stdin);
    // freopen("tree1207.out", "w", stdout);
    nhap();
    giai();

    return 0;
}


/*
Bài toán: Cho đồ thị vô hướng G = (V, E), cho biết phải xóa đi ít nhất bao nhiêu cạnh và thêm vào ít nhất bao nhiêu cạnh để đồ thị là một cây?

Input
- Dòng đầu gồm 2 số n, m là số đỉnh và số cạnh. (n, m <= 10^5)
- M dòng sau, mỗi dòng là 2 số u, v biểu diễn 1 cạnh.

Output
Ghi 2 số nguyên x, y là số cạnh ít nhất cần xóa và số cạnh ít nhất cần thêm để thỏa yêu cầu đề bài.

Ví dụ:
INPUT:
5 4
1 2
1 3
2 3
4 5

OUTPUT: 1 1
*/