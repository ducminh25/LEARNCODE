#include <bits/stdc++.h>
using namespace std;

struct qq {
    long long a, b; // a = start, b = finish
    int tt;          // original index
};
int n;
qq s[1000005];
int kq[1000005];

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i].a >> s[i].b;
        s[i].tt = i; // lưu số hiệu cuộc họp
    }
}

// So sánh theo thời điểm kết thúc (b), nếu bằng thì theo thời điểm bắt đầu (a)
bool ss(const qq &x, const qq &y) {
    if (x.b != y.b) return x.b < y.b;
    return x.a < y.a;
}

void solve() {
    // sort theo thời điểm kết thúc
    sort(s + 1, s + n + 1, ss);

    // Bước 2: chọn cuộc họp
    long long last_end = -1;
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (s[i].a >= last_end) {
            cnt++;
            kq[cnt] = s[i].tt;
            last_end = s[i].b;
        }
    }

    cout << cnt << "\n";
    for (int i = 1; i <= cnt; ++i) cout << kq[i] << "\n";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("ACTIVITY.INP", "r")) {
        freopen("ACTIVITY.INP", "r", stdin);
        freopen("ACTIVITY.OUT", "w", stdout);
    }

    input();
    solve();

    return 0;
}
