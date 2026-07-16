#include <bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
ll a[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("DEMHANG.inp","r"))
    {
        freopen("DEMHANG.inp","r",stdin);
        freopen("DEMHANG.out","w",stdout);
    }
    ll n;
    cin>>n;
    for (ll i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll dem=1,kq=0,d=a[1],ma;
    a[n+1]=LLONG_MAX;
    for (ll i=2; i<=n+1; i++)
    {
        if (a[i]==d) dem++;
        else
        {
            if (dem>kq)
            {
                kq=dem;
                ma=d;
            }
            d=a[i];
            dem=1;
        }
    }
    cout<<ma<<" "<<kq;

    return 0;
}

