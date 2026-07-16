#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define FOD(i,a,b) for(ll i=a;i<b;++i)
#define io(name) if(fopen(name".INP","r")){ freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define all(v) v.begin(),v.end()
#define ms(a,v) memset(a,v,sizeof(a));

stringstream ss;
const int N = 1e6;
ll a[N + 2],n,h = 1e18,k, minx = 1e18, maxx,res;
void sub1()
{
    FOR(i,1,n) res += maxx - a[i];
    cout<<res;
}
void sub2()
{
    h = a[1];
    FOR(i,1,n){
        if(h < a[i]) h = maxx;
        res += h - a[i];
    }
    cout<<res;
}
void sub3()
{
    ll pos = 0;
    FOR(i,2,n) if(a[i] - a[i - 1] >= 2){
        pos = i;
        break;
    }
    ll ma = 0;
    FOR(i,1,pos - 1) ma = max(ma,a[i]);
    FOR(i,1,n){
        if(ma < a[i]) ma = maxx;
        res += ma - a[i];
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("cau2")
    cin>>n>>k;
    FOR(i,1,n){
        cin>>a[i];
        minx = min(minx,a[i]);
        maxx = max(maxx,a[i]);
    }
    if(k == 0) sub1();
    else if(k == -1) sub2();
    else sub3();
    return 0;
}