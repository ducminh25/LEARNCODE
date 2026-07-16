#include <bits/stdc++.h>
using namespace std;
int n, m, s = 0;
struct bi {
    int a, b;
};
bi a[100005];

bool compare(bi x, bi y) {
    if(x.b > y.b) return true;
    else return false;
}

void input() {
    cin >> m >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].a >> a[i].b;
    }
}

void solve() {
    sort(a + 1, a + 1 + n, compare);
    for(int i = 1; i <= n; ++i) {
        if(m >= a[i].a) {
            m -= a[i].a;
            s += a[i].a * a[i].b;
        }
        else {
            s += m * a[i].b;
            break;
        }
    }
    cout << s << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
