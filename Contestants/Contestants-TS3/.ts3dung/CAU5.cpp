#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n,k;
long long pre[N + 10],suf[N + 10],a[N + 10],ans = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU5.INP","r",stdin);
    freopen("CAU5.OUT","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    pre[1] = a[1];
    for(int i = 2; i <= n; i++) pre[i] = min(pre[i - 1],a[i]);
    suf[n] = a[n];
    for(int i = n - 1; i > 0; i--) suf[i] = min(suf[i + 1],a[i]);
    for(int i = 1; i <= n; i++){
        long long res = pre[i] + suf[i + 1];
        ans = max(ans,res);
    }
    cout << ans;
    return 0;
}
