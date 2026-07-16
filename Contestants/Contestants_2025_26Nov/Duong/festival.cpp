#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define io(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define FOR(i,a,b) for(ll i = a;i <= b;++i)
#define FOD(i,a,b) for(ll i = a;i < b;++i)
#define all(v) v.begin(),v.end()

const int N = 1e3;
ll n,m,k,x,y,parent[N + 2],sz[N + 2],res;
ll find(ll x)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unite(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("festival")
    cin>>n>>m>>k;
    FOR(i,1,n){
        parent[i] = i;
        sz[i] = 1;
    }
    FOR(i,1,m){
        cin>>x>>y;
        unite(x,y);
    }
    cout<<sz[1] - 1<<'\n';
    if(sz[1] - 1 >= k){
        cout<<0;
        return 0;
    }
    FOR(i,2,n) if(parent[i] == i) res++;
    cout<<res;
    return 0;
}

//8 7 7
//1 2
//1 3
//2 3
//2 4
//3 5
//4 6
//7 8



