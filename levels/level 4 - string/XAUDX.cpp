#include <bits/stdc++.h>
using namespace std;
vector<int> index;
int n;

bool checkPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    index.push_back(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string input;
        cin >> input;
        if (checkPalindrome(input)) {
            index.push_back(i);
        }
    }
    cout << index.size() - 1 << endl;
    for (int i = 1; i < index.size(); ++i) {
        cout << index[i] << " ";
        if(i % 20 == 0) cout << endl;
    }

    return 0;
}