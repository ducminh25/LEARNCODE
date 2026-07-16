#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    getline(cin, s);
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) 
        if (s[i] == '9') cnt++;
    cout << cnt << endl;

    return 0;
}