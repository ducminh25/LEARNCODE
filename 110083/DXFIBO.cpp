#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long> fiblen(93);

void precompute() {
    fiblen[1] = 1;
    fiblen[2] = 1;
    for (int i = 3; i < 93; ++i) {
        fiblen[i] = fiblen[i - 1] + fiblen[i - 2];
    }
}

char getFiboCharacter(int n, unsigned long long i) {
    while (n > 2) {
        if (i <= fiblen[n - 2]) {
            n -= 2;
        } else {
            i -= fiblen[n - 2];
            n -= 1;
        }
    }
    return (n == 1) ? 'A' : 'B';
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("DXFIBO.inp", "r")) {
        freopen("DXFIBO.inp", "r", stdin);
        freopen("DXFIBO.out", "w", stdout);
    }

    precompute();
    int t;
    cin >> t;
    while (t--) {
        int n;
        unsigned long long i;
        cin >> n >> i;
        cout << getFiboCharacter(n, i) << endl;
    }
    return 0;
}