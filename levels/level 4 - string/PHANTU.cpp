#include <bits/stdc++.h>
using namespace std;
string a, b;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    getline(cin, a);
    getline(cin, b);

    char lastA = a[a.size() - 1];
    char firstB = b[0];
    if (lastA == firstB) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    int count = 0;
    for (char c : a) {
        if(c == firstB) count++;
    }
    cout << count << endl;

    for (int i = a.size() - 1; i >= 0; --i) {
        cout << a[i];
    }
    cout << endl;

    for (int i = 0; i <= b.size() - 1; ++i)
        if(b[i] != ' ') cout << b[i];
    cout << endl;

    string s = "";
    for (char c : a) {
        if ('0' <= c && c <= '9') s += c;
    }
    cout << s << endl;

    //check Palindrome
    bool ok = true;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}