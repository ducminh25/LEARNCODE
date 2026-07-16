#include <bits/stdc++.h>
using namespace std;

uint64_t n, x, y;
uint64_t lcm (uint64_t a, uint64_t b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("ShenYun.Inp", "r")) {
        freopen("ShenYun.Inp", "r", stdin);
        freopen("ShenYun.Out", "w", stdout);
    }
    
    cin >> n >> x >> y;
    uint64_t ans;
    uint64_t mul = lcm(x, y);
    if (mul > n) {
        cout << 0 << endl;
        return 0;
    }
    
    ans = (uint64_t) n / mul;
    cout << ans << endl;
    return 0;
}