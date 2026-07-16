#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

ll n, a, v, d = INT_MIN;
map<ll,ll> k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DEMHANG.INP", "r", stdin);
    freopen("DEMHANG.OUT", "w", stdout);
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a;
        k[a]++;
    }
    for(auto x : k){
        if(x.second > d){
            v = x.first;
            d = x.second;
        }
    }
    cout << v << ' ' << d;
    return 0;
}
