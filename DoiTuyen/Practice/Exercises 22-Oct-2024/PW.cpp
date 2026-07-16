#include <bits/stdc++.h>
using namespace std;

int countSafePasswords(string S) {
    int n = S.length();
    int count = 0;
    for (int i = 0; i < n; i++) {
        int upper = 0, lower = 0, digit = 0;
        for (int j = i; j < n && j < i + 6; j++) {
            if (isupper(S[j])) upper++;
            else if (islower(S[j])) lower++;
            else if (isdigit(S[j])) digit++;
            if (j >= i + 5 && upper > 0 && lower > 0 && digit > 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI4.INP", "r")) {
        freopen("BAI4.INP", "r", stdin);
        freopen("BAI4.OUT", "w", stdout);
    }
    
    string s;
    getline(cin, s);
    cout << countSafePasswords(s) << endl;
    return 0;
}
