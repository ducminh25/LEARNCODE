#include <bits/stdc++.h>
#define N int(1e6)
using namespace std;
int n,k;
int a[N+6];
long long t=0,f[N+6];
int maxr[N+6];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==0)
    {
        int max1=*max_element(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            t+=(max1-a[i]);
        }
        cout<<t;
    }
    else
        if(k==-1)
    {
        maxr[n]=a[n];
        for(int i=n-1;i>=1;i--)
            maxr[i]=max(maxr[i+1],a[i]);
        int max1=a[1];
        for(int i=1;i<=n;i++)
        {
            if(max1<a[i])
                max1=maxr[i];
            t+=(max1-a[i]);
        }
        cout<<t;
    }
    else
        if(k==1&&n<=10000)
    {
        int max1=*max_element(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            f[i]=f[i-1]+(max1-a[i]);
        }
        maxr[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            maxr[i]=max(maxr[i-1],a[i]);
        }
        maxr[0]=0;
        t=LLONG_MAX;
        for(int i=1;i<=n;i++)
        {
                long long t1=0;
                for(int j=i-1;j>=1;j--)
                    t1+=(maxr[i]-a[j]);
                t1+=(f[n]-f[i]);
                t=min(t,t1);
        }
        cout<<t;
    }
    return 0;
}
