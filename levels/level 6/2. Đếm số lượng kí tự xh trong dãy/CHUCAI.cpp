#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);

    map<char, long long> frequency;

    for (char c : s) {
        if (isalpha(c) || isdigit(c)) {
            frequency[c]++;
        }
    }

    for (char a = 'A'; a <= 'Z'; a++) {
        if (frequency[a] > 0) {
            cout << a << " " << frequency[a] << endl;
        }
    }
    return 0;
}