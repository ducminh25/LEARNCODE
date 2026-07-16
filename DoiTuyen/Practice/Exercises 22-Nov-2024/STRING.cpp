#include <bits/stdc++.h>
using namespace std;
string a, b;

void input() {
    cin >> a >> b;
}

int freq[15];
void solve() {
    int sizea = a.size();
    int sizeb = b.size();
    for(int i = 0; i < sizea; ++i) {
        freq[a[i] - '0']++;
    }
    for(int i = 0; i < sizeb; ++i) {
        freq[b[i] - '0']++;
    }
    set<int, greater<int>> res;
    bool ok = false;
    for(int i = 0; i <= 9; ++i) {
        if(freq[i] > 1) {
            res.insert(i);
            ok = true;
        }
    }
    if(ok)
        for (auto it = res.begin(); it != res.end(); ++it)
            cout << *it;
    else
        cout << -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("STRING.inp", "r")) {
        freopen("STRING.inp", "r", stdin);
        freopen("STRING.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}