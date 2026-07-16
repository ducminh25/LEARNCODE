// BCNN (Least Common Multiple)
#include <bits/stdc++.h>
using namespace std;
uint64_t n, x, y;

uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

uint64_t lcm (uint64_t a, uint64_t b) {
    uint64_t multi = a * b;
    uint64_t g = gcd(a, b);
    return multi / g;
}

int main() {
    cin >> x >> y;
    cout << lcm(x, y);
    return 0;
}
