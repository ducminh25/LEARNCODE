#include <bits/stdc++.h>
using namespace std;
int n, a[5005][5005], b[1005][1005], maxv, minv, minn, k;
void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] > maxv) maxv = a[i][j];
            if (a[i][j] < minv) minv = a[i][j];
        }
}

bool bfs(int minn, int k) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) b[i][j] = 0;
    for (int i = 0; i <= n + 1; i++) {
        b[0][i] = 1;
        b[n + 1][i] = 1;
        b[i][0] = 1;
        b[i][n + 1] = 1;
    }
    int h[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};
    int d = 0, xx, yy;
    queue<int> qx, qy;
    qx.push(1);
    qy.push(1);
    b[1][1] = 1;
    while (!qx.empty()) {
        xx = qx.front();
        yy = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 0; i <= 3; i++) {
            int u = xx + h[i], v = yy + c[i];
            if (b[u][v] == 0 && a[u][v] >= minn && a[u][v] - minn <= k) {
                if (u == n && v == n) return true;
                qx.push(u);
                qy.push(v);
                b[u][v] = 1;
            }
        }
    }
    return false;
}
int bs(int minn, int l, int r) {
    // cout<<minn<<" "<<l<<" "<<r<<endl;
    int res = maxv - minv;
    while (l <= r) {
        int mid = (l + r) / 2;
        // cout<<minn<<" "<<mid<<endl;
        if (bfs(minn, mid) == true) {
            res = mid;
            // cout<<mid<<endl;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return res;
}

void giai() {
    int mink = 10000000;
    for (int i = minv; i <= a[1][1]; i++) {
        int k = bs(i, 0, maxv - minv);
        if (k < mink) mink = k;
    }
    cout << mink;
}
int main() {
    // freopen("mtwalk.inp", "r", stdin);
    // freopen("mtwalk.out", "w", stdout);
    nhap();
    giai();
}

/*
xx...
.xx..   
..x..
..x..
..xxx
*/