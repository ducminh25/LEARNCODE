#include <bits/stdc++.h>
#define ll long long
#define Name "CAU1"
#define N int(1e6)
using namespace std;

ll l,r;
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
void sub1()
{
    ll d=0;
    for(ll i=l; i<r; i++)
    {
        for(ll j=i+1; j<=r; j++)
        {
            if(p[j*j-i*i]==1)
                d++;
        }
    }
    cout<<d;
}
void sub2()
{
    ll t=0;
    for(ll i=l; i<r; i++)
    {
        if(p[(i+1)*(i+1)-i*i]==1)
            t++;
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
    cin>>l>>r;
    sang();
    if(r<=1000)
        sub1();
    else
        sub2();

    return 0;
}
