#include <bits/stdc++.h>
using namespace std;
int vis[100001];
int n, m, s;
vector<int> a[100005];
int res = 0;

void input() {
    cin >> n >> m >> s;
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dfs(int u) {
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        // Kiểm tra xem v đã được đi qua hay chưa
        if (vis[v] == 0) {
            vis[v] = u;
            dfs(v);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    vis[s] = n + 1;
    dfs(s);

    for (int i = 1; i <= n; ++i)
        if (vis[i] > 0)
            res++;

    cout << res;

    return 0;
}

/*
Đồ thị vô hướng n đỉnh, m cạnh là một tập hợp gồm các đỉnh được đánh số 1, 2, …, n và m cạnh, mỗi cạnh (u, v) nối giữa đỉnh u và đỉnh v.
Cho đồ thị G. Đường đi P = (p0, p1, …, pk) đi qua k+1 đỉnh p0, p1, … , pk và k cạnh (p0, p1), (p1, p2), … , (pk-1, pk) đi từ đỉnh p0 đến đỉnh pk.
Kí hiệu p0 -> pk. p0 gọi là đỉnh đầu, pk gọi là đỉnh cuối, p1, …, pk-1 gọi là đỉnh trong.

Đỉnh u gọi là đến được từ s nếu có đường đi P = (s, p1, …, pk, u) từ s đến u.
Yêu cầu: Cho đồ thị vô hướng G = (V, E) và đỉnh s. Tìm số lượng các đỉnh có thể đến từ s.

Input
• Dòng 1 chứa số đỉnh n, số cạnh m của đồ thị, đỉnh xuất phát s. (1 <= n <= 10^5, 1 <= m <= 10^5 , 1 <= s <= n)

• m dòng tiếp theo, mỗi dòng có dạng hai số nguyên dương u, v cách nhau một dấu cách, thể hiện có cạnh nối từ đỉnh u đến đỉnh v trong đồ thị

Output
Số lượng các đỉnh có thể đến được từ s (tính cả đỉnh s).

VD:
INPUT:
8 6 1
1 2
1 3
2 3
2 4
4 6
7 8

--> OUTPUT: 5
*/