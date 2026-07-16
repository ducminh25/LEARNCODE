// minimum string
#include <bits/stdc++.h>
using namespace std;
int a, b, k;

string toString(int n) {
    string res = "";
    while (n > 0) {
        res = char(n % 10 + '0') + res;
        n /= 10;
    }
    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> a >> b >> k;
    string minn = "a";

    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            if (toString(i) < minn) minn = toString(i);
        }
    }
    cout << minn;

    return 0;
}