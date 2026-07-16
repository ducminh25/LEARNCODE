#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define mod 25071987LL

ll n, j = 1, ans, k = INT_MIN, dmax = INT_MIN, a[100005];
vector<pair<ll,ll>> res;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DUBAO.INP", "r", stdin);
    freopen("DUBAO.OUT", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    res.push_back({1, 1});
    for(ll i = 1; i <= n+1; i++){
        if(a[i] >= 0){
            if(i-1 >= j) res.push_back({j, i-1});
            dmax = max(dmax, i-j);
            j = i+1;
        }
    }
    for(ll i = 1; i < res.size(); i++){
        if(res[i].second-res[i].first+1 == dmax) k = max(k, min(res[i].first-res[i-1].second, 3*(res[i].second-res[i].first+1)));
        ans += min(res[i].first-res[i-1].second, 2*(res[i].second-res[i].first+1));
    }
    for(ll i = 1; i < res.size(); i++){
        if(min(res[i].first-res[i-1].second, 3*(res[i].second-res[i].first+1)) == k){
            ans = ans-min(res[i].first-res[i-1].second, 2*(res[i].second-res[i].first+1))+k;
            break;
        }
    }
    cout << ans;
    return 0;
}
