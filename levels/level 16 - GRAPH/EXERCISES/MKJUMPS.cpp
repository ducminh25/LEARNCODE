#include <bits/stdc++.h>
using namespace std;

int n, m, xx1, yy1, x2, y2, b[11][11] = {2};
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int x[1000], y[1000], xxx[1000], yyy[1000], maxx = 1;
void xuatb() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) cout << b[i][j];
        cout << endl;
    }
}
void vet(int i) {
    int vx, vy;
    for (int j = 0; j < 8; j++) {
        vx = x[i - 1] + dx[j];
        vy = y[i - 1] + dy[j];
        if (0 < vx && vx <= 10 && 0 < vy && vy <= 10 && b[vx][vy] == 0) {
            b[vx][vy] = 1;
            x[i] = vx;
            y[i] = vy;
            if (i > maxx) {
                maxx = i;
                for (int k = 1; k <= maxx; k++) {
                    xxx[k] = x[k];
                    yyy[k] = y[k];
                }
            }
            vet(i + 1);
            b[vx][vy] = 0;
        }
    }
}

int main() {
    // freopen("mkjumps.inp", "r", stdin);
    // freopen("mkjumps.out", "w", stdout);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) b[i][j] = 2;
    cin >> m;
    int p, q, u, v, s = 0;
    for (int i = 1; i <= m; i++) {
        cin >> p >> q;
        s = s + q;
        u = 1 + p;
        v = u + q - 1;
        for (int j = u; j <= v; j++) b[i][j] = 0;
    }
    // xuatb();
    xx1 = 1;
    for (int j = 1; j <= 10; j++)
        if (b[1][j] == 0) {
            yy1 = j;
            break;
        }
    x[1] = 1;
    y[1] = yy1;
    b[1][yy1] = 1;
    vet(2);
    cout << (s - maxx);
    //<<" "<<maxx;
    // for(int i=1;i<=maxx;i++)
    //  {
    //      cout<<xxx[i]<<" "<<yyy[i]<<endl;
    //  }
    return 0;
}
