#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    bool presence[n + 1] = {false};
    int val;
    for(int i = 0; i < n; i++) {
        cin >> val;
        if(val >= 1 && val <= n) {
            presence[val] = true;
        }
    }

    int changes = 0;
    for(int i = 1; i <= n; i++) {
        if (!presence[i]) {
            changes++;
        }
    }
    
    cout << changes << endl;
    
    return 0;
}