#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
int n, m;
int a[100005], b[20];
set<long long> s;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];
}

void genSum(int i, long long sum) {
    if (i > m) {
        if (sum != 0) {
            s.insert(sum);
        }
        return;
    }
    genSum(i + 1, sum);
    genSum(i + 1, sum + b[i]);
}

void solve() {
    genSum(0, 0);
    // for(auto &sum : s) cout << sum << " ";
    // cout << endl;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (s.find(a[i]) != s.end()) {
            ++cnt;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // auto start = high_resolution_clock :: now();
    // freopen("random.inp", "r", stdin);
    // freopen("CHECK.out", "w", stdout);
    if(fopen("CHECK.inp", "r")) {
        freopen("CHECK.inp", "r", stdin);
        freopen("CHECK.out", "w", stdout);
    }

    input();
    solve();

    // auto end = high_resolution_clock :: now();
    // auto duration = duration_cast<milliseconds> (end - start);
    // cout << endl << "Time: " << duration.count() << " ms" << endl;

    return 0;
}
