#include <iostream>
#include <string>
using namespace std;

string nenXau(string s) {
    string result = "";
    int count = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            result += to_string(count) + s[i - 1];
            count = 1;
        }
    }
    result += to_string(count) + s[s.length() - 1];
    return result;
}

int main() {
    string s;
    cin >> s;

    string result = nenXau(s);
    cout << result;

    return 0;
}
