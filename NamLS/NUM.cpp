#include <bits/stdc++.h>
using namespace std;

// Xóa đi đúng K chữ số của N để số còn lại lớn nhất có thể.
// Ex: 11686 1 --> 1686
string removeKdigits(string num, int k) {
    string result = "";
    stack<char> s;
    for (char c : num) {
        while (!s.empty() && k > 0 && s.top() < c) {
            s.pop();
            k--;
        }
        if (!s.empty() || c != '0') {
            s.push(c);
        }
    }
 
    while (!s.empty() && k--) {
        s.pop();
    }
 
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }
 
    return result.empty() ? "0" : result;
}
 
int main() {
    string N;
    int K;
    cin >> N >> K;
    cout << removeKdigits(N, K);
    return 0;
}