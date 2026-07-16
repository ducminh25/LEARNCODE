#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI2.inp", "r")) {
        freopen("BAI2.inp", "r", stdin);
        freopen("BAI2.out", "w", stdout);
    }

    int N;
    cin >> N;
    map<int, int> cnt;

    for (int i = 0; i < N; ++i) {
        int btype;
        cin >> btype;
        cnt[btype]++;
    }

    int maxcnt = 0;
    int maxfreq = INT_MAX;

    for (auto& pair : cnt) {
        if (pair.second > maxcnt) {
            maxcnt = pair.second;
            maxfreq = pair.first;
        } else if (pair.second == maxcnt && pair.first < maxfreq) {
            maxfreq = pair.first;
        }
    }
    cout << maxfreq << " " << maxcnt << endl;

    return 0;
}