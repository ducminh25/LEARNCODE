#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define Unique(v) \
    sort(all(v)); \
    (v).erase(unique(all(v)), (v).end());

const int N = 105;

int n, k, q;
int a[N];

#define tup tuple<int, int, int>

void Solve() {
    cin >> n >> k >> q;

    memset(a, -1, sizeof a);

    vector<tup> ev;

    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        ev.emplace_back(c, l, r);
    }

    sort(all(ev));

    for (auto [c, l, r] : ev) {
        if (c == 1) {
            for (int i = l; i <= r; i++)
                a[i] = k;
        } else {
            for (int i = l; i <= r; i++)
                a[i] += (a[i] == k);
        }
    }

    int cur = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            a[i] = cur;

            cur++;
            if (cur == k) cur = 0;
        }

        cout << a[i] << ' ';
    }

    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#define task "mexarray"
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    if (fopen("task.inp", "r")) {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }

    int T;
    cin >> T;
    while (T--) Solve();

    // cerr << setprecision(3) << fixed << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}
