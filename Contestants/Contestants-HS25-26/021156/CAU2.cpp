#include <bits/stdc++.h>
#define N int(1e6)
using namespace std;
int k;
int n;
int h[N+5],max1=0,smax[N+6];
long long t=0,f[N+5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);
    cin>>n>>k;
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        max1=max(max1,h[i]);
        f[i]=f[i-1]+h[i];
    }
    if(k==0)
    {
        t=0;
        for(int i=1;i<=n;i++)
        {
            t+=(max1-h[i]);
        }
        cout<<t;
        return 0;
    }
    if(k==-1)
    {
        t=0;
        for(int i=1;i<=n;i++)
        {
            if(h[1]<h[i])
                h[1]=max1;
            t+=(h[1]-h[i]);
        }
        cout<<t;
        return 0;
    }
    if(k==1)
    {
        t=0;
        int vt=n;
        smax[0]=0;
        for(int i=1;i<=n;i++)
        {
            t+=(max1-h[i]);
            if(max1==h[i])
                vt=min(vt,i);
            smax[i]=max(smax[i-1],h[i]);
        }
        long long min1=f[n];
        for(int i=1;i<vt;i++)
        {
            //cout<<(1LL*i*smax[i]-f[i])<<' '<<(1LL*(n-i)*max1-(f[n]-f[i]))<<' ';
            //cout<<(1LL*i*smax[i]-f[i])+(1LL*(n-i)*max1-(f[n]-f[i]))<<'\n';
            min1=min(min1,(1LL*i*smax[i]-f[i])+(1LL*(n-i)*max1-(f[n]-f[i])));
        }
        cout<<min1;
        return 0;
    }
    return 0;
}
