#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
long long n, k, a[MAXN], b, ans = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("TONG.INP", "r")) {
        freopen("TONG.INP", "r", stdin);
        freopen("TONG.OUT", "w", stdout);
    }
    
    cin >> n >> k >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    b = (b - 1) % n + 1; 
    for (int i = 0; i < k; i++) {
        int idx = (b + i - 1) % n + 1;
        ans += a[idx];
    }
    
    cout << ans << endl;
    return 0;
}

/*
Tổng dãy số chạy
Tính tổng k số nguyên liên tiếp xuất hiện trên màn hình bắt đầu từ số nguyên thứ b.

Ví dụ: (n = 5, k = 7, b = 6)
5 7 6
1
2
3
4
5

--> OUTPUT: 18
*/