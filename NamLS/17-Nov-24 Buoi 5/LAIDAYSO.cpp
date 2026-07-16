#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("LAIDAYSO.inp", "r")) {
        freopen("LAIDAYSO.inp", "r", stdin);
        freopen("LAIDAYSO.out", "w", stdout);
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int cnt = 0;
    unordered_map<int, bool> m;
    for (int p = 1; p <= n; ++p) {
        for (int k = p - 1; k >= 1; --k) {
            if (m[a[p] - a[k]]) {
                cnt++;
                break;
            }
        }
        for (int k = 1; k <= p; ++k)
            m[a[p] + a[k]] = true;
    }
    cout << cnt << endl;

    return 0;
}

/*
Đề bài:
Cho dãy số nguyên a1, a2, ..an. Yêu cầu: Đếm tất cả các chỉ số p của dãy số trên thỏa mãn điều kiện tồn tại 3 số i, j, k sao cho: ap = ai + aj + ak, với 1 <= i, j, k < p; i, j, k không nhất thiết phải khác nhau.

Input
• Dòng đầu tiên chứa số nguyên dương n (1 <= n <= 5000)
• Dòng thứ hai chứa dãy số a1, a2, ..an (|ai| <= 10^5 với mọi i = 1..n).

Output: gồm một số duy nhất là kết quả tìm được.

Sample:
input:
6
1 2 3 5 7 10
--> output:
4

*/
