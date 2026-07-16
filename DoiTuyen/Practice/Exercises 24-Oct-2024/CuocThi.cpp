#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAX_POS = 1000000005;
int n, q;
int x[MAXN];
int fen[MAXN];

void update(int i, int val, int n) {
    for (; i <= n; i += i & -i) {
        fen[i] += val;
    }
}

int query(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += fen[i];
    }
    return res;
}

int range_q(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("CuocThi.Inp", "r")) {
        freopen("CuocThi.Inp", "r", stdin);
        freopen("CuocThi.Out", "w", stdout);
    }

    cin >> n >> q;
    vector<int> tnv(n);
    for (int i = 0; i < n; ++i) {
        cin >> tnv[i];
    }

    vector<int> s_tnv = tnv;
    sort(s_tnv.begin(), s_tnv.end());
    s_tnv.erase(unique(s_tnv.begin(), s_tnv.end()), s_tnv.end());

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(s_tnv.begin(), s_tnv.end(), tnv[i]) - s_tnv.begin() + 1;
        update(pos, 1, n);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        int l = lower_bound(s_tnv.begin(), s_tnv.end(), a) - s_tnv.begin() + 1;
        int r = upper_bound(s_tnv.begin(), s_tnv.end(), b) - s_tnv.begin();
        if (l > r)
            cout << 0 << endl;
        else
            cout << range_q(l, r) << endl;
    }

    return 0;
}