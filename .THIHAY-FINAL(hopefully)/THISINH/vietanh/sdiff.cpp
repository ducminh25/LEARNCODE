#include <bits/stdc++.h>
#define ll long long
#define str string
#define pii pair<ll,ll>
using namespace std;
ll a[5000005];
multiset<ll>mtst;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen("sdiff.inp","r"))
    {
        freopen("sdiff.inp","r",stdin);
        freopen("sdiff.out","w",stdout);
    }
    ll n;
    cin>>n;
    ll p,q,m;
    cin>>p>>q>>m;
    ll t;
    cin>>t;
    ll kq=0;
    for (ll i=1; i<=n; i++)
    {
        a[i]=(p*i+q)%m;
    }

    if (n<=2000)
    {

        for (ll i=1; i<=n; i++)
        {
            ll mi=LLONG_MAX,ma=0;
            for (ll j=i; j<=n; j++)
            {
                mi=min(mi,a[j]);
                ma=max(ma,a[j]);
                if (ma-mi<=t) kq++;
            }
        }
        cout<<kq;
    }
    else
    {
        ll l=1;
        for (ll i=1; i<=n; i++)
        {
            mtst.insert(a[i]);
            while(*mtst.rbegin()-*mtst.begin()>t)
            {
                auto k=mtst.find(a[l]);
                mtst.erase(k);
                l++;
            }
            kq+=i-l+1;
        }
        cout<<kq;
    }




    return 0;
}

