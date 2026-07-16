#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int nt[N+5],pr[N+5]={0};
void sang(){
    fill(nt,nt+N+1,1);
    for(int i=2;i*i<=N;i++)
      if(nt[i]==1)
      for(int j=i;j<=N;j+=i)
        if(nt[j]==1)nt[j]=i;
}
int pt(int s){
    int res=s;
    int x=nt[s];
    while(res%x==0)res/=x;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("cau3.INP","r",stdin);
    freopen("cau3.OUT","w",stdout);
    int n,m;cin>>n>>m;
    sang();
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    for(int i=0;i<m;i++){
      int x=b[i];
      while(x!=1){
        if(pr[nt[x]]==0)pr[nt[x]]=1;
        x=pt(x);
      }
    }
    long long ans=0;
    for(int i=0;i<n;i++){
      int s=a[i];
      bool ok=1;
      while(s!=1)
        if(pr[nt[s]]){
          ok=0;break;
        }else s=pt(s);
      if(ok)ans++;
    }
    cout<<ans;
    return 0;
}
