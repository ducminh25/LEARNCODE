// Chia hết cho 30. Bài 3 năm 2022
#include <bits/stdc++.h>
using namespace std;
string s;

void solve() {
    int n = s.size();
    sort(s.begin(), s.end(), greater<char>());
    if (s[n - 1] != '0') {
        cout << -1;
        return;
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += s[i] + '0';
    }
    if (sum % 3 == 0) {
        cout << s;
    }
    else cout << -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    if(fopen("MATMA.inp", "r")) {
        freopen("MATMA.inp", "r", stdin);
        freopen("MATMA.out", "w", stdout);
    }

    cin >> s;
    solve();

    return 0;
}
