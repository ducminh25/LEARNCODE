#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000006],t=0,ma,x,vt,mi=LLONG_MAX;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(k==0)
    {
        for(int i=1;i<=n;i++)
            t+=ma-a[i];
        cout<<t;
    }
    if(k==-1)
    {
        x=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=a[1]&&x==0)
                t+=a[1]-a[i];
            else if(a[i]>a[1]&&x==0)
            {
                x=1;
                t+=ma-a[i];
            }
            else if(x==1)
                t+=ma-a[i];
        }
        cout<<t;
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            long long sum=0;
            x=a[i];
            for(int j=1;j<=n;j++)
            {
                if(x<a[j])
                    x=ma;
                sum+=x-a[j];
            }
            mi=min(mi,sum);
        }
        cout<<mi;
    }
    return 0;
}
