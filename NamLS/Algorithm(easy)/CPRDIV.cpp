/* Tổ hợp chập m của n phần tử
 * Đếm số lượng ước nguyên tố của:
 * S =      n!/(m!(n - m)!)
 */
#include <bits/stdc++.h>
using namespace std;
int c[100000] = {0};  // đếm ước ngto từ m+1 tới n
int c1[100000] = {0}; // đếm ước ngto từ 2 tới n-m
int n, m;

void input() {
    cin >> n >> m;
}

void solve() {
    // Đếm số mũ của các ước nguyên tố trong khoảng từ m+1 đến n
    for (int i = m + 1; i <= n; ++i) {
        int t = i;
        int k = 2;
        while (t != 1) {
            if (t % k == 0) {
                c[k]++;
                t /= k;
            } else
                k++;
        }
    }

    // Đếm số mũ của các ước nguyên tố trong khoảng từ 2 đến n-m
    for (int i = 2; i <= n - m; i++) {
        int t = i;
        int k = 2;
        while (t != 1) {
            if (t % k == 0) {
                c1[k]++;
                t /= k;
            } else
                k++;
        }
    }

    // Đếm số lượng ước nguyên tố mà số mũ của chúng trong (m+1 tới n) lớn hơn trong (2 tới n-m)
    int d = 0;
    for (int i = 2; i < 100000; ++i)
        if (c[i] > c1[i]) d++;

    cout << d;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("CPRDIV.inp", "r")) {
        freopen("CPRDIV.inp", "r", stdin);
        freopen("CPRDIV.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
