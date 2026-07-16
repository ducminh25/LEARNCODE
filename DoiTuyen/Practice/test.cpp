/**
 *    author:  monhduc2k8
 *    created: 19.11.2025 22:08:34
 **/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

vector<int> get_pi(string s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());

    string combined = s + '#' + rev;
    vector<int> pi = get_pi(combined);

    int max_len = pi.back();
    string add = s.substr(max_len);
    reverse(add.begin(), add.end());

    cout << add << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("MKPALIN.INP", "r")) {
        freopen("MKPALIN.INP", "r", stdin);
        freopen("MKPALIN.OUT", "w", stdout);
    }

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}