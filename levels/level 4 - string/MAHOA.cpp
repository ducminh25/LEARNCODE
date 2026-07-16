#include <bits/stdc++.h>
using namespace std;
string s;

void upper(char c) {
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    cout << c;
}

void sol() {
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] >= '0' && s[i] <= '9') {
            cout << char(s[i] + 48);
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            char c = toupper(s[i]);
            cout << c;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    getline(cin, s);
    sol();
    return 0;
}