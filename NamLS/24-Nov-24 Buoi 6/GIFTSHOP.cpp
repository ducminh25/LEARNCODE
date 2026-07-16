#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n, k, res;

void input() {
    cin >> n >> k;
}

void solve() {
    res = 0;
    // step
    long long s = k + 1;
    for (long long i = s; i <= n; i += s) {
        bool taken = false;
        for (long long j = 2; j <= k && j * j <= i; ++j) {
            if (i % j == 0) {
                taken = true;
                break;
            }
        }
        if (!taken) res++;
    }

    cout << res << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("GIFTSHOP.inp", "r")) {
        freopen("GIFTSHOP.inp", "r", stdin);
        freopen("GIFTSHOP.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
Cửa hàng có n phần quà khuyến mãi đánh số từ 1 tới n và một kế hoạch trao tặng khách hàng khá thú vị:
Khách hàng thứ i vào mua hàng sẽ được tặng hết các phần quà khuyến mãi còn lại có số hiệu chia hết cho i + 1.
Trong khi xếp hàng đợi vào mua, Đức thấy mình đứng ở số thứ tự k.
Đức muốn nhẩm tính xem mình có thể may mắn được tặng bao nhiêu phần quà từ cửa hàng này.

Input gồm một dòng chứa 2 số nguyên dương n <= 2*10^9 và k <= 2*10^9.
Output gồm một số nguyên duy nhất là số quà mà Đức được tặng.

TLE 2/12 test. Còn lại AC

Không dùng bao hàm - loại trừ, vì bị WA 10/12 test.
*/