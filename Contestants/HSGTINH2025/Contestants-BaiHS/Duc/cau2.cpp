#include <bits/stdc++.h>
#define N 1000002
#define int long long
using namespace std;
int n,k,a[N],f[N];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("cau2.inp","r",stdin);
    freopen("cau2.out","w",stdout);
    cin>>n>>k;
    int maxso=LLONG_MIN;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxso=max(maxso,a[i]);
    }
    int tong=0;
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            tong+=(maxso-a[i]);
        }
        cout<<tong;
    }
    else if(k==-1)
    {
        int maxd=0;
        int dem=1;
        int docao=a[1],kt=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=a[1]&&kt==1)
            {
                tong+=a[1]-a[i];
            }
            else
            {
                tong+=maxso-a[i];
                kt=0;
            }
        }
        cout<<tong;
    }
    else if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            f[i]=f[i-1]+a[i];
        }
        int minso=LLONG_MAX;
        for(int i=1;i<=n;i++)
        {
            int sum=0,vt=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j]<=a[i]) sum+=a[i]-a[j];
                else
                {
                    vt=j;
                    break;
                }
            }
            int tong1=f[n]-f[vt-1];
            minso=min(minso,sum+(n-vt+1)*maxso-tong1);
        }
        cout<<minso;
    }
    return 0;
}
