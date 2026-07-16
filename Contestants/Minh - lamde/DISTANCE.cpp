#include <bits/stdc++.h>
using namespace std;
string x, y;
long long s = 0;

int stringToInt (string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res = res * 10 + (s[i] - '0');
    }

    return res;
}

int minn (int x, int y, int z) {
    int m = x;
    if (y < m) m = y;
    if (z < m) m = z;

    return m;
}

int d (char a, char b) {
    int x, y, c1, c2, c3, res;
    x = int(a) - 48;
    y = int(b) - 48;
    c1 = abs(x - y);
    c2 = x + 10 - y;
    c3 = y + 10 - x;
    res = minn(c1, c2, c3);

    return res;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("DISTANCE.inp", "r")) {
        freopen("DISTANCE.inp", "r", stdin);
        freopen("DISTANCE.out", "w", stdout);
    }
    
    cin >> x >> y;
    for (int i = 0; i < x.size(); ++i) {
        s += d(x[i], y[i]);
    }

    cout << s << endl;
    return 0;
}