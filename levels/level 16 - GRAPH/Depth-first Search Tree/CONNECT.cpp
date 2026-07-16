#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
int vis[100005] = {0};
int n, m;
vector<int> a[100005];
vector<int> region;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
}

void dfs(int u) {
    region.pb(u);
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (vis[v] == 0) {
            vis[v] = u;
            dfs(v);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            vis[i] = n + 1;
            region.clear();
            dfs(i);
            sort(region.begin(), region.end());
            for (int x : region) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}

/*
Đồ thị vô hướng được gọi là liên thông nếu giữa hai đỉnh bất kỳ đều tồn tại đường đi.
Nếu đồ thị G không liên thông, thì nó được hợp từ hai hay nhiều đồ thị con liên thông. Các đồ thị con này đôi một không có đỉnh chung. Các đồ thị con liên thông rời nhau như vậy gọi là thành phần liên thông của đồ thị đang xét.
Yêu cầu: cho đồ thị vô hướng G = (V, E) gồm n đỉnh và m cạnh. Hãy liệt kê các thành phần liên thông của đồ thị.

Input:
- Dòng 1 chứa hai số nguyên dương n và m (n <= 10^5; m <= 10^6)
- m dòng tiếp theo, mỗi dòng chứa hai số nguyên dương u, v thể hiện có cạnh nối từ đỉnh u tới đỉnh v trong đồ thị.
Output: gồm nhiều dòng, mỗi dòng liệt kê các đỉnh thuộc một thành phần liên thông. Các đỉnh được liệt kê theo thứ tự tăng dần.

Ví dụ:
INPUT:
12 10
1 4
2 3
3 6
4 5
6 7
8 9
8 10
9 11
11 8
11 12

--> OUTPUT:
1 4 5 
2 3 6 7 
8 9 10 11 12
*/