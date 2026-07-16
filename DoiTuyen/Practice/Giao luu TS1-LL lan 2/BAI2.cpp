#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, k, a[maxn];
string s;

void input() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < k; ++i) cin >> a[i];
}

void solve() {
    long long dis = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1])
            dis += 2;
        else
            dis += 1;
    }
    
    for (int i = 0; i < k; ++i) {
        a[i] -= 1;
        if (s[a[i]] == '0') {
            if (a[i] + 1 < n && s[a[i] + 1] == '1') dis += 1;
            if (a[i] - 1 >= 0 && s[a[i] - 1] == '1') dis += 1;
            if (a[i] + 1 < n && s[a[i] + 1] == '0') dis -= 1;
            if (a[i] - 1 >= 0 && s[a[i] - 1] == '0') dis -= 1;
            s[a[i]] = '1';
        }

        else {
            if (a[i] + 1 < n && s[a[i] + 1] == '1') dis -= 1;
            if (a[i] - 1 >= 0 && s[a[i] - 1] == '1') dis -= 1;
            if (a[i] + 1 < n && s[a[i] + 1] == '0') dis += 1;
            if (a[i] - 1 >= 0 && s[a[i] - 1] == '0') dis += 1;
            s[a[i]] = '0';
        }

        cout << dis << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("Bai2.inp", "r")) {
        freopen("Bai2.inp", "r", stdin);
        freopen("Bai2.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
