#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define fi first
#define se second
using namespace std;
int n,k,a[N],smax,ans=1e18,f[N];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU2.inp","r",stdin);
    freopen("CAU2.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    f[i]=f[i-1]+a[i];
    smax=max(smax,a[i]);
}
if(k==0)
{
    int kq=0;
    for(int i=1;i<=n;i++)
    {
        kq=kq+(smax-a[i]);
    }
    cout<<kq;
}
else if(k==-1)
{
    for(int i=2;i<=n;i++)
    {
       int val1=a[1]*(i-1)-f[i-1];
       int val2=smax*(n-i+1)-(f[n]-f[i-1]);
      // cout<<val1<<" "<<val2<<'\n';
       ans=min(ans,val1+val2);
        if(a[i]>a[1])
        {
            break;
        }
    }
    cout<<ans;
}
else
{
    ans=smax*n-f[n];
    //cout<<ans<<'\n';
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
       int val1=maxx*(i-1)-f[i-1];
       int val2=smax*(n-i+1)-(f[n]-f[i-1]);
      // cout<<val1<<" "<<val2<<'\n';
       ans=min(ans,val1+val2);
       maxx=max(a[i],maxx);
    }
    cout<<ans;
}
    return 0;
}
/*
DOC DE
TEN BAI
GIOI HAN DE BAI
KET QUA DAU RA
SINH TEST
THOI GIAN
*/
