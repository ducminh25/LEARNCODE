#include <bits/stdc++.h>
using namespace std;
string s, p;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    getline (cin, s);
    getline (cin, p);
    int l = s.size();
    int cnt = 0;
    for (int i = 0; i < l; ++i) {
        if(s[i] == p[l - i - 1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}