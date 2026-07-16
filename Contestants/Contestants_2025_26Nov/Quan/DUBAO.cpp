#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
pii ngay[1000009];
ll d=0;
ll a[1000009], l=0, r=0, ans, maxl, n;
ll dd[1000009], dma[1000009];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen("DUBAO.inp","r")){
        freopen("DUBAO.inp","r",stdin);
        freopen("DUBAO.out","w",stdout);
    }
    cin>>n;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
    }
    a[0] = 1000;
    a[n+1] = 1000;
    ll dem=0;
    for(ll i=1; i<=n; i++){
        if(a[i] < 0){
            dem++;
            if(a[i-1] >= 0)
                l=i;
            if(a[i+1] >= 0){
                r=i-l+1;
                ++d;
                ngay[d].first=dem;
                ngay[d].second=l;
                maxl=max(maxl, dem);
                dem=0;

            }
        }
    }
    ll jj=0;
    sort(a+1, a+n+1);
    for(ll i=1; i<=d; i++){
        if(ngay[i].first == maxl){
            jj=i;
            break;
        }
        ll j=ngay[i].second;
        ll x=2*ngay[i].first;
        while(j >= 1 && x!=0){
            x--;
            j--;
            if(j<1) break;
            if(dd[j]==0){
                ans++;
            }
            dd[j]=1;
        }
    }
    ll maxl=0;
    for(ll i=jj; i<=d; i++){
        ll ck=0;
        memset(dma, 0, sizeof(dma));
        ll j=ngay[i].second;
        ll x=3*ngay[i].first;
        while(j >= 1 && x!=0){
            x--;
            j--;
            if(j<1) break;
            if(dd[j]==0 && dma[j]==0){
                ck++;
            }
            dma[j]=1;

        }
        for(ll k=jj; k<=d; k++){
            if(i==j) continue;
            ll j=ngay[k].second;
            ll x=2*ngay[k].first;
            while(j >= 1 && x!=0){
                x--;
                j--;
                if(j<1) break;
                if(dd[j]==0 && dma[j]==0)
                    ck++;
                dma[j]=1;
            }
        }
        maxl=max(maxl, ck);
    }
    ans+=maxl;
    cout<<ans;
    return 0;
}
/*
8
1 -1 4 3 8 -2 3 -3

15
1 2 -1 2 3 4 5 6 1 4 8 3 -1 -2 1
*/





