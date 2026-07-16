#include <bits/stdc++.h>
#define int long long
#define N 100005
#define fi first
#define se second
using namespace std;
int n,k,a[N],ans,pre[N],suf[N];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU5.inp","r",stdin);
    freopen("CAU5.out","w",stdout);
cin>>n>>k;
if(k<=2)
{
        pre[0]=1e9;
        suf[n+1]=1e9;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            pre[i]=min(pre[i-1],a[i]);
        }
        for(int i=n; i>=1; i--)
        {
            suf[i]=min(suf[i+1],a[i]);
        }
        for(int i=1;i<n;i++)
        {
            ans=max(ans,pre[i]+suf[i+1]);
        }
        if(k==1)
        {
            cout<<pre[n];
            return 0;
        }
        cout<<ans;
}

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
