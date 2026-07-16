#include <bits/stdc++.h>
using namespace std;

int n;

int main () {
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            if (i == 0 || s[i] != s[i - 1])
                cout << s[i];
        cout << endl;
    }

    return 0;
}