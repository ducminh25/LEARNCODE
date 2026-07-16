#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    int n = s.length();
    vector<int> freq(10, 0);
    for (char c : s) {
        freq[c - '0']++;
    }
    
    for (int d = 0; d <= 9; d++) {
        int cnt = freq[d];
        if (cnt == n - 1) return true;
    }
    
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("LAIXOASO.inp", "r")) {
        freopen("LAIXOASO.inp", "r", stdin);
        freopen("LAIXOASO.out", "w", stdout);
    }

    int t;
    cin >> t;

    while (t--) {
        string N;
        cin >> N;
        
        if (check(N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}