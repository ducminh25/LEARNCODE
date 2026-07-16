// int(c) + 5 % 28
#include <bits/stdc++.h>
using namespace std;

int n, f;
string s;
void encode(string s) {
    for (int i = 0; i < s.size(); ++i) {
        int x = int(s[i]) - 65;
        x = (x + 5) % 26;
        cout << char(x + 65);
    }
    cout << endl;
}

void decode(string s) {
    for (int i = 0; i < s.size(); ++i) {
        int x = int(s[i]);
        if (x < 70) x += 26;
        x = x - 5;
        cout << char(x);
    }
    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while (n--) {
        cin >> f >> s;
        if (f == 1) decode(s);
        if (f == 0) encode(s);
    }

    return 0;
}