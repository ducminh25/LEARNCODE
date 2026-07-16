#include <bits/stdc++.h>
using namespace std;
int m, n, k;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("CAU4.inp", "r")) {
        freopen("CAU4.inp", "r", stdin);
        freopen("CAU4.out", "w", stdout);
    }

    cin >> m >> n >> k;
    vector<vector<int>> height(m + 1, vector<int>(n + 1, 0));
    for (int p = 0; p < k; ++p) {
        int xp, yp, up, vp;
        cin >> xp >> yp >> up >> vp;
        height[xp][yp]++;
        if (up + 1 <= m) height[up + 1][yp]--;
        if (vp + 1 <= n) height[xp][vp + 1]--;
        if (up + 1 <= m && vp + 1 <= n) height[up + 1][vp + 1]++;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i > 1) height[i][j] += height[i - 1][j];
            if (j > 1) height[i][j] += height[i][j - 1];
            if (i > 1 && j > 1) height[i][j] -= height[i - 1][j - 1];
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxx = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
            } else if (height[i][j] == height[i - 1][j] &&
                       height[i][j] == height[i][j - 1] &&
                       height[i][j] == height[i - 1][j - 1]) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            } else
                dp[i][j] = 1;
            maxx = max(maxx, dp[i][j]);
        }
    }
    cout << maxx;

    return 0;
}

/*
Sàn một nhà thi đấu là một hình chữ nhật kích thước m x n được chia thành lưới ô vuông đơn vị, các hàng được đánh số từ 1 tới m từ trên xuống và các cột được đánh số từ 1 tới n từ trái qua phải, ô nằm trên giao của hàng i và cột j được gọi là ô (i,j). Khi mới được xây dựng, tất cả các ô là ô trống và được coi là có độ height bằng 0.

Trong quá trình sử dụng, nhà thi đấu đã tổ chức k sự kiện thể thao đánh số từ 1 tới k, ở sự kiện thứ p (p=1..k) người ta trải thêm các tấm nệm vào tất cả các ô thuộc hình chữ nhật có góc trái trên là (x_p, y_p) và góc phải dưới là (u_p, v_p) và làm tăng độ height của những ô này lên 1 đơn vị. Tức là bao gồm tất cả các ô (i,j) có x_p ≤ i ≤ u_p và y_p ≤ j ≤ v_p.

Sắp tới có cuộc thi trượt Patin tại nhà thi đấu. Vì các tấm nệm mềm không thích hợp cho môn thể thao này, Ban tổ chức muốn chọn một hình vuông có các cạnh song song với các cạnh sàn nhà và toàn bộ các ô bên trong hình vuông đó đều height bằng nhau để đặt lên đó một tấm phủ cứng làm sàn trượt Patin.

Yêu cầu: Tìm cạnh hình vuông lớn nhất mà Ban tổ chức có thể sử dụng như mô tả trên.

Dữ liệu vào gồm:
- Dòng đầu chứa 3 số nguyên dương m, n, k (m, n ≤ 2000, k ≤ 10^5);
- Dòng thứ p trong k dòng tiếp theo ghi 4 số nguyên dương x_p, y_p, u_p, v_p (x_p ≤ u_p ≤ m, y_p ≤ v_p ≤ n với mọi p = 1..k).

Kết quả: gồm một số nguyên duy nhất là cạnh hình vuông lớn nhất tìm được.

Ví dụ:
INPUT:
6 6 4
2 2 3 6
2 2 6 3
2 4 4 5
4 2 6 4
--> OUTPUT: 3
*/