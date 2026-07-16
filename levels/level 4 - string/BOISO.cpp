// divisible by 11
#include <bits/stdc++.h>
using namespace std;
string s;

// int stringToInt(char s) {
//     int res = 0;
//     res = res * 10 + (s - '0');
//     return res;
// }

int check(char c1, char c2, char c3) {
    int a, b, c;
    if (c1 == '0') return 0;
    a = int(c1) - 48;
    b = int(c2) - 48;
    c = int(c3) - 48;
    if (a + c == b) return 1;
    else return 0;
}

void sol() {
    int res = 0;
    for (int i = 0; i <= s.size() - 3; i++) {
        res += check(s[i], s[i + 1], s[i + 2]);
    }
    cout << res << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    getline(cin, s);
    sol();

    return 0;
}