#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
struct t {
    int h;
    int m;
};
t gio[maxn];

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> gio[i].h >> gio[i].m;
}

void solve() {
    sort(gio, gio + n, [](const t& a, const t& b) {
        return a.h * 60 + a.m < b.h * 60 + b.m;
    });

    int max_khach = 1;
    int khach_hien_tai = 1;

    for (int i = 1; i < n; ++i) {
        if (gio[i].h == gio[i-1].h && gio[i].m == gio[i-1].m) {
            khach_hien_tai++;
        } else {
            khach_hien_tai = 1;
        }
        max_khach = max(max_khach, khach_hien_tai);
    }

    cout << max_khach << '\n';
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    #define task "COFFEE"
    if(fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    input();
    solve();

    return 0;
}

/*
Khang mới mở một quán cà phê. Trước đó, Khang đã mời n bạn bè đến mừng ngày khai và mỗi người đã phản hồi chính xác thời gian người sẽ tới vào lúc hi giờ, mi phút.

Quán cà phê mất không quá 1 phút để phục vụ một khách hàng. Nhưng Khang muốn khi khách đến phải được phục vụ ngay lập tức, không được để khách hàng phải chờ đợi.

Vì Khang muốn phục vụ chu đáo tất cả n người khách, nên quán cần đảm bảo rằng trong mỗi thời điểm số nhân viên phục vụ không ít hơn số lượng khách.

Yêu cầu: Các bạn hãy giúp Khang tính số nhân viên ít nhất cần có mà vẫn có thể đảm bảo phục vụ trong ngày khai trương.

Input
Vào từ file văn bản COFFEE.INP gồm:

- Dòng đầu tiên ghi số nguyên n ( 1 ≤ n ≤ 105).

- n dòng tiếp theo, mỗi dòng gồm cặp số nguyên hi, mi tương ứng là giờ và phút mà người thứ i tới quán (0 ≤ hi ≤ 23, 0 ≤ mi ≤ 59).

Output
Ghi ra file văn bản COFFEE.OUT một số là số nhân viên ít nhất mà vẫn đảm bảo phục vụ được tất cả n người.

Ví dụ:
INPUT:
4
8 0
8 10
8 10
8 45
--> OUTPUT: 2


*/