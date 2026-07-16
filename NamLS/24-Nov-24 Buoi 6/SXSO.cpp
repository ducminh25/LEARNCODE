#include <bits/stdc++.h>
using namespace std;
int n;
bool ok = false;

string toString (int a) {
    string res = "";
    while (a > 0) {
        res += char (a % 10 + '0');
        a /= 10;
    }

    return res;
}

void input() {
    cin >> n;
}

void solve() {
    string s = toString(n);
    sort(s.begin(), s.end(), greater<char>());

    if (s.back() != '0' && s.back() != '5') {
        for (int i = 0; i < 4; ++i) {
            if (s[i] == '0' || s[i] == '5') {
                swap(s[i], s.back());
                ok = true;
                break;
            }
        }
    } else ok = true;

    if (ok) cout << s << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("SXSO.inp", "r")) {
        freopen("SXSO.inp", "r", stdin);
        freopen("SXSO.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
Cho một số nguyên dương N có 4 chữ số.

Yêu cầu: Hãy sắp xếp lại các chữ số của N để được số lớn nhất mà chia hết cho 5, nếu không tìm được số chia hết cho 5 thì ghi ra -1.
*/