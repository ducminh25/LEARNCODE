#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int m = 1000000007;
int n, k;
int a[maxn];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
}

void solve() {
    vector<vector<int>> dp(maxn, vector<int>(k, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i][(j + a[i] % k + k) % k] = (dp[i][(j + a[i] % k + k) % k] + dp[i - 1][j]) % m;
            dp[i][(j - a[i] % k + k) % k] = (dp[i][(j - a[i] % k + k) % k] + dp[i - 1][j]) % m;
        }
    }

    cout << dp[n][0] << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("CAU5.inp", "r")) {
        freopen("CAU5.inp", "r", stdin);
        freopen("CAU5.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
Cho một dãy gồm N số nguyên  a_1,a_2,a_3,…,a_N và một số nguyên dương K. Ta có biểu thức:
? a_1 ? a_2 ? a_3  …? a_N = X
Trong đó ta có thể thay thế dấu ‘?’ bằng cách phép toán ‘+’ hoặc ‘-’. Hãy đếm xem có tất cả bao nhiêu cách thay dấu khác nhau để X chia hết cho K. Hai cách thay dấu gọi là khác nhau nếu tồn tại một vị trí mà ở đó dấu ở cách này khác dấu ở cách kia.
Dữ liệu vào:
+ Dòng đầu tiên gồm 2 số nguyên dương N, K.
+ Dòng thứ hai gồm N số nguyên dương a_1,a_2,a_3,…,a_N. (a_i <= 10^9)
+ N ≤ 10000, K ≤ 1000.
Kết quả: là số cách thay dấu lấy modulo cho 10^9 + 7.
Ví dụ:
INPUT:
5 3
1 7 14 6 7
--> OUTPUT: 12
*/