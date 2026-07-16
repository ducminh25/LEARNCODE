#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k;
vector<int> a;

void input() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void solve() {
    int res = 1;
    int curlen = 1;
    int remain = k;

    for (int i = 1; i < n; ++i) {
        int gap = a[i] - a[i - 1] - 1;
        if (gap == 0) curlen++;
        else if (gap <= remain) {
            curlen += gap + 1;
            remain -= gap;
        }
        else {
            res = max(res, curlen);
            curlen = min(remain, gap) + 1;
            remain = k - min(remain, gap);
        }
        res = max(res, curlen);
    }

    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("RDO.inp", "r")) {
        freopen("RDO.inp", "r", stdin);
        freopen("RDO.out", "w", stdout);
    }
    
    input();
    solve();

    return 0;
}