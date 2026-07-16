// Đếm số lượng chữ số 0 ở tận cùng của số N!.
#include <bits/stdc++.h>
using namespace std;

int cnt(int n) {
    int res = 0;
    while (n % 5 == 0) {
        res++;
        n /= 5;
    }
    return res;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie(0);

    int n;
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        res += cnt(i);
    }
    cout << res << endl;
    return 0;
}