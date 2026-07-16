// Tìm số lượng số nguyên từ 1 đến n chia hết cho tất cả m số đã nhập.
#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n;
    int m;
    cin >> n >> m;

    long long lcm_value = 1;
    for (int i = 0; i < m; i++) {
        long long num;
        cin >> num;
        lcm_value = lcm(lcm_value, num);
        if (lcm_value > n) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << n / lcm_value << endl;

    return 0;
}