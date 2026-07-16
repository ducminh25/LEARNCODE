#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define io(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define FOR(i,a,b) for(ll i = a;i <= b;++i)
#define FOD(i,a,b) for(ll i = a;i < b;++i)
#define all(v) v.begin(),v.end()

const int N = 1e5;
ll n,a[N + 2],cong[N + 2],t,cnt,maxx,s,res;
vector<pair<ll,ll>> pos;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("dubao")
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n){
        if(a[i] < 0){
            t = i;
            cnt = 1;
            while(i < n && a[i + 1] < 0){
                i++;
                cnt++;
            }
            maxx = max(maxx,cnt);
            pos.push_back({t,cnt});
        }
    }
    for(auto &i : pos){
        ll r = i.first - 1,sz = i.second;
        ll l = max(1LL,r - 2 * sz + 1);
        if(i.second == maxx) l = max(1LL,r - 3 * sz + 1);
        cong[l]++;
        cong[r + 1]--;
    }
    FOR(i,1,n){
        s += cong[i];
        if(s > 0) res++;
        //cout<<s<<' ';
    }
    //for(auto &i : pos) cout<<i.first<<' '<<i.second<<'\n';
    cout<<res;
    return 0;
}

//15
//1 2 -1 2 3 4 5 6 1 4 8 3 -1 -2 1
//-> 8

//15
//1 2 -1 2 3 4 5 6 1 4 8 3 -1 -2 -1
//-> 11

