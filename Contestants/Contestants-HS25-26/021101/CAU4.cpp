#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=1e9+7;
ll ans,res,n,k,dp[10000005],l,r,m,pw[10000005],q;
string s;
map<ll,ll>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #define Name "CAU4"
    if(fopen(Name".INP","r"))
    {
        freopen(Name".INP","r",stdin);
        freopen(Name".OUT","w",stdout);
    }
    cin>>n>>k>>s;
    pw[0]=1;
    for (ll i=1;i<=1e6;i++)
    {
        pw[i]=(pw[i-1]*311)%M;
    }
    s='0'+s;
    for (ll i=1;i<=n;i++)
    {
        dp[i]=((dp[i-1]*311)%M + s[i])%M;
    }
    l=1;r=n;
    ans=-1;
    while (l<=r)
    {
        m=(l+r)/2;
        q=0;
        mp.clear();
        for (ll i=m;i<=n;i++)
        {
            res=(dp[i]-(dp[i-m]*pw[m])%M+M)%M;
            mp[res]++;
            if (mp[res]==k)
            {
                q=1;
            }
        }
        if (q==1)
        {
            ans=m;
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    cout<<ans;
    return 0;
}
