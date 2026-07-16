#include <bits/stdc++.h>
#define ll long long
#define str string
#define pii pair<ll,ll>
using namespace std;
ll dd[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("CAU4.inp","r"))
    {
        freopen("CAU4.inp","r",stdin);
        freopen("CAU4.out","w",stdout);
    }
    ll n,k;
    cin>>n>>k;
    str s;
    cin>>s;
    ll ok=0;
    for (ll i=0;i<n;i++){
        dd[s[i]]++;
        if (dd[s[i]]>=k) ok=1;
    }
    if (ok==0) cout<< -1;
    else {
        ll kq=1;
        for (ll i=0;i<n;i++){
            if (dd[s[i]]>=k){
                ll d=1;
                for (ll j=i+1;j<n;j++){
                    if (dd[s[j]]>=k) d++;
                    else break;
                }
                kq=max(kq,d);
            }
        }
        cout<<kq;
    }
    return 0;
}

