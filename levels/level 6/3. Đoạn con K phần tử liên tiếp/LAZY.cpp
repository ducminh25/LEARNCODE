#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000000], x, c, i, s = 0, maxx = -1, nmax = -1;
void nhap() {
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> c >> x;
        a[x] = c;
        if (nmax < x)
            nmax = x;
    }
}
void giai() {
    for (i = 0; i <= 2 * k; i++)
        s = s + a[i];
    maxx = s;
    for (i = 2 * k + 1; i <= nmax; i++) {
        s = s + a[i] - a[i - (2 * k + 1)];
        if (s > maxx)
            maxx = s;
    }
    cout << maxx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    nhap();
    giai();
}
