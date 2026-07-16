#include <bits/stdc++.h>
using namespace std;

int output(const string& s) {
    int n = s.length();
    vector<int> last(26, -1);
    int maxlen = 0;
    
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        if (last[c] != -1) {
            int len = 1;
            while (i + 1 < n && s[i] == s[i+1]) {
                ++len;
                ++i;
            }
            maxlen = max(maxlen, min(len, i - last[c]));
        }
        last[c] = i;
    }
    
    return maxlen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    if(fopen("XAUCON.inp", "r")) {
        freopen("XAUCON.inp", "r", stdin);
        freopen("XAUCON.out", "w", stdout);
    }
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << output(s) << '\n';
    }
    
    return 0;
}