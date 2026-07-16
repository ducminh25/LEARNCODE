#include <bits/stdc++.h>
using namespace std;

void sol () {
    string necklace;
    cin >> necklace;
    int y = 0, r = 0, g = 0;
    for (int i = 0; i < necklace.size (); i++) {
        if (necklace [i] == 'Y') y++;
        if (necklace [i] == 'R') r++;
        if (necklace [i] == 'G') g++;
    }
    if (y == r && r == g) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main () {
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    int t;
    cin >> t;
    while (t--) sol ();

    return 0;
}