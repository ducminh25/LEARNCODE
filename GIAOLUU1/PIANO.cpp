#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;
int a[MAXN];
int trace[MAXN][6]; // trace[i][j]: ngón tay ở nốt i-1 đã dẫn đến ngón j ở nốt i

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(fopen("piano.inp", "r")) {
        freopen("piano.inp", "r", stdin);
        freopen("piano.out", "w", stdout);
    }

    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 2; i <= n; ++i) {
        for (int cur = 1; cur <= 5; ++cur) {        // Ngón hiện tại
            for (int prev = 1; prev <= 5; ++prev) { // Ngón trước đó
                // Kiểm tra nếu nốt trước đó (prev) chưa đến được thì bỏ qua
                // Riêng với i=2, nốt 1 luôn đến được bằng mọi ngón
                if (i > 2 && trace[i - 1][prev] == 0) continue;

                bool ok = false;
                if (a[i] > a[i - 1]) {
                    if (cur > prev) ok = true;
                } else if (a[i] < a[i - 1]) {
                    if (cur < prev) ok = true;
                } else { // a[i] == a[i-1]
                    if (cur != prev) ok = true;
                }

                if (ok) {
                    trace[i][cur] = prev;
                    break; // Chỉ cần tìm 1 đường đi hợp lệ là đủ
                }
            }
        }
    }

    int last_finger = -1;
    for (int j = 1; j <= 5; ++j) {
        // Nếu n=1 thì ngón nào cũng được, nếu n>1 thì cần có vết
        if (n == 1 || trace[n][j] != 0) {
            last_finger = j;
            break;
        }
    }

    if (last_finger == -1) {
        cout << -1;
    } else {
        vector<int> res;
        res.push_back(last_finger);
        for (int i = n; i > 1; --i) {
            last_finger = trace[i][last_finger];
            res.push_back(last_finger);
        }
        reverse(res.begin(), res.end());

        for (int x : res) cout << x << " ";
    }

    return 0;
}