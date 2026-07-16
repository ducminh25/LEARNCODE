#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXA = 5e6 + 5;
int n, a[MAXN];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("GCD.INP", "r")) {
        freopen("GCD.INP", "r", stdin);
        freopen("GCD.OUT", "w", stdout);
    }

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int x = a[0];
    for (int i = 1; i < n; ++i)
        x = gcd(x, a[i]);

    vector<int> gcds;
    for (int i = 0; i < n; ++i) {
        int newgcd = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (newgcd == 0)
                    newgcd = a[j];
                else
                    newgcd = gcd(newgcd, a[j]);
            }
        }
        if (newgcd > x) {
            gcds.push_back(newgcd);
        }
    }

    if (gcds.empty()) {
        cout << -1 << endl;
        return 0;
    } 
    else {
        int max_gcd = *max_element(gcds.begin(), gcds.end());
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (gcd(a[i], max_gcd) == x) count++;
        }
        cout << count << endl;
    }

    return 0;
}
