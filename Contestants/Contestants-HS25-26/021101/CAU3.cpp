#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,m,a[10000005],b[10000005],d,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #define Name "CAU3"
    if(fopen(Name".INP","r"))
    {
        freopen(Name".INP","r",stdin);
        freopen(Name".OUT","w",stdout);
    }
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (ll i=1;i<=m;i++)
    {
        cin>>b[i];
        if (i==1)
        {
            d=b[i];
        }
        else
        {
            d=__gcd(d,b[i]);
        }
    }
    for (ll i=1;i<=n;i++)
    {
        x=__gcd(a[i],d);
        if (x==1)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
