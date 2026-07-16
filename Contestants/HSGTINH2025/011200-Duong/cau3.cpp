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
ll a[N + 2],b[N + 2],n,m,res;
bool is_prime[N + 2], s2 = true,seen[N + 2];

void sieve(int n) {
    for (int i = 0; i <= n; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
void sub1()
{
    FOR(i,1,n){
        bool ok = true;
        FOR(j,1,m){
            if(__gcd(a[i],b[j]) != 1){
                ok = false;
                break;
            }
        }
        if(ok) res++;
    }
   cout<<res;
}
void sub2()
{
    FOR(i,1,m) seen[b[i]] = 1;
    FOR(i,1,n) if(!seen[a[i]]) res++;
    cout<<res;
}
void sub3()
{
    ll g = 0;
    FOR(i,1,m) seen[b[i]] = 1;
    FOR(i,1,m) g = __gcd(g,b[i] - b[1]);
    FOR(i,1,n) if(!seen[a[i]] && __gcd(g,a[i]) == 1) res++;
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("cau3")
    cin>>n>>m;
    sieve(N);
    FOR(i,1,n){
        cin>>a[i];
        if(!is_prime[a[i]]) s2 = false;
    }
    FOR(i,1,m){
        cin>>b[i];
        if(!is_prime[b[i]]) s2 = false;
    }
    if(n <= 1000) sub1();
    else if(s2) sub2();
    else sub3();
    return 0;
}