// O(N * K)
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
int n, k;
string s;

inline bool isValid(int pos, char c, const string& current_s) {
    if (pos - 1 >= 0 && current_s[pos - 1] == c) return false;
    if (pos - 2 >= 0 && current_s[pos - 2] == c) return false;
    return true;
}

void solve() {
    if (!(cin >> n >> k >> s)) return;
    int pivot = -1;

    for (int i = n - 1; i >= 0; --i) {
        for (char c = s[i] + 1; c < 'a' + k; ++c) {
            if (isValid(i, c, s)) {
                s[i] = c;
                pivot = i;
                goto BUILD_SUFFIX;
            }
        }
    }

    cout << "NO\n";
    return;

BUILD_SUFFIX:
    for (int i = pivot + 1; i < n; ++i) {
        for (char c = 'a'; c < 'a' + k; ++c) {
            if (isValid(i, c, s)) {
                s[i] = c;
                break;
            }
        }
    }
    cout << s << "\n";
}

int main() {
    fast_io;
    if(fopen("ANTIPALIN.INP", "r")) {
        freopen("ANTIPALIN.INP", "r", stdin);
        freopen("ANTIPALIN.OUT", "w", stdout);
    }
    solve();
    return 0;
}