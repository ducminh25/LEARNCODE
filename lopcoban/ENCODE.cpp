#include <bits/stdc++.h>
using namespace std;

int tinhSM(string s) {
    int sm = 0;
    for (int i = 0; i <= 9; i++) {
        sm = sm + (i + 1) * (int(s[i]) - 48);
    }
    return sm;
}

int main() {
    int n, vt;
    string s;
    cin >> s;
    int k = 0;
    n = s.size();
    for (int i = 0; i <= n - 1; i++)
        if (s[i] == '?') vt = i;
    for (int j = 48; j <= 57; j++) {
        s[vt] = char(j);
        k = tinhSM(s);
        if (k % 11 == 0) cout << char(j);
    }
    return 0;
}
