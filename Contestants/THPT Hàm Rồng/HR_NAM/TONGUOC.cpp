#include <bits/stdc++.h>
#define ll long long
#define str string
using namespace std;

ll uoc(ll n)
{
    ll t=0;
    for(ll i=1;i*i<=n;i++)
        if(n%i==0)
        {
            t+=i;
            if(n/i!=i)
                t+=n/i;
        }
        return t;
}
ll n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("TONGUOC.inp","r",stdin);
    freopen("TONGUOC.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin >> x;
        cout << uoc(x) << ' ';
    }
}
