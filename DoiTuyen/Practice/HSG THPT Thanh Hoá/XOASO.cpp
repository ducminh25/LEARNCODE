// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// string n;

// void solve() {
//     cin >> n;
//     int len = n.size();

//     vector<long long> cnt(3, 0);
//     long long ps = 0, res = 0;
//     cnt[0] = 1;

//     for (int i = 0; i < len; ++i) {
//         ps = (ps + (n[i] - '0')) % 3;
//         res += cnt[ps];
//         cnt[ps]++;
//     }

//     cout << res << endl;
// }

// int main() {
//     ios_base :: sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     cin >> n;
//     solve();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
string s;

void solve() {
    s = " " + s;
    long long ps[s.size()] = {0}, sum = 0;
    int cnt[3] = {0};
    for (int i = 1; i < s.size(); ++i) {
        int digit = s[i] - '0';
        sum += digit;
        ps[i] = ps[i - 1] + digit;
        cnt[ps[i] % 3]++;
    }

    long long res = 0;
    for (int i = 1; i < s.size(); ++i) {
        res += cnt[(sum + ps[i - 1]) % 3];
        cnt[ps[i] % 3]--;
    }
    if (sum % 3 != 0)
        res--;

    cout << res << endl;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU3.inp", "r")) {
        freopen("CAU3.inp", "r", stdin);
        freopen("CAU3.out", "w", stdout);
    }

    cin >> s;
    solve();
    
    return 0;
}