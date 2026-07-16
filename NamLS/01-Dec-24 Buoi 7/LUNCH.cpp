#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pll pair<long long, long long>

const int maxn = 1e5 + 5;
long long n, m;
pll dish[maxn];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> dish[i].fi >> dish[i].se;
}

bool check(int maxspicy) {
    long long sum = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        if (dish[r].se < maxspicy) {
            sum += dish[r].fi;
            while (sum >= m) return true;
        }
        else {
            sum = 0;
            l = r + 1;
        }
    }
    return false;
}

int binary_search() {
    int l = 0, r = 1e9, res = INT_MIN;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("LUNCH.inp", "r")) {
        freopen("LUNCH.inp", "r", stdin);
        freopen("LUNCH.out", "w", stdout);
    }

    input();
    cout << binary_search() << '\n';

    return 0;
}

/*
WA on test 1:
Các đầu bếp đang chuẩn bị một bữa ăn ngon cho các bạn học sinh ăn bán trú tại trường THPT XYZ. 
Trong nhà ăn, người ta đặt N món ăn thành một hàng ngang. Món ăn thứ i có hương vị Fi và độ cay Si.
Bữa ăn của các bạn học sinh sẽ bao gồm một dãy các món ăn liên tiếp. 
Tổng hương vị của bữa ăn là tổng hương vị các món ăn được chọn, độ cay của bữa ăn là độ cay tối đa của tất cả các loại món ăn trong số những món ăn liên tiếp được chọn.
Bạn Cuội (một học sinh trong trường) muốn xác định độ cay tối thiểu của bữa ăn trưa mà bạn ấy cần phải lựa chọn, với điều kiện là dãy món ăn liên tiếp được chọn phải có tổng hương vị ít nhất là m.

Input:
- Dòng 1 chứa hai số n và m (1 <= n <= 10^5; 1 <= m <= 10^18).
- n dòng tiếp theo, dòng thứ i chứa một cặp (Fi, Si) thể hiện hương vị và độ cay của các món ăn thứ i (1 <= Fi, Si <= 10^9).

Output: một số nguyên duy nhất là độ cay nhỏ nhất của bữa ăn trưa hôm đó của bạn Cuội.

Ví dụ:
INPUT:
5 10
4 10
6 15
3 5
4 9
3 6

OUTPUT: 9
*/