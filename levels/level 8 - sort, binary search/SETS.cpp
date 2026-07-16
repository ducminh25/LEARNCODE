#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct segment {
    int l, r;
};

int n;
segment d[maxn];
long long cnt = 0;
vector<int> b;

bool cmp(const segment &a, const segment &b) {
    return a.r < b.r || a.l < b.l;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i].l >> d[i].r;
    }
}

void solve() {
    sort(d + 1, d + n + 1, cmp);
    
    b.push_back(d[1].r - 1);
    b.push_back(d[1].r);
    cnt = 2;
    
    for (int i = 2; i <= n; ++i) {
        if (d[i].l > b.back()) {
            b.push_back(d[i].r - 1);
            b.push_back(d[i].r);
            cnt += 2;
        } else if (d[i].l > b[b.size() - 2]) {
            b.push_back(d[i].r);
            cnt++;
        }
    }
    
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    solve();
    
    return 0;
}