#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    if (fopen("TOTAL.inp", "r")) {
        freopen("TOTAL.inp", "r", stdin);
        freopen("TOTAL.out", "w", stdout);
    }

    int n;
    cin >> n;
    char s[n + 5];

    int sum = 0;
    char prev = '?';

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        char c = s[i];
        if (c == '?') {
            if (prev == 'a')
                c = 'a';
            else if (prev == 'b')
                c = 'b';
            else
                c = 'a'; // hoặc 'b'
        }

        if (prev != '?') {
            if (prev == 'a' && c == 'b')
                sum += 1;
            else if (prev == 'b' && c == 'a')
                sum -= 1;
        }
        prev = c;
    }

    cout << sum << endl;
    return 0;
}
