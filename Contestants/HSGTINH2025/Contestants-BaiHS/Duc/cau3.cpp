#include <bits/stdc++.h>
#define N 1000006
using namespace std;
int n,a[N],b[N],m,p[N],check[N],dem=0;
void sangntd()
{
    for(int i=2; i*i<=N; i++)
        if(!p[i])
            for(int j=i*i; j<=N; j+=i)
            {
                if(!p[j]) p[j]=i;
            }
    for(int i=2; i<=N; i++)
    {
        if(!p[i]) p[i]=i;
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("cau3.inp","r",stdin);
    freopen("cau3.out","w",stdout);
    sangntd();
    int dem=0;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
        int x=b[i];
        check[b[i]]=1;
        check[p[b[i]]]=1;
        while(x>1)
        {
            check[x]=1;
            check[p[x]]=1;
            x/=p[x];
        }
    }
    for(int i=1; i<=n; i++)
    {
        int kt=1;
        if(a[i]==1) dem++;
        else
        {
            int x=a[i];
            if(!check[p[a[i]]])
            {
                while(x>1)
                {
                    if(check[x]==1||check[p[x]]==1)
                    {
                        kt=0;
                        break;
                    }
                    x/=p[x];
                }
            }
            else kt=0;
            if(kt==1) dem++;
        }
    }
    cout<<dem;
    return 0;
}
