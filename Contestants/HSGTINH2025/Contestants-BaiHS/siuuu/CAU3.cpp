#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define fi first
#define se second
using namespace std;
int n,m,a[N],b[N],dema[N],demb[N],p[N];
int smax=0,ans;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU3.inp","r",stdin);
    freopen("CAU3.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
  dema[a[i]]++;
}
for(int i=1;i<=m;i++)
{
    cin>>b[i];
    demb[b[i]]++;
}
for(int i=2;i<=N-5;i++)p[i]=1;
for(int i=2;i*i<=N-5;i++)
{
    if(p[i]==1)
    {
        bool kta=false,ktb=false;
        vector<int>v;
        for(int j=i;j<=N-5;j+=i)
        {
            if(dema[j]!=0)
            {
                kta=true;
                v.push_back(j);
            }
            if(demb[j]!=0)ktb=true;
        }
        if(kta==true&&ktb==true)
        {
            for(int x:v)
            {
                dema[x]=0;
            }
        }
    }
}
for(int i=1;i<=n;i++)
{
    if(dema[a[i]])ans++;
}
cout<<ans;
    return 0;
}
/*
DOC DE
TEN BAI
GIOI HAN DE BAI
KET QUA DAU RA
SINH TEST
THOI GIAN
*/
