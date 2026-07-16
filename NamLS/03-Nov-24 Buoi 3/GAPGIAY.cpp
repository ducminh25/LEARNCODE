#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> computePrefixSum(const vector<vector<int>> &grid, int n) {
    vector<vector<int>> ps(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            ps[i][j] = grid[i - 1][j - 1] 
                       + ps[i - 1][j] 
                       + ps[i][j - 1] 
                       - ps[i - 1][j - 1];

    return ps;
}

// Hàm tính tổng số 1 trong một phần của ma trận
int calSum(const vector<vector<int>> &ps, int x1, int y1, int x2, int y2) {
    return ps[x2][y2] 
           - ps[x1 - 1][y2] 
           - ps[x2][y1 - 1] 
           + ps[x1 - 1][y1 - 1];
}

// Hàm tìm số lượng số 1 trong phần ít nhất của cách gấp tốt nhất
int min1best(int n, const vector<vector<int>> &grid) {
    // Tính mảng ps để dễ dàng lấy tổng trong từng vùng
    vector<vector<int>> ps = computePrefixSum(grid, n);
    int maxx = 0;
    // Duyệt qua các dòng và cột có thể gấp
    for (int row = 1; row < n; ++row) {
        for (int col = 1; col < n; ++col) {
            // Tính tổng số 1 trong từng phần
            int tl = calSum(ps, 1, 1, row, col);
            int tr = calSum(ps, 1, col + 1, row, n);
            int bl = calSum(ps, row + 1, 1, n, col);
            int br = calSum(ps, row + 1, col + 1, n, n);

            // Tìm phần có ít số 1 nhất trong 4 phần
            int min1 = min({tl, tr, bl, br});
            // Cập nhật kết quả nếu min1 lớn hơn maxx
            maxx = max(maxx, min1);
        }
    }

    return maxx;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("GAPGIAY.inp", "r")) {
        freopen("GAPGIAY.inp", "r", stdin);
        freopen("GAPGIAY.out", "w", stdout);
    }

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    cout << min1best(n, grid) << endl;
    return 0;
}
