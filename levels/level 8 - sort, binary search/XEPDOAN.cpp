#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct segment {
    int x1, x2;
};
segment d[maxn];
int n;

void input() {
    int k;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i].x1 >> k;
        d[i].x2 = d[i].x1 + k;
    }
}

bool cmp (segment a, segment b) {
    if (a.x1 < b.x1) return true;
    return false;
}

void solve() {
    sort (d + 1, d + n + 1, cmp);
    long long a = d[1].x1;
    long long b = d[1].x2;
    
    long long res = 0;
    for (int i = 2; i <= n; ++i) {
        if (b >= d[i].x1) {
            if (d[i].x2 > b) b = d[i].x2;
        }
        else {
            res += b - a;
            a = d[i].x1;
            b = d[i].x2;
        }
    }
    res += b - a;
    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
