#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long , long long>;
const int mod = 1e9 + 7;
const int inf = 1e9;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());


#define hlong "cau1"

inline void Freopen() {
    if (fopen(hlong ".inp" , "r")){
        freopen(hlong ".inp" , "r" , stdin);
        freopen(hlong ".out" , "w" , stdout);
    }
}

const int MAXN = 4e4 + 5;
bitset<MAXN> isPrime;
vector<int> v;

void sieve() {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2 ; i * i <= MAXN ; i++) {
        if(isPrime[i]) {
            for(int j = i * i ; j <= MAXN ; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    for(int i = 2 ; i <= MAXN ; i++) {
        if(isPrime[i]) v.push_back(i);
    }
}

bool p(long long x) {
    if(x < 2) return false;
    for(int i = 2 ; i * i <= x ; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Freopen();

    long long l , r;
    cin >> l >> r;
    sieve();

    long long ans = 0;


    for(auto it : v) {
        for(int i = l ; i <= r ; i++) {
            long long tmp = 1LL * i * i + it;
            if(tmp > 1LL * r * r) break;
            if(int(sqrt(tmp)) == sqrt(tmp)) ans++;
        }
    }

    cout << ans;




    return 0;
}

