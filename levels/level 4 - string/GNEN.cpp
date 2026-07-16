#include <bits/stdc++.h>
using namespace std;
string s;

int stringToInt(string num) {
    int res = 0;
    for (int i = 0; i < num.size(); ++i) {
        res = res * 10 + (num[i] - '0');
    }
    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> s;
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            t += s[i];
        }
        else {
            if (t != "") {
                int x = stringToInt(t);
                for (int j = 1; j <= x; j++) {
                    cout << s[i];
                }
                t = "";
            }
            else cout << s[i];
        }
    }
    return 0;
}