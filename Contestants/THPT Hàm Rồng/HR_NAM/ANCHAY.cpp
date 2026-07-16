#include <bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
 ll t,m,n,a,b,ans=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ANCHAY.inp","r",stdin);
    freopen("ANCHAY.out","w",stdout);
    cin>>n>>m;
    n--;
    if(m<1000000000)
    {
        m--;
        for(ll i=n;i<=n+m;i++)
            if(i%7==0||i%7==6)
                ans++;
        cout<<ans;
    }
        else
    {
        t=n+m;
        ans+=(t/7)*2;
        if(n==7)
            ans--;
        if(t%7==6)
            ans--;
            cout<<ans;
    }
}
