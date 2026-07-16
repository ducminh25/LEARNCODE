#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("CAU5.INP","r",stdin);
    freopen("CAU5.OUT","w",stdout);
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    vector<int> pre(n+1,INT_MAX);
    vector<int> suf(n+2,INT_MAX);
    int amin=INT_MAX;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        amin=min(amin,a[i]);
        pre[i]=min(pre[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
        suf[i]=min(suf[i+1],a[i]);
    if(k<=2){
        if(k==1)
            cout << amin;
        else{
            int ans=0;
            for(int i=1;i<n;i++)
                ans=max(ans,pre[i]+suf[i+1]);
            cout << ans;
        }
    }
    return 0;
}
