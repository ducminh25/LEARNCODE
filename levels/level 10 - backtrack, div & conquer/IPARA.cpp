// Phân tích số
#include <bits/stdc++.h>
using namespace std;
int n, x[1000], cnt, s = 0;

void input() {
    cin >> n;
}

void out(int k) {
    for (int i = 1; i <= k; ++i) {
        cout << x[i] << ' ';
    }
    cnt++;
    cout << endl;
}

void vet(int i) {
    for (int j = x[i - 1]; j <= n; ++j) {
        x[i] = j;
        s += j;
        if (s == n) out(i);
        if (s < n && i < n) vet(i + 1);
        s -= j;
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("ipara.inp", "r")) {
        freopen("ipara.inp", "r", stdin);
        freopen("ipara.out", "w", stdout);
    }
    input();
    x[0] = 1;
    vet(1);
    cout << cnt;

    return 0;
}