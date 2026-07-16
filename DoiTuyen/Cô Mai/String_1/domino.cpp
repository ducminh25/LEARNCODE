#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("domino.inp", "r", stdin);
    freopen("domino.out", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'L') {
                ans += 'R';
            } else if (s[i] == 'R') {
                ans += 'L';
            } else if (s[i] == 'U') {
                ans += 'D';
            } else {
                ans += 'U';
            }
        }
        cout << ans << endl;
    }
    return 0;
}