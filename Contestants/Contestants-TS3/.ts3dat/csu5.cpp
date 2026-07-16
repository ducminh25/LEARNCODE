#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("cau5.INP","r",stdin);
    freopen("cau5.OUT","w",stdout);
    int n,k;cin>>n>>k;
    vector<long long>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<long long>l(n+1,1e9),r(n+2,1e9);
    for(int i=1;i<=n;i++)l[i]=min(l[i-1],a[i]);
    for(int i=n;i>0;i--)r[i]=min(r[i+1],a[i]);
    if(k==1){
      cout<<l[n];
    }
    if(k==2){
      long long ans=0;
      for(int i=1;i<n;i++)
        ans=max(ans,l[i]+r[i+1]);
      cout<<ans;
    }
    return 0;
}
