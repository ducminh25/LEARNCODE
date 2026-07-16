#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    getline(cin, s);
    for(int i = 0; i < s.length(); i += 2) {
        cout << s[i];
    }
    cout << endl;
    
    return 0;
}