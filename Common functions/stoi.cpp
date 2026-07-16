#include <bits/stdc++.h>
using namespace std;
string num;

int stringToInt (string number) {
    int res = 0;
    for (int i = 0; i < number.size(); ++i) {
        res = res * 10 + (number[i] - '0');
    }
    return res;
}

int main() {
    cin >> num;
    int ans = stringToInt(num);
    cout << ans * 2 << endl;

    return 0;
}