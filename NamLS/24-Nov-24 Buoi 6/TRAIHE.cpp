#include <bits/stdc++.h>
using namespace std;
int a, b;

void input() {
    cin >> a >> b;
}

int res = 0;
void solve() {
    res += a;
    while (b > 0) {
        res++;
        b = b - 3;
    }

    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("TRAIHE.inp", "r")) {
        freopen("TRAIHE.inp", "r", stdin);
        freopen("TRAIHE.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
Sau khi học sinh đã đăng kí danh sách tham gia trại hè. Nhà trường cần đặt phòng khách sạn theo nhu cầu của học sinh. 
Theo thông tin đăng kí nhận được thì có a học sinh muốn ở phòng riêng (một mình một phòng) và có b học sinh không có yêu cầu gì, tùy theo sắp xếp của nhà trường.
Biết rằng mỗi phòng chỉ ở tối đa 3 học sinh.
Yêu cầu: Hãy tính số lượng phòng ít nhất mà nhà trường cần đặt.
*/