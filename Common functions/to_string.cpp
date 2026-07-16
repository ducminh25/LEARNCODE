#include <bits/stdc++.h>
using namespace std;

long long n;
string toString (long long a) {
    string res = "";
    while (a > 0) {
        res = char (a % 10 + '0') + res;
        a /= 10;
    }
    return res;
}

int main() {
    cin >> n;
    string ans = toString(n);
    cout << typeid(ans).name() << endl;

    return 0;
}