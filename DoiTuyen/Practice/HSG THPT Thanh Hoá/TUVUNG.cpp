#include <bits/stdc++.h>
#define vi vector<int>
#define endl '\n'
using namespace std;
string s;
int n;

bool isvowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void input() {  
    cin >> s;
    n = s.size();
}

void solve() {
    long long cnt = 0;
    vi vowelcnt(n + 1, 0);
    vi concnt(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        vowelcnt[i] = vowelcnt[i - 1] + isvowel(s[i - 1]);
        concnt[i] = concnt[i - 1] + !isvowel(s[i - 1]);
    }

    for (int i = 0; i < n; ++i) {
        if (isvowel(s[i])) cnt += concnt[n] - concnt[i + 1];
        else cnt += vowelcnt[n] - vowelcnt[i + 1];
    }

    cout << cnt << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU4.inp", "r")) {
        freopen("CAU4.inp", "r", stdin);
        freopen("CAU4.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}