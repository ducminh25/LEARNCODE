#include <bits/stdc++.h>
using namespace std;
vector<long long>ad[1000005];
long long d[1000005],a[1000005];
void dfs(long long u,long long x)
{
    d[u]=x;
    for(auto p: ad[u])
    {
        if(d[p]==0)
        {
            dfs(p,x);
        }
    }
}
int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      freopen("FESTIVAL.inp","r",stdin);
      freopen("FESTIVAL.out","w",stdout);
long long n,m,dem,k,i,j,u,v,q=0,kq=0;
cin>>n>>m>>k;
for(i=1;i<=m;i++)
{
    cin>>u>>v;
    ad[u].push_back(v);
    ad[v].push_back(u);
}
dfs(1,1);
for(i=1;i<=n;i++)
{
    if(d[i]==0)
    {
        dfs(i,i);
    }
}
dem=0;
for(i=1;i<=n;i++)
{
    if(d[i]!=1)
    {
         a[d[i]]++;
    }
    else
    {
        dem++;
    }
}
sort(a+1,a+n+1);
cout<<dem-1<<'\n';
k=k-dem;
while(k>0)
{
    kq++;
    k=k-a[n];
n--;
}
cout<<kq;
}


