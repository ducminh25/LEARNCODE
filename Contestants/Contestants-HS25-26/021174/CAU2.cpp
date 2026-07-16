#include <bits/stdc++.h>
#define ll long long
#define Name "CAU2"
#define N int(2e6)
using namespace std;

ll n,k,maxa=0;
ll a[N+2];

void sub1()
{
    ll t=0;
    for(int i=1; i<=n; i++)
        t+=maxa-a[i];
    cout<<t;
}
void sub2()
{
    ll t=0;
    ll res=a[1];
    for(int i=2; i<=n; i++)
    {
        if(res>=a[i])
            t+=res-a[i];
        else
        {
            res=maxa;
            t+=res-a[i];
        }
    }
    cout<<t;
}
void sub3()
{
    ll tb=0,t=0;
    for(int i=1; i<=n; i++)
    {
        tb+=a[i];
    }
    tb=tb/n;
    for(int i=1; i<=n; i++)
    {
        if(tb>=a[i])
            t+=tb-a[i];
        else
        {
            tb=maxa;
            t+=tb-a[i];
        }
    }
    cout<<t;
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
        maxa=max(maxa,a[i]);
    }
    if(k==0)
        sub1();
    else
        if(k==-1)
            sub2();
        else
            if(k==1)
                sub3();
    return 0;
}
