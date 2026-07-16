#include <bits/stdc++.h>
using namespace std;
string s;

int toInt(char c) {
    return c - '0';
}

long long cal(string s) {
    long long res = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') continue;
        res += toInt(s[i]) * (i + 1);
    }

    return res;
}

void solve() {
    int j = s.find('?');
    long long tmp = cal(s);
    bool ok = false;
    if (j == 0) {
        for (int i = 1; i <= 9; ++i) {
            if ((tmp + i * (j + 1)) % 7 == 0) {
                ok = true;
                cout << i;
                return;
            }
        }
    }
    else {
        for (int i = 0; i <= 9; ++i) {
            if ((tmp + i * (j + 1)) % 7 == 0) {
                ok = true;
                cout << i;
                return;
            }
        }
    }
    
    if(!ok) cout << -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI1.inp", "r")) {
        freopen("BAI.inp", "r", stdin);
        freopen("BAI1.out", "w", stdout);
    }

    getline(cin, s);
    solve();

    return 0;
}
