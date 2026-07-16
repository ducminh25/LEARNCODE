#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = (char)('0' + n % 2) + binary;
        n /= 2;
    }
    return binary;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string binaryN = decimalToBinary(n);
        int count = 0;
        for (int i = 0; i < binaryN.size(); ++i) {
            if (binaryN[i] == '1') {
                count++;
            }
        }
        if (count % 2 == 0) cout << "even" << endl;
        else cout << "odd" << endl;
    }

    return 0;
}