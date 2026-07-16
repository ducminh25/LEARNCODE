#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long , long long>;
const int mod = 1e9 + 7;
const int inf = 1e9;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());


#define hlong "cau2"

inline void Freopen() {
    if (fopen(hlong ".inp" , "r")){
        freopen(hlong ".inp" , "r" , stdin);
        freopen(hlong ".out" , "w" , stdout);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Freopen();

    int n , k;
    cin >> n >> k;

    vector<int> a(n) , f(n + 1 , 0);
    long long r = -1;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
        r = max(r , 1LL * a[i]);
        f[i + 1] = f[i] + a[i];
    }
    long long ans = 0;

    if(k == 0) {
        for(auto it : a) {
            ans += (r - it);
        }
    }
    else if(k == -1) {
        int x = a[0];
        for(int i = 1 ; i < n ; i++) {
            if(x >= a[i]) ans += (x - a[i]);
            else if(x < a[i]){
                x = r;
                ans += (x - a[i]);
            }
        }
    }
    else if(k == 1) {
        ans = INT_MAX;
        int maxa = INT_MAX , res = -1;
        long long dif = 0;
        for(int i = 0 ; i < n ; i++) {
            res = max(res , a[i]);
            if(res < maxa) {
                dif = a[i] * (i + 1) - f[i + 1] + r * (n - i - 1) - (f[n] - f[i]);
                ans = min(ans , dif);
                maxa = res;
            }
            else break;
        }
    }

    cout << ans;

    return 0;
}

