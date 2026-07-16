#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    if (fopen("TDX.INP", "r")) {
        freopen ("TDX.INP", "r", stdin);
        freopen ("TDX.OUT", "w", stdout);
    }

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        map<char, int> count;
        for (int i = 0; i < n; i++) {
            for (char c : arr[i]) {
                count[c]++;
            }
        }

        bool check = true;
        for (auto& it : count) {
            if (it.second % n != 0) {
                check = false;
                break;
            }
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
// full. need explanation