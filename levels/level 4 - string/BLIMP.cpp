#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    bool found = false;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (s.find("FBI") != string::npos) {
            found = true;
            cout << i << " ";
        }
    }

    if (!found) cout << "GO";
    return 0;
}