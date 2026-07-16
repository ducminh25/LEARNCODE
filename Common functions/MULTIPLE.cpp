#include <bits/stdc++.h>
using namespace std;

// Hàm nhân hai số nguyên lớn ở dạng string
string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0) return "0";

    vector<int> res(n1 + n2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    
    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        
        for (int j = n2 - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + res[i_n1 + i_n2] + carry;
            carry = sum / 10;
            res[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0)
            res[i_n1 + i_n2] += carry;
        i_n1++;
    }

    int i = res.size() - 1;
    while (i >= 0 && res[i] == 0)
        i--;

    if (i == -1)
        return "0";

    string s = "";
    while (i >= 0)
        s += to_string(res[i--]);

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    bool negative = (a[0] == '-') ^ (b[0] == '-');
    if (a[0] == '-') a = a.substr(1);
    if (b[0] == '-') b = b.substr(1);

    string res = multiply(a, b);
    
    if (negative && res != "0")
        cout << "-";
    cout << res << endl;

    return 0;
}
/*
56235874122 95632541282
--> 5377979553501520504404
*/