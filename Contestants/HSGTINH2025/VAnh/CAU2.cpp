#include <bits/stdc++.h>
#define ll long long
#define str string
#define pii pair<ll,ll>
using namespace std;
ll a[1000005];
ll n,k,cao=1e18,ma=0;
bool check(ll m){
    ll tong=0,ok1=0;
    for (ll i=1;i<=n;i++){
            if (ok1==0&&m>=a[i]){
                tong+=m-a[i];
            }
            else if (ok1==0&&m<a[i]){
                tong+=ma-a[i];
                ok1=1;
            }
            else if (ok1==1){
                tong+=ma-a[i];
            }
        }
        if (tong<cao) {
                cao=tong;
                return true;}
        else return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("CAU2.inp","r"))
    {
        freopen("CAU2.inp","r",stdin);
        freopen("CAU2.out","w",stdout);
    }
    cin>>n>>k;
    for (ll i=1;i<=n;i++) {cin>>a[i];
    ma=max(ma,a[i]);
    }
    if (k==0){
        ll kq=0;
        for (ll i=1;i<=n;i++) kq+=ma-a[i];
        cout<<kq;
    }
    else if (k==-1){
        ll kq=0,ok=0;
        for (ll i=2;i<=n;i++){
            if (ok==0&&a[1]>=a[i]){
                kq+=a[1]-a[i];
            }
            else if (ok==0&&a[1]<a[i]){
                kq+=ma-a[i];
                ok=1;
            }
            else if (ok==1){
                kq+=ma-a[i];
            }
        }
        cout<<kq;
    }
    else if (k==1){
            ll kq=1e18;
        ll l=a[1],r=ma;
        while (l<=r){
            ll mid=(l+r)/2;
            if (check(mid)){
                kq=min(kq,cao);
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<kq;
    }
    return 0;
}

