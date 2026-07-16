#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
long long a[MAXN], ps[MAXN];
unordered_map<long long, int> cnts;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI5.inp", "r")) {
        freopen("BAI5.inp", "r", stdin);
        freopen("BAI5.out", "w", stdout);
    }
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    
    long long allsum = ps[n];
    if (allsum % 4 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    long long qrts = allsum / 4;
    long long res = 0;
    
    for (int j = 2; j < n - 1; j++) {
        if (ps[j-1] == qrts) {
            cnts[ps[j-1]]++;
        }
        if (ps[n] - ps[j] == qrts) {
            res += cnts[2 * qrts];
        }
    }
    cout << res << endl;
    
    return 0;
}