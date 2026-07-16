#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[1000005],ans,d,maxa,res,dpa[1000005],dpb[1000005],pa[1000005],pb[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #define Name "CAU2"
    if(fopen(Name".INP","r"))
    {
        freopen(Name".INP","r",stdin);
        freopen(Name".OUT","w",stdout);
    }
    cin>>n>>k;
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    if (k==0)
    {
        d=maxa;
        for (ll i=1;i<=n;i++)
        {
            ans+=(d-a[i]);
        }
        cout<<ans;
        return 0;
    }
    if (k==-1)
    {
        d=a[1];
        for (ll i=1;i<=n;i++)
        {
            if (d<a[i])
            {
                d=maxa;
            }
            if (d>=a[i])
            {
                ans+=(d-a[i]);
            }
        }
        cout<<ans;
        return 0;
    }
    if (k==1)
    {
        for (ll i=1;i<=n;i++)
        {
            dpa[i]=max(dpa[i-1],a[i]);
            pa[i]=pa[i-1]+a[i];
        }
        for (ll i=n;i>0;i--)
        {
            dpb[i]=max(dpb[i+1],a[i]);
            pb[i]=pb[i+1]+a[i];
        }
        ans=1e17;
        for (ll i=1;i<=n;i++)
        {
            res=((dpa[i]*i)-pa[i])+((dpb[i+1]*(n-i))-pb[i+1]);
            ans=min(ans,res);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
