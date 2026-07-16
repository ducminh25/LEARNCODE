#include <bits/stdc++.h>
using namespace std;
int n, x[100005];

void output() {
    for (int i = 1; i <= n; ++i) cout << x[i] << ' ';
    cout << endl;
}

void vet(int i) {
    for (int j = 0; j <= 1; ++j) {
        x[i] = j;
        if (i == n) output();
        else vet(i + 1);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(fopen("NHIPHAN.inp", "r")) {
        freopen("NHIPHAN.inp", "r", stdin);
        freopen("NHIPHAN.out", "w", stdout);
    }
    cin >> n;
    vet(1);

    return 0;
}