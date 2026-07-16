#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int limit = 1e9;
int n, a[maxn];

// vector<int> findDiv(int x) {
//     vector<int> res;
//     for (int i = 2; i * i <= x; ++i) {
//         if (x % i == 0) {
//             res.push_back(i);
//             while (x % i == 0) x /= i;
//         }
//     }
//     if (x > 1) res.push_back(x);
//     return res;
// }

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

void solve() {
    set<int> ans;
    int gcddiff = 0;

    for (int i = 1; i < n; ++i)
        gcddiff = __gcd(gcddiff, abs(a[i] - a[0]));
    for (int k = 1; k * k <= gcddiff; ++k) {
        if (gcddiff % k == 0) {
            if (k > 1) ans.insert(k);
            if (k != gcddiff / k && gcddiff / k > 1) ans.insert(gcddiff / k);
        }
    }

    if (ans.empty()) cout << -1;
    else if (ans.size() > limit) cout << -2;
    else for (auto it = ans.begin(); it != ans.end(); ++it) cout << *it << ' ';
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("MODULO.inp", "r")) {
        freopen("MODULO.inp", "r", stdin);
        freopen("MODULO.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}


/*
Cho dãy số nguyên a1, a2, ... , an. Yêu cầu tìm tất cả các số nguyên dương K >1 sao cho:
a1 % K = a2 % K = ...= an % K
Output: một dòng gồm tất cả các số K tìm được theo thứ tự tăng dần. Trường hợp không có số nào thì ghi -1, trường hợp số các số K nhiều quá 10^9 thì ghi ra số -2.
*/

/*
Sub full: sẽ có 2 số khác nhau, gọi a [i], a [j]:
    a [i] % K == a [j] % K ==> abs (a [i] - a [j]) % K == 0
    K phải là ước của abs (a [i] - a [j]); Thay vì xét full (code trâu) thì ta chỉ xét các số K là ước của abs (a [i] - a [j])
*/