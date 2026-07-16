#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define io(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define FOR(i,a,b) for(ll i = a;i <= b;++i)
#define FOD(i,a,b) for(ll i = a;i < b;++i)
#define all(v) v.begin(),v.end()

const int N = 1e6;
ll f[N + 2],cnt,n,a,maxx;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("demhang")
    cin>>n;
    FOR(i,1,n){
        cin>>a;
        f[a]++;
        cnt = max(cnt,f[a]);
    }
    FOR(i,1,N){
        if(f[i] == cnt){
            cout<<i<<' '<<cnt;
            return 0;
        }
    }
    return 0;
}



