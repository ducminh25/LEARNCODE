#include <bits/stdc++.h>
using namespace std;
int n, m;
string t, s;

bool check(const vector<int>& freqs, const vector<int>& freqt, int stars) {
    int extneed = 0;
    for (int i = 0; i < 26; ++i) {
        if (freqs[i] < freqt[i]) {
            extneed += freqt[i] - freqs[i];
        }
    }
    return extneed <= stars;
}

void input() {
    cin >> n >> m >> t >> s;
}

void solve() {
    vector<int> freqt(26, 0);
    for (char c : t) {
        freqt[c - 'a']++;
    }

    vector<int> freqs(26, 0);
    int stars = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*')
            stars++;
        else
            freqs[s[i] - 'a']++;
    }

    int cnt = 0;
    if (check(freqs, freqt, stars))
        cnt++;

    for (int i = n; i < m; ++i) {
        if (s[i - n] == '*')
            stars--;
        else
            freqs[s[i - n] - 'a']--;

        if (s[i] == '*')
            stars++;
        else
            freqs[s[i] - 'a']++;

        if (check(freqs, freqt, stars))
            cnt++;
    }

    cout << cnt << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("CAU3.inp", "r")) {
        freopen("CAU3.inp", "r", stdin);
        freopen("CAU3.out", "w", stdout);
    }

    input();
    solve();
    
    return 0;
}