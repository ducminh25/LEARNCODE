#include <bits/stdc++.h>
using namespace std;
int a[20], b[20], x[20], n;
long long tong, tich, minn;

void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
}

void vet(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        tong = tong + j * b[i];
        if (j == 1) tich = tich * a[i];
        if (i == n) {
            if (abs(tong - tich) < minn && tong > 0)
                minn = abs(tong - tich);
        } else vet(i + 1);
        tong = tong - j * b[i];
        if (j == 1) tich = tich / a[i];
    }
}

void giai() {
    minn = 1000000000;
    tong = 0; tich = 1;
    vet(1);
    cout << minn;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("GIAVI.INP", "r")) {
        freopen("GIAVI.INP", "r", stdin);
        freopen("GIAVI.OUT", "w", stdout);
    }
    
    nhap();
    giai();

    return 0;
}
