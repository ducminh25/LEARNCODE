#include <bits/stdc++.h>
#define ll long long
#define str string
#define pii pair<ll,ll>
#define N 1000000
using namespace std;
ll a[1000005],b[1000005],dd[1000005],ddb[1000005];
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
void ptnt(ll k)
{
    for (ll i=2; i*i<=k; i++)
    {
        if (k%i==0)
        {
            ddb[i]=1;
            while (k%i==0) k=k/i;
        }
    }
    if (k>1) ddb[k]=1;
}
bool ktnt(ll k)
{
    for (ll i=2; i*i<=k; i++)
    {
        if (k%i==0)
        {
            if (ddb[i]==1) return 0;
            while (k%i==0) k=k/i;
        }
    }
    if (k>1) if (ddb[k]==1) return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("CAU3.inp","r"))
    {
        freopen("CAU3.inp","r",stdin);
        freopen("CAU3.out","w",stdout);
    }
    sangnt();
    ll n,m;
    cin>>n>>m;
    ll nt1=0,nt2=0;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
        if (p[a[i]]==1) nt1=1;
    }
    for (ll i=1; i<=m; i++)
    {
        cin>>b[i];
        if (p[b[i]]==1) nt2=1;
    }
    if (n<=1000&&m<=1000)
    {
        ll kq=0;
        for (ll i=1; i<=n; i++)
        {
            ll ok=0;
            for (ll j=1; j<=m; j++)
            {
                if (__gcd(a[i],b[j])!=1)
                {
                    ok=1;
                    break;
                }
            }
            if (ok==0) kq++;
        }
        cout<<kq;
    }
    else if (nt1==0&&nt2==0)
    {
        ll kq=0;
        for (ll i=1; i<=m; i++) dd[b[i]]=1;
        for (ll i=1; i<=n; i++)
        {
            if (dd[a[i]]==0) kq++;
        }
        cout<<kq;
    }
    else
    {
        ll kq=0;
        for (ll i=1; i<=m; i++)
        {
            ptnt(b[i]);
        }
        for (ll i=1; i<=n; i++)
        {
            if (ddb[a[i]]!=1&&ktnt(a[i])) kq++;
        }
        cout<<kq;
    }
    return 0;
}

