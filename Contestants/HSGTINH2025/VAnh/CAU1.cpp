#include <bits/stdc++.h>
#define ll long long
#define str string
#define pii pair<ll,ll>
#define N 1000000
using namespace std;
ll p[1000005];
void sangnt()
{
    p[0]=1;
    p[1]=1;
    for (ll i=2; i*i<=N; i++)
    {
        if (p[i]==0)
        {
            for (ll j=i*i; j<=N; j+=i) p[j]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("CAU1.inp","r"))
    {
        freopen("CAU1.inp","r",stdin);
        freopen("CAU1.out","w",stdout);
    }
    ll l,r;
    cin>>l>>r;
    sangnt();
    if (r<=500)
    {
        ll kq=0;
        for (ll i=l; i<r; i++)
        {
            for (ll j=i+1; j<=r; j++)
            {
                if (p[j*j-i*i]==0)
                {
                    kq++;
                }
            }
        }
        cout<<kq;
    }
    else
    {
        ll kq=0;
        for (ll i=2*l; i<=2*r; i++)
        {
            if (p[i]==0) kq++;
        }
        if (l==1) kq--;
        cout<<kq;
    }

    return 0;
}

