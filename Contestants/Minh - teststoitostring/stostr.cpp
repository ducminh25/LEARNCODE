#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    if(fopen("stostr.inp", "r")) {
        freopen("STOSTR.INP", "r", stdin);
        freopen("stostr.OUT", "w", stdout);
    }
    int n;
    string a;
    cin >> n;
    cin.ignore();
    getline(cin, a);
    string s = to_string(n);
    int b = stoi(a);
    cout << s + 'a' << endl << b + 2 << endl;

    return 0;
}
