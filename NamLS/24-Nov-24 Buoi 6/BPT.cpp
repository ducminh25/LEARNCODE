#include <bits/stdc++.h>
using namespace std;
long long n;

void solve() {
    int cnt = 0;
    for (int i = 9; i <= n; i += 10) cnt++;

    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("BPT.inp", "r")) {
        freopen("BPT.inp", "r", stdin);
        freopen("BPT.out", "w", stdout);
    }
    
    cin >> n;
    solve();
    
    return 0;
}

/*
Cho hàm số y = f(x), với x là số nguyên dương thì y là tổng các chữ số của x. Ví dụ, cho x = 191 thì y = f(191) = 1 + 9 + 1 = 11.
Yêu cầu: Cho số nguyên dương n. Tìm số lượng các số nguyên dương x thỏa mãn đồng thời hai điều kiện:
- Điều kiện 1: 1 <= x <= n
- Điều kiện 2: f(x + 1) < f(x) 

Dữ liệu: gồm một dòng chứa số nguyên n (1 ≤ n ≤ 10^9).
Kết quả: gồm một dòng chứa số lượng các số nguyên dương x thỏa mãn yêu cầu.

Ví dụ:
INPUT:
11 
--> OUTPUT: 1 (Có 1 số nguyên dương x = 9 thoả mãn)
*/