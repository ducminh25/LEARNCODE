#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000;
int lp[maxn + 1];

void sieve(){
    for(int i = 2; i <= maxn; i++){
        if(lp[i] == 0){
            for(int j = i; j <= maxn; j += i){
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	freopen("cau3.inp", "r", stdin);
    freopen("cau3.out", "w", stdout);

    sieve();

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    unordered_set<int> bad; 

    for(int x : b){
        while(x > 1){
            int p = lp[x];
            bad.insert(p);
            while(x % p == 0) x /= p;
        }
    }

    long long ans = 0;

    for(int x : a){
        bool ok = true;
        int y = x;
        while(y > 1){
            int p = lp[y];
            if(bad.count(p)){
                ok = false;
                break;
            }
            while(y % p == 0) y /= p;
        }
        if(ok) ans++;
    }

    cout << ans;
    return 0;
}
