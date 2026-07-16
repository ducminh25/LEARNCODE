#include <bits/stdc++.h>
using namespace std;
string name;

void upper(char c) {
    if (c >= 'a' && c <= 'z') 
        c = c - 32;
    cout << c;
}

void upper1st (string s) {
    upper(s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if(s[i - 1] == ' ') {
            upper(s[i]);
        }
        else cout << s[i];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    getline(cin, name);
    for(int i = 0; i < name.size(); ++i) {
        char a = name[i];
        upper(a);
    }
    cout << endl;
    upper1st(name);

    return 0;
}