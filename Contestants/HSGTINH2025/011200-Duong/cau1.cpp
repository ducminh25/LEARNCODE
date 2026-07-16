#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define FOD(i,a,b) for(ll i=a;i<b;++i)
#define io(name) if(fopen(name".INP","r")){ freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define all(v) v.begin(),v.end()
#define ms(a,v) memset(a,v,sizeof(a));

stringstream ss;
ll l,r,res;
bool is_prime[1000002];

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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("cau1")
    sieve(1000000);
    cin>>l>>r;
    FOD(i,l,r){
        if(is_prime[2 * i + 1]) res++;
    }
    cout<<res;
    return 0;
}