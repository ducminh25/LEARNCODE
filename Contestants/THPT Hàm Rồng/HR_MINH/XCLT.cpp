#include <bits/stdc++.h>
using namespace std;
string s;
int n;

void input() {
    getline(cin, s);
    n = s.size();
}

void solve() {
    int start = 0, maxx = 0;
    string res;

    for (int end = 0; end < n; ++end) {
        if (end > 0 && s[end] == s[end - 1]) {
            start = end;
        }

        if (end - start + 1 > maxx ||
            (end - start + 1 == maxx && s.substr(start, maxx) > res)) {
            maxx = end - start + 1;
            res = s.substr(start, maxx);
        }
    }

    cout << res << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("XCLT.inp", "r")) {
        freopen("XCLT.inp", "r", stdin);
        freopen("XCLT.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
