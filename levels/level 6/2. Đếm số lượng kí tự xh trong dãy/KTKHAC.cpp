#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    cin.ignore();
    int results[T];

    for (int i = 0; i < T; ++i) {
        string S;
        getline(cin, S);

        int count[26] = {0};
        int differentChars = 0;

        for (char c : S) {
            if ('A' <= c && c <= 'Z') {
                if (count[c - 'A'] == 0) {
                    differentChars++;
                }
                count[c - 'A']++;
            }
        }

        results[i] = differentChars;
    }

    for (int i = 0; i < T; ++i) {
        cout << results[i] << endl;
    }

    return 0;
}