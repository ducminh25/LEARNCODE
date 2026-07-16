#include <bits/stdc++.h>
using namespace std;
int vis[100001], del[100001];
int n, m, s;
vector<int> a[100005];
int res = 0;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dfs(int u) {
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (vis[v] > 0 && vis[u] != v && del[v] == 0)
            res++;
        if (vis[v] == 0) {
            vis[v] = u;
            dfs(v);
        }
    }
    del[u] = 1;
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            vis[i] = n + 1;
            dfs(i);
        }
    }

    cout << res << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("ADS.INP", "r")) {
        freopen("ADS.INP", "r", stdin);
        freopen("ADS.OUT", "w", stdout);
    }

    input();
    solve();
    return 0;
}

/*
Trong thành phố có m con đường, n đại lý bán kẹo (đánh số từ 1 đến n).
Mỗi con đường chỉ nối trực tiếp giữa 2 đại lý, và được ký hiệu bằng chỉ số của 2 đại lý mà nó nối.
Đồng thời, giữa 2 đại lý bất kỳ có không quá 1 con đường nối chúng.

Ông Fruit-Jelly nghĩ rằng, ông ta sẽ quản lý nhân viên dễ hơn nếu xếp mỗi người tiếp thị trên những hành trình có tính chất thứ tự.
Tức là những đại lý bán kẹo trên hành trình đó thỏa các điều kiện sau:
• Có đường nối trực tiếp giữa 2 đại lý liên tiếp nhau trên hành trình
• Từ một đại lý bất kỳ trong hành trình có thể đi qua tất cả các đoạn đường trong hành trình đó rồi trở về nơi xuất phát mà không đi qua đoạn đường nào quá một lần
• Hành trình phân công cho mỗi nhân viên phải có ít nhất một đoạn đường chưa có nhân viên nào khác đi tiếp thị.
• Mỗi nhân viên chỉ di chuyển trên hành trình mà anh ta được phân công.
Hãy tính số lượng nhân viên tối đa mà ông Fruit-Jelly có thể xếp việc, và hành trình cụ thể mà mỗi người được xếp.

Input
• Dòng đầu là 2 số tự nhiên N và M (N <= 2000; M <= 5000)
• Trong M dòng tiếp theo, mỗi dòng ghi 2 số nguyên mô tả một đoạn đường, mỗi đoạn đường được mô tả bởi chỉ số của 2 đại lý mà nó nối.
Output
Dòng đầu tiên ghi Q là số lượng nhân viên tối đa tìm được.

Ví dụ:
Input:
5 6
1 2
2 4
4 5
3 5
1 3
2 3
--> OUTPUT: 2
*/