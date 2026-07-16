#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int nt[N+5];
int l,r;
void sang(){
    fill(nt,nt+N+1,1);
    nt[0]=nt[1]=0;
    for(int i=2;i*i<=N;i++)
      if(nt[i]){
      for(int j=i*i;j<=N;j+=i)
        nt[j]=0;
      }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("cau1.INP","r",stdin);
    freopen("cau1.OUT","w",stdout);
    cin>>l>>r;
    sang();
    long long ans=0;
    for(int i=l;i<r;i++){
      if(nt[i+i+1])ans++;
    }
    cout<<ans;
    return 0;
}
