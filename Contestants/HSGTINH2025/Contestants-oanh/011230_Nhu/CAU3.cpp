#include <bits/stdc++.h>
#define N 1000001
#define ll long long
using namespace std;
ll n,m,a[1000001],b[1000001],dem=0;
ll d1=0,d2=0,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(ll i=1;i<=n;i++){
            dem=0;
        for(ll j=1;j<=m;j++){
                x=__gcd(a[i],b[j]);
                if(x==1){
                    dem++;
        }
    }
         if(dem==m) d1++;
    }
    cout<<d1;
    return 0;
}
