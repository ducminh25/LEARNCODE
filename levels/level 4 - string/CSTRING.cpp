#include <bits/stdc++.h>
using namespace std;
string s, ss = "";
int n, c;


string f(int n, string s) {
    string s1 = "";
    for (int i = n; i <= s.length() - 1; ++i) {
        s1 += s[i];
    }
    s1 += s;

    return s1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> c;
    cin >> s;
    for (int i = 1; i <= c; ++i) {
        s = f(n, s);
    }
    cout << s;
    
    return 0;
}