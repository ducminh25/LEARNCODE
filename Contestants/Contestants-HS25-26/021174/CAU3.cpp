#include <bits/stdc++.h>
#define ll long long
#define Name "CAU3"
#define N int(1e6)
using namespace std;

ll n,m,da=0,db=0;
ll a[N+2];
ll b[N+2];
ll p[N+2];

void sang()
{
    for(int i=2; i*i<=N; i++)
        p[i]=1;
    p[0]=p[1]=0;
    for(int i=2; i*i<=N; i++)
        if(p[i]==1)
            for(int j=i*i; j<=N; j+=i)
                p[j]=0;
}
bool ktra(ll a, ll b)
{
    ll x=__gcd(a,b);
    if(x==1)
        return true;
    return false;
}
void sub1()
{
    ll d=0;
    for(int i=1; i<=n; i++)
    {
        bool ok=true;
        for(int j=1; j<=m; j++)
        {
            if(!ktra(a[i],b[j]))
            {
                ok=false;
                break;
            }
        }
        if(ok)
            d++;
    }
    cout<<d;
}
void sub2()
{
    cout<<n;
}

void sub3()
{
    ll d=0;
    for(int i=1; i<=n; i++)
    {
        bool ok=true;
        for(int j=1; j<=m; j++)
        {
            if(!ktra(a[i],b[j]))
            {
                ok=false;
                break;
            }
        }
        if(ok)
            d++;
    }
    cout<<d;
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
    sang();
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(p[a[i]]==1)
            da++;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
        if(p[b[i]]==1)
            db++;
    }
    if(n<=1000&&m<=1000)
        sub1();
    else
    {
        if(da==n&&db==m)
            sub2();
        else
            sub3();
    }
    return 0;
}
