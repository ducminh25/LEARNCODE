#include <bits/stdc++.h>
using namespace std;

void solve() {
    string X, Y;
    cin >> X >> Y;
    bool ok = false;
    for (char c : X) {
        if (Y.find(c) != string::npos) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(NULL); cout.tie(NULL);
 
    if(fopen("PALIN.inp", "r")) {
        freopen("PALIN.inp", "r", stdin);
        freopen("PALIN.out", "w", stdout);
    }
    
    int T;
    cin >> T;
    while (T--)
        solve();
    
    return 0;
}