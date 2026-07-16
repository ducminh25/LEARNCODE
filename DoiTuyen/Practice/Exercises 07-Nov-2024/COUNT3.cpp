#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
unordered_map<int, int> mp;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("COUNT3.inp", "r")) {
        freopen("COUNT3.inp", "r", stdin);
        freopen("COUNT3.out", "w", stdout);
    }
    
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    
    int ps = 0;
    mp[0] = 1;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) ps++;
        else ps--;

        if (mp.find(ps) != mp.end())
            res += mp[ps];
        mp[ps]++;
    }

    cout << res << endl;
    return 0;
}