#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin.ignore();
    while(n--) {
        string s;
        getline(cin, s);
        if (s.size() > 10) {
            string temp = s[0] + to_string(s.size() - 2) + s[s.size() - 1];
            cout << temp << endl;
        }
        else cout << s << endl;
    }

    return 0;
}