// Kiểm tra số đối xứng
#include <bits/stdc++.h>
using namespace std;

string toString(int n) {
    string res = "";
    while (n > 0) {
        res += n % 10 + '0';
        n /= 10;
    }

    return res;
}

bool checkPalin(int n) {
    string s = toString(n);
    for (int i = 0; i <= s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) return 0;
    }

    return 1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    if (checkPalin(n)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}