#include <bits/stdc++.h>
using namespace std;
bool isUnique(const string &S, int length) {
    for (int i = 0; i <= S.size() - length; ++i) {
        for (int j = i + 1; j <= S.size() - length; ++j) {
            if (S.substr(i, length) == S.substr(j, length)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    string S;
    cin >> n >> S;

    int l = 1;
    for (; l <= n; ++l) {
        if (isUnique(S, l)) {
            break;
        }
    }

    cout << l << endl;
    return 0;
}