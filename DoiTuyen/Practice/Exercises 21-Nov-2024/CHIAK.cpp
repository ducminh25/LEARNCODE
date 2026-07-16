#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
long long n, k, a[MAXN], ps[MAXN];
map<long long, long long> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    if(fopen("CHIAK.inp", "r")) {
        freopen("CHIAK.inp", "r", stdin);
        freopen("CHIAK.out", "w", stdout);
    }
    cin >> n >> k;
    ps[0] = 0;
    cnt[0] = 1;
    long long res = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = (ps[i-1] + a[i] % k + k) % k;
        res += cnt[ps[i]];
        cnt[ps[i]]++;
    }
    cout << res << endl;
    
    return 0;
}