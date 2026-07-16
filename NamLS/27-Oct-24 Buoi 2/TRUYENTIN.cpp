#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct points {
    int x, y;
};
points a[maxn];
double res, maxx;
int n;

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
}

double length(points a, points b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// void solve() {
//     res = INT_MAX;
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             double tmp = length(a[i], a[j]);
//             res = min(res, tmp);
//         }
//     }
//     cout << fixed << setprecision(3) << res << endl;
// }

vector<int> parent(maxn);
vector<pair<double, pair<int, int>>> edges;

void makeSet(int v) {
    parent[v] = v;
}

int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a;
}

void solve() {
    for (int i = 0; i < n; i++) {
        makeSet(i);
        for (int j = i + 1; j < n; j++) {
            double dist = length(a[i], a[j]);
            edges.push_back({dist, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    double max_edge = 0;
    for (auto& edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        if (findSet(u) != findSet(v)) {
            unionSets(u, v);
            max_edge = max(max_edge, edge.first);
        }
    }

    cout << fixed << setprecision(3) << max_edge / 2 << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if (fopen("TRUYENTIN.inp", "r")) {
        freopen("TRUYENTIN.inp", "r", stdin);
        freopen("TRUYENTIN.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
Thành phố được mô phỏng như mặt phẳng tọa độ 2 chiều. Có N trạm truyền tin được xây dựng trong thành phố, trạm thứ i (i = 1...n) có tọa độ là xi, yi. Phạm vi phủ sóng của một trạm là tập hợp tất cả các điểm trên mặt phẳng có khoảng cách với trạm đó không quá một số thực r. Nếu phạm vi phủ sóng của hai trạm A, B (A, B = 1..N) bất kì có điểm chung thì hai trạm này được coi là có giao tiếp được với nhau. Ngoài ra, nếu A giao tiếp được với B mà B giao tiếp được với C thì A cũng giao tiếp được với C (với mọi A, B, C = 1..N).

Yêu cầu: Tìm số thực r nhỏ nhất sao cho mọi cặp trạm truyền tin đều có thể giao tiếp được với nhau.

Input:
- Dòng đầu chứa số nguyên n (n <= 1000).
- Dòng thứ i trong N dòng tiếp theo ghi hai số nguyên không âm xi, yi (xi, yi <= 10^9).

Output: gồm một số thực là số r tìm được theo yêu cầu, làm tròn đến 3 chữ số thập phân.

Ví dụ:
INPUT:
4
1 1
2 6
4 3
6 8

--> OUTPUT: 2.236

Thuật toán Kruskal để tìm cây khung nhỏ nhất (Minimum Spanning Tree - MST) của đồ thị. Cạnh dài nhất trong MST sẽ là bán kính r cần tìm. Đây là một cách tiếp cận hiệu quả với độ phức tạp O(N^2 log N).
*/