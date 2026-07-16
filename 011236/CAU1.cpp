#include <bits/stdc++.h>
using namespace std;
uint64_t n, a, b;

uint64_t gcd(uint64_t a, uint64_t b) {
    while (b) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

uint64_t lcm(uint64_t a, uint64_t b) {
    return (a / gcd(a, b)) * b; 
}

void input() {
    cin >> n >> a >> b;
}

void solve() {
    uint64_t lcm_ab = lcm(a, b);
    uint64_t result = n / lcm_ab;
    
    cout << result << endl;

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU1.inp", "r")) {
        freopen("CAU1.inp", "r", stdin);
        freopen("CAU1.out", "w", stdout);
    }
    input();
    solve();
    
    return 0;
}

// Miss calculation of prime numbers