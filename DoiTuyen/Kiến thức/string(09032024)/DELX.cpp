#include <iostream>
#include <string>
using namespace std;

int main() {
    char x;
    string s;
    
    cin >> x;
    cin.ignore();
    getline(cin, s);
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != x) {
            cout << s[i];
        }
    }
    
    return 0;
}