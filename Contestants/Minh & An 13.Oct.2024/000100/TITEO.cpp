#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie (0); cout.tie (0);

    if (fopen ("TITEO.INP", "r")) {
        freopen ("TITEO.INP", "r", stdin);
        freopen ("TITEO.OUT", "w", stdout);
    }
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
    
        long long ans = (k - 1) * n + (n - 1);
        cout << (long long)(ans / (n - 1)) << endl;
    }

    return 0;
}
