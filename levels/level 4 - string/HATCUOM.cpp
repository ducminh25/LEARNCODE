#include <bits/stdc++.h>
using namespace std;
int n;
char s[260];
string ansX = "", ansT = "", ans = "";

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if(s[i] == 'X') ansX += s[i];
        else ansT += s[i];
    }
    ans = ansX + ansT;
    cout << ans << endl;

    return 0;
}