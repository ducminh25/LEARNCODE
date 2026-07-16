#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define mod 1000000007LL

ll n, j, ans = INT_MIN, a[1000005], track[1000005];
pair<ll,ll> dp[1000005];
vector<ll> res;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("PHITIEU.INP", "r", stdin);
    freopen("PHITIEU.OUT", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    dp[1].first = a[1];
    dp[2].first = a[2]+a[1];
    dp[2].second = 1;
    for(ll i = 3; i <= n; i++){
        dp[i].first = dp[i-3].first+a[i-1]+a[i];
        dp[i].second = i-1;
        if(dp[i-3].second != i-4 && a[i-2] > a[i-1]){
            dp[i].first = dp[i-3].first+a[i-2]+a[i];
            dp[i].second = i-2;
        }
        track[i] = i-3;
    }
    for(ll i = 1; i <= n; i++){
        //cout << dp[i] << ' ';
        if(dp[i].first > ans){
            ans = dp[i].first;
            j = i;
        }
    }
    //cout << '\n';
    while(j > 0){
        res.push_back(j);
        if(dp[j].second != 0) res.push_back(dp[j].second);
        j = track[j];
    }
    cout << res.size() << ' ' << ans << '\n';
    for(auto x : res) cout << x << '\n';
    return 0;
}
