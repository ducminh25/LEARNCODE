#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long , long long>;
const int mod = 1e9 + 7;
const int inf = 1e9;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());


#define hlong "cau3"

inline void Freopen() {
    if (fopen(hlong ".inp" , "r")){
        freopen(hlong ".inp" , "r" , stdin);
        freopen(hlong ".out" , "w" , stdout);
    }
}

const int N = 1e6 + 5;
int spf[N];
void diva() {
    for(int i = 2 ; i <= N ; i++) spf[i] = i;
    for(int i = 2 ; i * i <= N ; i++) {
        for(int j = i * i ; j <= N ; j += i) {
            if(spf[j] == j) spf[j] = i;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Freopen();

    int n , m;
    cin >> n >> m;
    diva();

    vector<int> a(n) , b(m);
    for(auto &x : a) {
        cin >> x;
        x = spf[x];
    }
    for(auto &x : b) {
        cin >> x;
        x = spf[x];
    }

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    long long ans = 0;
    for(int i = 0 ; i < n ; i++) {
        auto pos = upper_bound(b.begin() , b.end() , a[i]);
        auto it = lower_bound(b.begin() , b.end() , a[i]);
        if(pos == b.end() && *it != a[i]){
            ans++;
        }
    }

    cout << ans;



    return 0;
}

