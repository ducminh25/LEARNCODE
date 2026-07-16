#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
ll n, a[1000009], ans, loai;
const ll inf=1e10;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen("DEMHANG.inp","r")){
        freopen("DEMHANG.inp","r",stdin);
        freopen("DEMHANG.out","w",stdout);
    }
    cin>>n;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
    }
    ll dem=0;
    sort(a+1, a+n+1);
    a[n+1]=inf;
    for(ll i=1; i<=n; i++){
        dem++;
        if(a[i] != a[i+1]){
            if(ans < dem){
                ans=dem;
                loai=a[i];
            }
            dem=0;
        }
    }
    cout<<loai<<' '<<ans;
    return 0;
}
/*
11
1
2
2
3
2
4
5
2
6
7
6
*/




