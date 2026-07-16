#include <bits/stdc++.h>
using namespace std;

int n, d[20001], res = 0, k, b[20001];
struct point {
    int x, y;
};
point a[20001];

bool cmp(point u, point v) {
    if (u.x < v.x) return true;
    if (u.x > v.x) return false;
    if (u.y > v.y) return true;
    if (u.y < v.y) return false;
    return false;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
}
void bs(int l, int r, int x) {
    if (r >= l) {
        int mid = (l + r) / 2;
        if (b[mid] >= x) {
            k = mid;
            bs(mid + 1, r, x);
        } else
            bs(l, mid - 1, x);
    }
}
void solve() {
    sort(a + 1, a + 1 + n, cmp);

    res = 1;
    d[1] = 1;
    b[1] = a[1].y;
    for (int i = 2; i <= n; ++i) {
        k = 0;
        bs(1, res, a[i].y);
        d[i] = k + 1;
        b[d[i]] = a[i].y;
        res = max(res, d[i]);
    }
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if(fopen("LATDAT.INP", "r")) {
        freopen("LATDAT.INP", "r", stdin);
        freopen("LATDAT.OUT", "w", stdout);
    }

    input();
    solve();
}
