#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define fi first
#define se second
using namespace std;
int l,r,p[N];
void sang()
{
    for(int i=2;i<=N-5;i++)p[i]=1;
    for(int i=2;i*i<=N-5;i++)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=N-5;j+=i)p[j]=0;
        }
    }
}
int ans=0;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU1.inp","r",stdin);
    freopen("CAU1.out","w",stdout);
sang();
cin>>l>>r;
for(int i=l+1;i<=r;i++)
{
    int x=i-1;
    if(p[i+x])
    {
       // cout<<i<<'\n';
        ans++;
    }
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
