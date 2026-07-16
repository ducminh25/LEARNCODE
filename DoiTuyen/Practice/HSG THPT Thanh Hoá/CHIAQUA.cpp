#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) count++;
            else count += 2;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen ("CAU1.INP", "r")) {
        freopen ("CAU1.INP", "r", stdin);
        freopen ("CAU1.OUT", "w", stdout);
    }
    int x, y;
    cin >> x >> y;
    int g = gcd(x, y);
    cout << countDivisors(g) << endl;

    return 0;
}