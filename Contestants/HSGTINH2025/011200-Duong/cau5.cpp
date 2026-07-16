#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define FOD(i,a,b) for(ll i=a;i<b;++i)
#define io(name) if(fopen(name".INP","r")){ freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define all(v) v.begin(),v.end()
#define ms(a,v) memset(a,v,sizeof(a));

stringstream ss;
const ll N = 1e5, inf = 1e18;
ll n,k,a[N + 2],r[N + 2],l[N + 2],res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("cau5")
    cin>>n>>k;
    FOR(i,0,n + 1){
        r[i] = inf;
        l[i] = inf;
    }
    FOR(i,1,n){
        cin>>a[i];
        r[i] = min(r[i - 1],a[i]);
    }
    if(k == 1){
        cout<<*min_element(a + 1,a + n + 1);
        return 0;
    }
    
    for(ll i = n;i > 0;--i) l[i] = min(l[i + 1],a[i]);
    FOR(i,2,n) res = max(res,r[i - 1] + l[i]);
    cout<<res;
    return 0;
}