#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define Unique(v) \
    sort(all(v)); \
    (v).erase(unique(all(v)), (v).end());
const ll N = 1e6 + 5;
ll n, a[N], f[N];
ll uoc(ll n) {
    ll s = 0;
    for (int i = 1; i * i < n; i++)
        if (n % i == 0) s += i + n / i;
    ll k = sqrt(n);
    if (k * k == n) s += k;
    return s;
}
void sub1() {
    for (int i = 1; i <= n; i++)
        cout << uoc(a[i]) << ' ';
}
void sub2() {
    for (ll i = 1; i * i <= a[n]; i++) {
        ll l = max((a[1] - 1) / i + 1, i);
        ll r = a[n] / i;
        for (int j = l; j <= r; j++)
            f[i * j - a[1]] += i + j * (i != j);
    }
    for (int i = 0; i < n; i++)
        cout << f[i] << ' ';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define task "TONGUOC"
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 100000)
        sub1();
    else
        sub2();
}

/* Tổng ước SUMDIV sumdiv.cpp
Bài toán tìm ước chung lớn nhất là bài toán cơ bản trong Tin học, nhưng để tìm chính xác và nhanh khi dữ liệu lớn thì không phải ai cũng biết. 
Để kiểm tra khả năng thuần thục và nhanh nhạy khi tìm ước chung lớn nhất thầy giáo đã đưa ra bài toán như sau:
 
Cho dãy A gồm n số nguyên dương a1, a2 ,..., an . Ứng với mỗi số nguyên dương ai, bạn hãy cho biết tổng các ước số dương của nó.
Dữ liệu: Vào từ file văn bản TONGUOC.INP:
-	Dòng thứ 1 chứa số nguyên n
-	Dòng thứ 2 chứa n số nguyên a1, a2, …, an
Kết quả: Đưa ra file văn bản TONGUOC.OUT gồm n số, số thứ i là tổng các ước số dương của ai
Ví dụ:

TONGUOC.INP	TONGUOC.OUT
4
2 4 10 9	3 7 18 13

*/