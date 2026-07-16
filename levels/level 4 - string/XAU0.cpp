#include <bits/stdc++.h>
using namespace std;

string a, b;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    getline(cin, a);
    getline(cin, b);

    string c = a + ' ' + b;
    cout << c;
    return 0;
}