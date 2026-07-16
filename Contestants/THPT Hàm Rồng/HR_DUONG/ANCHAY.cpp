#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define FOD(i,a,b) for(ll i=a;i<b;++i)
#define io(name) if(fopen(name".INP","r")){ freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ms(a,v) memset(a,v,sizeof(a));

stringstream ss;
ll n,m,res;
void sub1(){
    m--;
    if(n % 7 == 0){
        if(m > 0) res += 2;
        else res++;
    }
    if(n % 8 == 0) res++;
    while(m--){
        n++;
        if(n % 7 ==0){
            res++;
            if(m > 0) res++;
            //if(m > 0) cout<<n<<' '<<n + 1<<'\n';
            //else cout<<n<<'\n';
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("ANCHAY")
    cin>>n>>m;
    if(m <= 1e8){
        sub1();
        return 0;
    }
    if(m == 1){
        if(n == 7 || n == 8) return cout<<1,0;
        else return cout<<0,0;
    }
    while(n % 7 != 0 && n != 8){
        n++;
        m--;
    }
    
    bool check = (7 * (m / 7) > m);
    res = 2 * (m / 7) + check;
    cout<<res;
    return 0;
}