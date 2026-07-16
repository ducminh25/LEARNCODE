#include <bits/stdc++.h>
#define ll long long
#define str string
#define pii pair<ll,ll>
using namespace std;
ll a[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("CAU5.inp","r"))
    {
        freopen("CAU5.inp","r",stdin);
        freopen("CAU5.out","w",stdout);
    }
ll n,k;
cin>>n>>k;
ll c=1e18;
for (ll i=1;i<=n;i++) {
    cin>>a[i];
    c=min(c,a[i]);
}
cout<<c;
    return 0;
}

