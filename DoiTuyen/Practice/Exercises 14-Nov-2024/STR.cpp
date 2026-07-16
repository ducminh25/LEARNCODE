#include <bits/stdc++.h>
using namespace std;
string s;

void cnt() {
    int cnt = 0;
    int freq[125] = {0};
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] >= 'a' && s[i] <= 'z' && freq[s[i]] == 0) {
            cnt++;
            freq[s[i]]++;
        }
    }
    cout << cnt << endl;
}

// Xoá những số 0 vô nghĩa
string delZero(string str) {
    int i = 0;
    while (i < str.size() && str[i] == '0')
        ++i;
    if (i == str.size())
        return "0";
    return str.substr(i);
}

void maxint() {
    string res = "";
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] >= '0' && s[i] <= '9') {
            string num = "";
            while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                num += s[i++];
            }
            --i;
            
            num = delZero(num);
            if(num.size() > res.size() || 
               (num.size() == res.size() && num > res))
                res = num;
        }
    }
    if(res.empty()) cout << "0" << endl;
    else cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("STR.inp", "r")) {
        freopen("STR.inp", "r", stdin);
        freopen("STR.out", "w", stdout);
    }

    getline(cin, s);
    cnt();
    maxint();

    return 0;
}