#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
ll n, m, k, ans;
vector<ll> adj[1000009];
ll dd[1000009];
ll con[1000009];
void bfs(ll s, ll &dem){
    queue<ll> q;
    dem=1;
    dd[s]=1;
    q.push(s);
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(ll v : adj[u]){
            if(dd[v] == 1) continue;
            dd[v]=1;
            dem++;
            q.push(v);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen("FESTIVAL.inp","r")){
        freopen("FESTIVAL.inp","r",stdin);
        freopen("FESTIVAL.out","w",stdout);
    }
    cin>>n>>m>>k;
    for(ll i=1; i<=m; i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, ans);
    ans--;
    cout<<ans<<'\n';
    if(ans>=k){
        cout<<0;
        return 0;
    }
    ll sl=0;
    for(ll i=2; i<=n; i++){
        ll res=0;
        if(dd[i]==1) continue;
        bfs(i, res);
        con[++sl]=res;
    }
    sort(con+1, con+sl+1, greater<ll>());
    for(ll i=1; i<=sl; i++){
        ans+=con[i];
        if(ans>=k){
            cout<<i;
            break;
        }
    }
}
/*
8 7 7
1 2
1 3
2 3
2 4
3 5
4 6
7 8

8 7 4
1 2
1 3
2 3
2 4
3 5
4 6
7 8
*/







