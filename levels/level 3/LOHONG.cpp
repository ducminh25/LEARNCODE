#include <bits/stdc++.h>
using namespace std;
const int a[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
string s;

void input() {
    getline(cin, s);
}

int toInt (char c) {
    return c - '0';
}

void solve() {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res += a[toInt(s[i])];
    }
    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
