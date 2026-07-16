#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll l,r,ans,nt[10000005],res,x,y,d,t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#define Name "CAU1"
    if(fopen(Name".INP","r"))
    {
        freopen(Name".INP","r",stdin);
        freopen(Name".OUT","w",stdout);
    }
    cin>>l>>r;
    for (ll i=2; i<=1e7; i++)
    {
        nt[i]=1;
    }
    for (ll i=2; i*i<=1e7; i++)
    {
        if(nt[i]==1)
        {
            for (ll j=i*i; j<=1e7; j+=i)
            {
                nt[j]=0;
            }
        }
    }
    for (ll b=l; b<=r; b++)
    {
        for (ll a=l; a<b; a++)
        {
            if (nt[b*b-a*a]==1)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
