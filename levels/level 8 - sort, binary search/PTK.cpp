#include <bits/stdc++.h>
using namespace std;
int a[10000001], cnt[10000001];
int n, m, k;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("ptk.inp", "r")) {
        freopen("ptk.inp", "r", stdin);
        freopen("ptk.out", "w", stdout);
    }

    cin >> n >> m >> k;
    a[1] = a[2] = 1;
    for(int i = 3; i <= n; ++i) {
        a[i] = (a[i - 1] + a[i - 2]) % m;
    }

    if(m > 1000000) {
        sort(a + 1, a + 1 + n);
        cout << a[k] << endl;
    }
    else {
        long long s = 0, res = 0;
        for(int i = 1; i <= n; ++i) 
            cnt[a[i]]++;
        for(int i = 0; i <= 1000000; ++i) {
            s += cnt[i];
            if(s >= k) {
                res = i;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}