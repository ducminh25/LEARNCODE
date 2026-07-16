#include <bits/stdc++.h>
using namespace std;
int n;
long long l, r, x;

long long power(int x, int y) {
    if (y == 0) return 1;
    long long t = power(x, y / 2);
    if (y % 2 == 0) return t * t;
    else return t * t * x;
}

void solve(int t) {
    cin >> l >> r;
    for (int k = 39; k >= 1; --k) {
        x = 2;
        while (power(x, k) <= r) x++;
        if (power(x - 1, k) >= l && x >= 2) {
            cout << "Case #" << t << ": " << k << endl;
            return;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) solve(i);

    return 0;
}
/*
Bài 1. POWER397 Lũy thừa
Cho l, r sao cho 2 ≤ 1≤ r ≤ 1012. Tìm số nguyên dương lớn nhất k sao cho tồn tại số nguyên dương x để 1≤ xk ≤ r.
Input:
· Dòng đầu tiên là số lượng test.
· Mỗi dòng tiếp theo chứa hai số nguyên I, r biểu thị một test.
Output: Đối với mỗi test in ra "Case #" + số hiệu test + ": " + số k lớn nhất tìm được.
Ví dụ:

Input

4
5 20
10 12
2 100
1000000000000 1000000000000

Ouput
Case #1: 4
Case #2: 1
Case #3: 6
Case #4: 12
*/