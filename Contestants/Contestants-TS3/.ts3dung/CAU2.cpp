#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long a[N + 10],n,k,ans = 0,prefix[N + 10],suf_fix[N + 10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(k == 0){
        long long maxn = *max_element(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) ans += (maxn - a[i]);
        cout << ans;
    }
    else if(k == -1){
        long long x = a[1],pos = -1;
        for(int i = 1; i <= n; i++){
            if(a[i] > x){
                pos = i;
                break;
            }
        }
        long long maxn = 0;
        for(int i = pos; i <= n; i++) maxn = max(maxn, a[i]);
        for(int i = 1; i <= n; i++){
            if(i < pos) ans += x - a[i];
            else ans += maxn - a[i];
        }
        cout << ans;
    }
    else{
        ans = 1e18;
        prefix[0] = 0;
        suf_fix[n + 1] = 0;
        for(int i = 1; i <= n; i++) prefix[i] = max(prefix[i - 1], a[i]);
        for(int i = n; i > 0; i--) suf_fix[i] = max(suf_fix[i + 1], a[i]);
        for(int i = 1; i <= n; i++){
            long long x = 0,maxn = 0,res = 0;
            if(prefix[i] != prefix[i - 1]) x = prefix[i];
            else continue;
            if(prefix[i] < suf_fix[i + 1]) maxn = suf_fix[i + 1];
            else maxn = x;
            bool ok = false;
            for(int j = 1; j <= n; j++){
                if(x >= a[j] && ok == false) res += x - a[j];
                else{
                    res += maxn - a[j];
                    ok = true;
                }
            }
            ans = min(ans , res);
        }
        cout << ans;
    }
    return 0;
}
