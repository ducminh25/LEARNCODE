// Tìm số mũ k lớn nhất trong các ước có dạng 2^k của số N!. Ví dụ: n = 6 --> T = 6! = (2 * 4 * 6) * 1 * 3 * 5 = (2^1 * 2^2 *2^1 * 3) * 1 * 3 * 5
#include <bits/stdc++.h>
using namespace std;
int n;

long long count(long long n, long long p) {
    long long res = 0, exp = p;
    while(n / exp > 0) {
        res += n / exp;
        exp *= p;
    }

    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    long long t = count(n, 2);
    cout << t << endl;

    return 0;
}
