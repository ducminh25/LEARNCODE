#include <bits/stdc++.h>
using namespace std;
string s;
int n,k;
map<string,int> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);
    cin >> n >> k >> s;
    if(n <= 10000){
        for(int i = 0; i < n; i++){
            string ss = "";
            for(int j = i; j < n; j++){
                ss += s[j];
                mp[ss]++;
            }
        }
        int ans = -1;
        for(auto x : mp){
            if(x.second >= k){
                int res = x.first.size();
                ans = max(ans,res);
            }
        }
        cout << ans;
    }
    else cout << -1;
    return 0;
}
