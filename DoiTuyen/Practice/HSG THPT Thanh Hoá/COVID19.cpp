#include <bits/stdc++.h>
using namespace std;
long long n, a, b;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI1.inp", "r")) {
        freopen("BAI1.inp", "r", stdin);
        freopen("BAI1.out", "w", stdout);
    }
    // N: số người cần cách ly, a: số người biết cách ly, b: danh sách (có thể thiếu) số người không cách ly tốt
    cin >> n >> a >> b;
    long long minn = max(0LL, a - b); // a <= b --> 0; a > b --> a - b
    long long maxx = min(a, n - b);   // a + b <= n --> a; a + b > n --> n - b
    cout << minn << ' ' << maxx << endl;

    return 0;
}
