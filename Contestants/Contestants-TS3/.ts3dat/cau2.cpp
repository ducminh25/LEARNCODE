#include <bits/stdc++.h>
using namespace std;
vector<int>a,pre,h;
int n,k;
long long res(int x,int l){
      long long sum=pre[n]-pre[x-1];
      long long cnt=n-x+1;
      long long res=1ll*l*(x-1)-1ll*pre[x-1];
      res+=1ll*cnt*h[n]-1ll*sum;
      return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("cau2.INP","r",stdin);
    freopen("cau2.OUT","w",stdout);
    cin>>n>>k;
    a.resize(n+1);pre.resize(n+1,0);
    h.resize(n+1,0);
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        h[i]=max(h[i-1],a[i]);
    }
    if(k==0){
      long long ans=1ll*h[n]*n-1ll*pre[n];
      cout<<ans;
    }else if(k==-1){
      int it=upper_bound(h.begin(),h.end(),h[1])-h.begin();
      cout<<res(it,h[1]);
    }else{
      long long ans=LLONG_MAX;
      int i=1;
      while(i<n){
        int it=upper_bound(h.begin(),h.end(),h[i])-h.begin();
        ans=min(res(it,h[i]),ans);
        i=it;
      }
      cout<<ans;
    }
    return 0;
}
