#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
vector<int> a;

void input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void solve() {
    int maxx = *max_element(a.begin(), a.end());
    int minn = *min_element(a.begin(), a.end());
    
    int minlen = n;
    int lmax = -1, lmin = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i] == maxx) {
            lmax = i;
            if (lmin != -1) {
                minlen = min(minlen, lmax - lmin + 1);
            }
        }
        if (a[i] == minn) {
            lmin = i;
            if (lmax != -1) {
                minlen = min(minlen, lmin - lmax + 1);
            }
        }
    }

    cout << minlen << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("DOANCON.inp", "r")) {
        freopen("DOANCON.inp", "r", stdin);
        freopen("DOANCON.out", "w", stdout);
    }

    input();
    solve();
    
    return 0;
}