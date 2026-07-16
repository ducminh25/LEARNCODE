// Xâu hoán vị, hoán vị của xâu

#include <bits/stdc++.h>
using namespace std;
char x[10];
string c, a;
int n, d[1000];

void out() {
    for (int i = 1; i <= n; ++i) cout << x[i];
    cout << endl;
}

void vet(int i) {
    for (int j = 65; j <= 91; ++j) {
        if (d[j] > 0) {
            x[i] = char(j);
            d[j]--;
            if (i == n)
                out();
            else
                vet(i + 1);
            d[j]++;
        }
    }
}

void input() {
    cin >> a;
    n = a.length();
    for (int i = 0; i <= n - 1; ++i) {
        d[int(a[i])]++;
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen("XAUHV.inp", "r")) {
        freopen("XAUHV.inp", "r", stdin);
        freopen("XAUHV.out", "w", stdout);
    }

    input();
    vet(1);

    return 0;
}

/*
Cho xâu S, chỉ gồm các kí tự ′A′ đến ′Z′ (các kí tự trong S không nhất thiết phải khác nhau).

Yêu cầu: Hãy liệt kê tất cả các hoán vị khác nhau của xâu S.
XAUHV.cpp
Input
Xâu S độ dài không vượt quá 8
Output
K dòng sau xuất các hoán vị của S, mỗi hoán vị trên một dòng. Theo thứ tự từ điển.
*/