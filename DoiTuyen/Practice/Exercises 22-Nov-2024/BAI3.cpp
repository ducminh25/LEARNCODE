#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI3.inp", "r")) {
        freopen("BAI3.INP", "r", stdin);
        freopen("BAI3.OUT", "w", stdout);
    }
    
    int N;
    string s;
    cin >> N >> s;

    int res = 0;
    for (int i = 0; i < N - 1; i++) {
        if (s[i] == '?' || s[i+1] == '?') {
            res++;
        } else if (s[i] == 'a' && s[i+1] == 'b') {
            res++;
        } else if (s[i] == 'b' && s[i+1] == 'a') {
            res--;
        }
    }

    cout << res << endl;

    return 0;
}