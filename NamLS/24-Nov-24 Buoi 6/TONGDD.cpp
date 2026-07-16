#include <bits/stdc++.h>
using namespace std;
int n;
struct segment {
    int x, d;
};
vector<segment> s;

bool cmp(segment a, segment b) {
    return a.x < b.x;
}

void input() {
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i].x >> s[i].d;
    }
}

void solve() {
    sort(s.begin(), s.end(), cmp);
    int res = 0;
    int curEnd = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (s[i].x > curEnd) {
            res += s[i].d;
            curEnd = s[i].x + s[i].d;
        } else {
            int newEnd = max(curEnd, s[i].x + s[i].d);
            res += max(0, newEnd - curEnd);
            curEnd = newEnd;
        }
    }
    cout << res << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("TONGDD.inp", "r")) {
        freopen("TONGDD.inp", "r", stdin);
        freopen("TONGDD.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
Cho N đoạn thẳng trên trục số với các điểm đầu xi và độ dài di (|xi|, di là những số nguyên không vượt quá 10^9). Tính tổng độ dài trên trục số bị phủ bởi N đoạn trên.
Ví dụ: Có 3 đoạn x1 = -5, d1 = 10; x2 = 0, d2 = 6; x3 = -100, d3 = 10 thì tổng độ dài trên trục số bị phủ bởi 3 đoạn trên là 21.

Input
vào từ tệp văn bản TONGDD.INP gồm:

- Dòng 1 ghi số nguyên dương N (1 <= N <= 10^4);

- Dòng thứ i trong n dòng tiếp theo ghi tọa độ điểm đầu và độ dài của đoạn thẳng thứ i.

Output
Ghi ra tệp văn bản TONGDD.OUT ghi một số là tổng độ dài trên trục số bị phủ bởi N đoạn thẳng đã cho.
*/