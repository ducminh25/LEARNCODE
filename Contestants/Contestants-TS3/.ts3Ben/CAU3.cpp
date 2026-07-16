#include <bits/stdc++.h>

using namespace std;
const int N=1e6;
int d[N+5];
void sang(){
    for(int i=1;i<=N;i++)
        d[i]=i;
    for(int i=2;i*i<=N;i++){
        if(d[i]==i){
            for(int j=i;j<=N;j+=i){
                if(d[j]==j)
                    d[j]=i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);
    sang();
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1),b(m+1);
    int ans=0;
    map<int,int> da;
    map<int,int> db;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=m;i++)
        cin >> b[i];
    for(int i=1;i<=n;i++)
        da[d[a[i]]]++;
    for(int j=1;j<=m;j++)
        db[d[b[j]]]++;
    for(pair<int,int> p:da){
        if(db[p.first]==0)
            ans+=p.second;
    }
    cout << ans;
    return 0;
}
