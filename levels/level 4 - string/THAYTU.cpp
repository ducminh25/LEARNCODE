#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
    getline(cin, s);
    
    while (s.find("anh") != -1) {
        int x = s.find("anh");
        s.replace(x, 3, "em");
    }
    cout << s << endl;

    return 0;
}