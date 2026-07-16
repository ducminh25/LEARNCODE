/*
Cho dãy số a1, a2, ... , an. Yêu cầu chọn ra 4 số x, y, u, v sao cho: 1 <= x <= y < u <= v <= n và tổng S = a[x] + a[x + 1]+ ... + a[y] + a[u] + a[u + 1] + ... + a[v] lớn nhất.
Input
- Dòng 1 chứa số nguyên dương n (2 <= n <= 50000).
- Dòng 2 chứa N số nguyên a1, a2, ... , an(|ai| <= 10^6).

Output: một số nguyên duy nhất là tổng giá trị lớn nhất.

Ví dụ:
Input:
5
1 1 -5 2 3
Output:
7

FAILED on test 1
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int n, a[N], L[N], R[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen("HAIDOAN.INP", "r")) {
        freopen("HAIDOAN.INP", "r", stdin);
        freopen("HAIDOAN.OUT", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int sum = 0, maxL = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        maxL = max(maxL, sum);
        L[i] = maxL;
    }

    sum = 0, maxL = 0;
    for (int i = n; i >= 1; i--) {
        sum += a[i];
        maxL = max(maxL, sum);
        R[i] = maxL;
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, L[i] + R[i + 1]);

    cout << ans << endl;
    return 0;
}
