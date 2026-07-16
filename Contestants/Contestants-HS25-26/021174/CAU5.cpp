#include <bits/stdc++.h>
#define ll long long
#define Name "CAU5"
#define N int(1e6)
using namespace std;

ll n,k;
ll a[N+2];

void sub1()
{
    if(k==1)
    {
        ll mina=LLONG_MAX;
        for(int i=1; i<=n; i++)
            mina=min(mina,a[i]);
        cout<<mina;
    }
    else
    {
        ll j=0,t=0;
        ll min1=a[1],mina=LLONG_MAX;
        bool ok=false;
        for(int i=2; i<=n; i++)
        {
            if(a[i]>=min1)
                continue;
            else
            {
                t+=min1;
                j=i;
                ok=true;
                break;
            }
        }
        //cout<<t<<' '<<j<<'\n';
        if(!ok)
        {
            t+=a[1];
            ll min2=a[n];
            for(int i=n; i>=2; i--)
            {
                if(min2>=a[i])
                {
                    t+=min2;
                    break;
                }
            }
        }
        else
        {
            for(int i=j; i<=n; i++)
                mina=min(mina,a[i]);
            t+=mina;
        }

        cout<<t;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen(Name".inp", "r"))
    {
        freopen(Name".inp", "r", stdin);
        freopen(Name".out", "w", stdout);
    }
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    if(k<=2)
        sub1();

    return 0;
}
