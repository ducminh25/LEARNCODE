#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans,dp1[1000005],dp2[1000005],a[1000005],d,f[1000][1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #define Name "CAU5"
    if(fopen(Name".INP","r"))
    {
        freopen(Name".INP","r",stdin);
        freopen(Name".OUT","w",stdout);
    }
    cin>>n>>k;
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (k<=2)
    {
        if (k==1)
        {
            ans=1e17;
            for (ll i=1;i<=n;i++)
            {
                ans=min(ans,a[i]);
            }
            cout<<ans;
            return 0;
        }
        if (k==2)
        {
            dp1[0]=1e17;
            dp2[n+1]=1e17;
            for (ll i=1;i<=n;i++)
            {
                dp1[i]=min(dp1[i-1],a[i]);
            }
            for (ll i=n;i>0;i--)
            {
                dp2[i]=min(dp2[i+1],a[i]);
            }
            for (ll i=1;i<n;i++)
            {
                ans=max(ans,dp1[i]+dp2[i+1]);
            }
            cout<<ans;
            return 0;
        }
    }
  //  if (n<=500)
   // {
        for (ll i=1;i<=n;i++)
        {
            d=a[i];
            for (ll j=i-1;j>=0;j--)
            {
                if (j>0)
                {
                    for (ll x=1;x<=j;x++)
                    {
                        f[i][x+1]=max(f[i][x+1],f[j][x]+d);
                    }
                }
                if (j==0)
                {
                    f[i][1]=max(f[i][1],d);
                }
                d=min(d,a[j]);
            }
        }
        cout<<f[n][k];
        return 0;
   // }
    return 0;
}
