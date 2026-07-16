/*
Cho ba số tự nhiên a, b, k (1 <= a, b <= 10^9; 1 <= k <= 15). Hãy tìm số tự nhiên c nhỏ nhất sao cho tích của a * b * c có k chữ số tận cùng.
*/
#include <bits/stdc++.h>
using namespace std;
// ft = factor, thừa số
long long ft2 = 0, ft5 = 0, a, b, k, c = 1;

void factor(long long x) {
    while (x % 2 == 0) {
        ft2++, x /= 2;
    }
    while (x % 5 == 0) {
        ft5++, x /= 5;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> k;
    
    factor(a); factor(b);
    while (ft2 < k) {
        c *= 2;
        ft2++;
    }
    while (ft5 < k) {
        c *= 5;
        ft5++;
    }
    cout << c;

    return 0;
}
