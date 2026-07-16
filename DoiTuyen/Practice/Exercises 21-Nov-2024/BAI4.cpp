#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if(fopen("BAI4.inp", "r")) {
        freopen("BAI4.inp", "r", stdin);
        freopen("BAI4.out", "w", stdout);
    }

    long long L, G;
    cin >> L >> G;

    if (G % L != 0) {
        cout << "-1 -1" << endl;
        return 0;
    }
    long long product = G / L;
    long long a = L, b = G;
    for (long long i = 1; i * i <= product; i++) {
        if (product % i == 0) {
            long long j = product / i;
            if (gcd(i, j) == 1) {
                long long new_a = L * i;
                long long new_b = L * j;
                if (new_a + new_b < a + b) {
                    a = new_a;
                    b = new_b;
                }
            }
        }
    }

    if (a > b) swap(a, b);
    cout << a << " " << b << endl;

    return 0;
}